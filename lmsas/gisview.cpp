#include "gisview.h"
#include "ui_gisview.h"
#include "CGMapView/cgmapview.h"
#include "CGDigitize/cgdigitizer.h"
#include "CGDigitize/cggeometryedit.h"
#include "CGGeoEvents/cgrtmapview.h"
#include "CGConnection/cgvectornativeconnection.h"
#include "CGConnection/cgrasternativeconnection.h"
#include "CGPipe/cgvectorpipe.h"
#include "CGPipe/cgstaticrasterpipe.h"
#include "CGPipe/cgdynamicrasterpipe.h"
#include "CGMapView/cgdatarepository.h"
#include "CGFileConnection/cgrasterfileconnection.h"
#include "CGFileConnection/cgvectorfileconnection.h"
#include "CGS52Renderer/cgs52mapview.h"
#include "CGProjection/cgprojectiondialog.h"
#include <CGProjection/cgprojection.h>
#include "CGConnection/cgvectornativeconnection.h"
#include "CGGeometry/cggeometryautomation.h"
#include "common/CommonFuncts.h"
#include "Searches/S52ViewAPI.h"
#include <Track/trackrepository.h>
#include "Gis/MapLoading/encloader.h"


GisView * GisView::gisview=NULL;

GisView::GisView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GisView)
{
    ui->setupUi(this);

       mapView = new CGRTMapView(this);
       mapView->setObjectName("map");
       //mapView->setBackgroundColor(Qt::darkYellow);
       mapView->setBackgroundColor(Qt::white);
       CGCoordinateSystemMgr csMerc( CGProjection::ID_Mercator_1SP, CGDatum::Type_WGS84);
       CGCoordinateSystemMgr csGeo( CGProjection::ID_Geographic, CGDatum::Type_WGS84);
       mapView->setCoordinateSystem(csMerc);
       //mapView->setCoordinateSystem(csGeo);
       QHBoxLayout *layout = new QHBoxLayout;
       layout->addWidget(mapView);
       this->setLayout(layout);

       //openMap("/home/himanshu/ImsasDesign/Gis/CAIRGIS_Training/Examples/Data/world.ivf");

       //openMap("/home/himanshu/ImsasDesign/Gis/CAIRGIS_Training/Examples/Data/43J11.tif");
       openMap("/home/trigun/gis/Examples/Data/world.ivf");

      // m_encLoader = new ENCLoader( "/home/himanshu/ImsasDesign/Imsas/Gis/maps/ENC", "/home/himanshu/ImsasDesign/Imsas/Gis/maps/charts.txt");
      // m_encLoader->attachMapView(mapView);


       overlayPipe = new CGVectorPipe("OverlayPipe",csGeo);
       overlayPipe->setUpdatable(true);

       polygon_layer = new polygonlayerdef();
       polygon_layer->SetPolygonLayer(getOverlayPipe());


        track_cluster_layer = new trackClusterLayerDefinition();
        track_cluster_layer->SettrackClusterLayer(getOverlayPipe());

        mapView->featureRepository()->addPipe(overlayPipe);

       ///////// Add sensor layer here ///////////////////////////
       trackpipe=new CGSensorPipe("TrackPipe",csGeo);
       tracklayer = new  TrackLayerDef();
       tracklayer->prepareTrackLayer(trackpipe);
       mapView->featureRepository()->addPipe(trackpipe);


       connect (mapView, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheelHandler(QWheelEvent*)));

       connect (mapView, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mouseDownEventHandler(QMouseEvent*)));

       connect (mapView, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseReleaseEventHandler(QMouseEvent*)));

       connect (mapView, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveEventHandler(QMouseEvent*)));

}

GisView::~GisView()
{
    delete ui;
}

void GisView::openMap(QString mapName)
{
    QFile file(mapName);

    if(!file.exists()) return;

    //this->statusBar()->showMessage("Opening maps...Please wait....");

    CGConnection *activeConn = NULL;

   // CGPointer <CGDataPipe> pipe;

    activeConn = createConnection( mapName );

    if(activeConn )
        pipe = openPipe( activeConn );

    if (pipe)
        mapView->featureRepository()->addPipe(pipe);

    //mapView->devicePixelRatio();

 //CGLineStyle *borderStyle=new CGLineStyle(CGColor(255,255,255));

 //CGAreaStyle style_Poly(CGColor(255,0,0),borderStyle);
    CGAreaStyle style_Poly(CGColor(189,183,107), CGAreaStyle::Fill_SolidPattern);

 int n= mapView->legend()->count();
//     qDebug() <<"n=" <<n;
    for (int i = 0; i < n; i++)  mapView->legend()->item(i)->setStyle(&style_Poly);//name();


   // mapView.legend()->item(i)->setStyle(&style_Poly);

    mapView->fit();

    //this->statusBar()->clearMessage();
}

CGConnection* GisView :: createConnection (QString fileName )
{

    QString path , mapName, fileType ;

    QFileInfo fileInfo = QFileInfo(fileName);

   if (!fileInfo.exists()) return NULL;

    CGConnection* conn = NULL;

    path = fileInfo.absoluteDir().absolutePath();

    mapName = fileInfo.fileName();

    fileType =  fileInfo.suffix().toLower();


    if ( fileType == "irf"  )
    {


        conn = new CGRasterNativeConnection(   path + "/" + mapName,
                                               mapName,
                                               "IRF Conn",
                                               CGConnection::Mode_ReadOnly );


    }
    else if ( fileType == "ief")
    {

        conn = new CGRasterNativeConnection(   path + "/" + mapName,
                                               mapName,
                                               "IEF Conn",
                                               CGConnection::Mode_ReadOnly );

    }

    else if ( fileType == "tiff" ||
              fileType == "tif" ||
              fileType == "dem" ||
              fileType == "bmp" ||
              fileType == "jpg" ||
              fileType == "jpeg" ||
              fileType.startsWith("dt") ||
              fileType == "grd" ||
              fileType == "hgt" )
    {

        conn = new CGRasterFileConnection (path + "/" + mapName, mapName );

    }
    else if ( fileType == "ivf")
    {
        conn = new CGVectorNativeConnection(path + "/" + mapName, mapName, "IVF Conn");

    }
    else if ( fileType == "iof")
    {
        conn = new CGVectorNativeConnection(path + "/" + mapName, mapName, "IOF Conn",
                                            CGConnection::Mode_ReadWrite);

    }
    else if ( fileType == "dgn" || fileType == "dvd" || fileType == "dat" ||
              fileType == "shp" || fileType == "dxf" || fileType == "dwg" ||
              fileType == "kml" ||fileType == "gml" || fileType.startsWith("00") || fileType == "mdb" )
    {
        conn = new CGVectorFileConnection(path + "/" + mapName, mapName, "Vector File Conn");
    }

    return conn;


}

CGPointer <CGDataPipe>  GisView:: openPipe ( CGConnection* activeConn )
{
    CGPointer <CGDataPipe> pipe = NULL;

    QStringList layers;

    QString pipeName = activeConn->name();


    if ( activeConn->connType() == CGConnection::Type_Vector )
    {

        pipe =   new CGVectorPipe( pipeName,
                                   dynamic_cast<CGVectorConnection*>(activeConn),
                                   layers ,
                                   QStringList(),
                                   (activeConn->mode()==CGConnection::Mode_ReadWrite)) ;

    }
    else
    {

        CGRasterConnection *rConn = dynamic_cast<CGRasterConnection*>(activeConn);

        if ( rConn && rConn->getDBType() == CGRasterConnection::Type_RasterFile )

        {
            //pipe = new CGStaticRasterPipe(pipeName, rConn , activeConn->name());

            CGRasterFileConnection *fileConn = dynamic_cast<CGRasterFileConnection*>(rConn);

            if ( fileConn && fileConn->isCacheEnabled() )
            {
                CGDynamicRasterPipe *dPipe = new CGDynamicRasterPipe(pipeName, fileConn , activeConn->name());

                CGPointer<CGDiskCache> cache = fileConn->getDiskCache();
                dPipe->setDiskCache( cache );

                pipe = dPipe;
            }
            else
                pipe = new CGStaticRasterPipe(pipeName, rConn , activeConn->name());
        }

        else// IRF, IEF
        {
            pipe = new CGDynamicRasterPipe(pipeName, rConn , activeConn->name());
        }

        //pipe->attachc( activeConn );
    }

    return pipe;
}
void GisView::mouseWheelHandler(QWheelEvent* event)
{
    CGMapView *srcMapView = qobject_cast<CGMapView*>(this->sender());


    //qDebug()<<"sender name = "<<srcMapView->objectName();

    if ( srcMapView == NULL ) return;

    double delta = fabs(event->delta() / 1200.0);

    if ( delta > 0.9 ) delta = 0.9;

    if( event->delta() < 0 )
    {
        srcMapView->zoom(1.0 + delta);
    }
    else
    {
        srcMapView->zoom(1.0 - delta);
    }

    event->accept();
}

void GisView:: mouseDownEventHandler(QMouseEvent* event)
{
    CGMapView *srcMapView = qobject_cast<CGMapView*>(this->sender());
CGCoordinateSystemMgr viewCS = mapView->coordinateSystem();

    if(srcMapView == NULL ) return; //@@@@@

    if ( event->buttons() == Qt::LeftButton)
    {
        m_StartPoint = event->pos();
       // QPointF corr= srcMapView->windowToWorld(m_StartPoint,&viewCS);

       QPointF worldPoint;

               mapView->windowToWorld(m_StartPoint,worldPoint, &viewCS);

               clickedPoint.setX(worldPoint.x());
               clickedPoint.setY(worldPoint.y());

        emit emitClickedPoint(worldPoint);

       CGCoordinateSystemMgr TargetCS(CGProjection::ID_Geographic, CGDatum::Type_WGS84);

       viewCS.transform(worldPoint, TargetCS);
//        QMessageBox msgBox;
//        msgBox.setText("The point is clicked.x = "+QString::number(worldPoint.x()));
//        msgBox.exec();

    }

    //qDebug()<<"sender name = "<<srcMapView->objectName();
}

void GisView :: mouseMoveEventHandler(QMouseEvent* event)
{
    CGMapView *srcMapView = qobject_cast<CGMapView*>(this->sender());

    if(srcMapView == NULL ) return; //@@@@@

    if (  event->buttons() == Qt::LeftButton )
    {
        QPoint delta = event->pos() - m_StartPoint;

        if ( abs(delta.x()) > 2 || abs(delta.y()) > 2)
        {
            srcMapView->pan(delta.x(),delta.y());

            srcMapView->setCursor( Qt::OpenHandCursor );
        }

        srcMapView->update();

        m_StartPoint = event->pos();

    }
}

void GisView :: mouseReleaseEventHandler(QMouseEvent* event)
{
    CGMapView *srcMapView = qobject_cast<CGMapView*>(this->sender());

    if(srcMapView == NULL ) return; //@@@@@

    srcMapView->setCursor( Qt::ArrowCursor );

    if ( event->button() == Qt::LeftButton)
    {
        if ( event->modifiers() & Qt::ControlModifier )
        {
            QList < CGPointer <CGFeatureObject> > selectedObjects = srcMapView->selectedObjects();

            srcMapView->clearSelectedObjects();

            srcMapView->selectObjects( event->pos());

            QList < CGPointer <CGFeatureObject> > selectedObjectsNew = srcMapView->selectedObjects();

            for (int i = 0; i < selectedObjects.count(); i++ )
            {
                if ( selectedObjectsNew.contains( selectedObjects.at(i) ))
                    selectedObjectsNew.removeOne( selectedObjects.at(i) );

                else selectedObjectsNew.append( selectedObjects.at(i) );

            }

            srcMapView->clearSelectedObjects();

            for (int i = 0; i < selectedObjectsNew.count(); i++ )
            {
                srcMapView->addSelectedObjects( selectedObjectsNew[i] );
            }
        }
        else
        {
            srcMapView->clearSelectedObjects();

            srcMapView->selectObjects( event->pos());
        }

        srcMapView->refresh();
    }

    else if ( event->button() == Qt::RightButton)
    {
        resetOperations();

        srcMapView->clearSelectedObjects();

        srcMapView->update();

    }
}
void GisView::resetOperations()
{
    //DynGeomObj = NULL;

    mapView->hideRubberBand();

   // m_mapOperation = 0;

}

//void MapWidget::resizeEvent(QResizeEvent *event)
//{

//    mytab->setGeometry(mapView->geometry().topRight().x()-450,mapView->geometry().y(),450,900);
//   //lwidget->setGeometry(mapView->geometry().x(),mapView->geometry().y(),300,400);

//   QWidget::resizeEvent(event);
//}

CGRTMapView *GisView::getMapView()
{
    return mapView;
}
CGVectorPipe *GisView::getOverlayPipe()
{
   return overlayPipe;
}

 CGSensorPipe *GisView::getTrackPipe()
 {
     return trackpipe;
 }

GisView * GisView::GetInstance()
{
    return gisview;
}

GisView * GisView::GetInstance(QWidget *parent)
{
    if(gisview==NULL)
    {
        gisview=new GisView(parent);
    }
    return gisview;
}

void GisView::GISGetXY (const double dLong_, const double dLat_,int& iX_, int& iY_, unsigned char bProj=1)
{
    QPoint point;
    toWindowCoordinate(dLong_,dLat_,point);
    iX_ = point.x();
    iY_ = point.y();
}
void GisView::GISGetLatLong (const short sX_, const short sY_, double& dLong_, double& dLat_, unsigned char bProj=0)
{
  QPointF pointworld;
  QPoint pointwin(sX_,sY_);

  toWorldCoordinate(pointwin,pointworld);
   dLong_ = pointworld.x();
   dLat_ = pointworld.y();
}
void GisView::GISGetLatLong (const double dOrgLong_, const double dOrgLat_,const double dRange_, const double dBrg_,double& dLong_, double& dLat_, unsigned char ucMethod =1)
{
    double finalbearing;
    CGCoordinateSystemMgr csmgr = mapView->coordinateSystem();
    double rng = 1852.0*dRange_;
    CGGeoComputation::geodeticPointAndFinalBearing(dOrgLong_,dOrgLat_,dBrg_,rng,dLong_,dLat_,finalbearing,csmgr.getDatum());

}
void GisView::GetCorrectXY (double dX1, double dY1, double dX2, double dY2,int& iX1, int& iY1, int& iX2, int& iY2)
{

//    return;///////////// to check where used
//  bool bDateline = false;

//  double dWidth = 0.0;
//  double dDX1 = -179.99999, dDY1 = 0.0, dDX2 = 179.99999, dDY2 = 0.0;
//  double dPX1 = 0.0, dPY1 = 0.0, dPX2 = 0.0, dPY2 = 0.0;
//  double dXOrg = 0.0, dYOrg = 0.0;

//  GISProject (dDX1, dDY1);
//  GISProject (dDX2, dDY2);

//  dWidth = (dDX2 - dDX1);

//  GISGetPosition (dXOrg, dYOrg);

//  if (!bDateline && ((dX1 < 180.0 && dX2 > 180.0) || (dX1 > 180.0 && dX2 < 180.0) ||
//    (dX1 < -180.0 && dX2 > -180.0) || (dX1 > -180.0 && dX2 < -180.0)))
//  { bDateline = true; }


//  if (bDateline) {

//    dPX1 = dX1; dPX2 = dX2; dPY1 = dY1; dPY2 = dY2;
//    GISProject (dPX1, dPY1);
//    GISProject (dPX2, dPY2);

//    CalcDrawPoints (dXOrg, dWidth, dX1, dX2, dPX1, dPX2);

//    GISGetXY (dPX1, dPY1, iX1, iY1, 0);
//    GISGetXY (dPX2, dPY2, iX2, iY2, 0);
//  }
//  else
//  {

    GISGetXY (dX1, dY1, iX1, iY1);
    GISGetXY (dX2, dY2, iX2, iY2);
  //}
}


void GisView::DrawArrows (int iX1, int iY1, int iX2, int iY2, QPainter* pPntr)
{

  double dAng = 0.0;

  QPoint points[3] = {

    QPoint(0, -5),
    QPoint(9, 0),
    QPoint(0, 5)
  };

  int iMidX = (iX1 + iX2) / 2;
  int iMidY = (iY1 + iY2) / 2;

  pPntr->drawLine (iX1, iY1, iX2, iY2);
  pPntr->translate (iMidX, iMidY);

  dAng = SDBAngleYDown (iX2, iY2, iX1, iY1);
  dAng = (dAng * (180.0/3.14));

  pPntr->rotate (360.0 - dAng + 180.0);
  pPntr->drawPolyline (points, 3);
}

void GisView::GISGetRngBrg(double dLong1_, double dLat1_, double dLong2_, double dLat2_, double &dRange_, double &dBrg_, unsigned char ucMethod_ = 1)
{
    double finalbrg;
    CGGeoComputation::geodeticDistanceAndBearing(dLong1_,dLat1_,dLong2_,dLat2_,dRange_,dBrg_, finalbrg,CGDatum::Type_WGS84);
    if(ucMethod_== 0)
    {
        dRange_ = CGGeoComputation::rhumbLineDistance (dLong1_,dLat1_,dLong2_,dLat2_)/1852.0;
    }


}

void GisView::GISGetLatLong (double dLat, double dLong, QString &ocLat, QString &ocLong)
{

  double dLatDeg = 0.0, dLatMin = 0.0, dLatSec = 0.0;
  double dLongDeg = 0.0, dLongMin = 0.0, dLongSec = 0.0;

  dLatSec = modf ((modf (fabs (dLat), &dLatDeg) * 60), &dLatMin) * 60;
  ocLat.sprintf ("%02.0f-%02.0f-%05.2f%c", dLatDeg, dLatMin, dLatSec,
                 ((dLat < 0) ? 'S' : 'N'));

  dLongSec = modf ((modf (fabs (dLong), &dLongDeg) * 60), &dLongMin) * 60;
  ocLong.sprintf ("%03.0f-%02.0f-%05.2f%c", dLongDeg, dLongMin,
                            dLongSec, ((dLong < 0) ? 'W' : 'E'));
}

QPointF GisView::GetClickedPoint()
{
//    QPointF clickedPoint;
//    clickedPoint.setX(Clickedlat);
//    clickedPoint.setY(Clickedlon);
//    return(clickedPoint);
}

int GisView::getLatLongS (char* pchLat_, char* pchLong_, double &dLat_, double &dLong_)
{
    if(NULL == pchLat_ || NULL == pchLong_)
        return -1;
    /* get latitude value and split deg, min and sec without - */

    char ptr[13];
    memset(ptr, '\0', 13);
    memcpy((void *)ptr, pchLat_, 2);

    double dDigit = strtod(ptr, NULL);
    if(dDigit >= 90)
        return -1;

    dLat_ = dDigit;
    memset(ptr, '\0', 13);
    memcpy((void *)ptr, pchLat_ + 2, 2);

    dDigit = strtod(ptr, NULL);
    if(dDigit >= 60)
        return -1;
    dLat_ +=  dDigit / 60;

    /* convert it into double value */
    memset(ptr, '\0', 13);
    memcpy((void *)ptr, pchLat_ + 4, 5);

    dLat_ += strtod(ptr, NULL) / 3600;

    /* verify the direction */
    dLat_ *= (pchLat_[9] == 'N') ? 1 : -1;

    /* get longitude value and split deg, min and sec without - */
    memset(ptr, '\0', 13);
    memcpy((void *)ptr, pchLong_, 3);

    dDigit = strtod(ptr, NULL);
    if(dDigit >= 180)
        return -1;

    dLong_ = dDigit;

    memset(ptr, '\0', 13);
    memcpy((void *)ptr, pchLong_ + 3, 2);

    dDigit = strtod(ptr, NULL);
    if(dDigit >= 60)
        return -1;
    dLong_ += dDigit / 60;

    /* convert it into double value */
    memset(ptr, '\0', 13);
    memcpy((void *)ptr, pchLong_ + 5, 5);
    dLong_ += strtod(ptr, NULL) / 3600;

    /* verify the direction */
    dLong_ *= (pchLong_[10] == 'E') ? 1 : -1;

    return 0;
}

void GisView::getLatLong(QString ocLat_, QString ocLong_,double &dLat_, double &dLong_)
{


  /* get latitude value and split deg, min and sec with - */
  QStringList ocLatLst = ocLat_.split ("-");

  dLat_ = ocLatLst[0].toDouble ();
  dLat_ += ocLatLst[1].toDouble () / 60;

  /* convert it into double value */
  ocLat_ = ocLatLst[2]; ocLat_.chop (1);
  dLat_ += ocLat_.toDouble () / 3600;

  /* verify the direction */
  ocLat_ = (QString) ocLatLst[2].right (1);
  dLat_ *= (ocLat_.compare ("N") == 0) ? 1 : -1;

  /* get longitude value and split deg, min and sec with - */
  QStringList ocLongLst = ocLong_.split ("-");

  dLong_ = ocLongLst[0].toDouble ();
  dLong_ += ocLongLst[1].toDouble () / 60;

  /* convert it into double value */
  ocLong_ = ocLongLst[2]; ocLong_.chop (1);
  dLong_ += ocLong_.toDouble () / 3600;

  /* verify the direction */
  ocLong_ = ocLongLst[2].right (1);
  dLong_ *= (ocLong_.compare ("E") == 0) ? 1 : -1;
}



