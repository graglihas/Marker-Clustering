#ifndef GISVIEW_H
#define GISVIEW_H

#include <QWidget>
#include "CGKernel/CGMapView/cgmapview.h"
#include "CGDigitize/cgdigitizer.h"
#include "CGDigitize/cggeometryedit.h"
#include "CGGeoEvents/cgrtmapview.h"
#include "CGGeoComputation/cggeocomputation.h"
#include <Searches/S52ViewAPI.h>
#include "CGGeoEvents/cgsensorpipe.h"
#include <Track/trackrepository.h>
#include <Track/tracklayerdef.h>
#include "Gis/MapLoading/encloader.h"
#include <Polygon/polygonlayerdef.h>
#include <Track/trackclusterlayerdefinition.h>


class polygonlayerdef;

namespace Ui {
class GisView;
}

class GisView : public QWidget
{
    Q_OBJECT

public:
    ~GisView();

    CGRTMapView *getMapView();
    CGVectorPipe *getOverlayPipe();
    CGSensorPipe *getTrackPipe();

    void GISGetXY (const double dLong_, const double dLat_,int& iX_, int& iY_, unsigned char bProj);
    void GISGetLatLong (const short sX_, const short sY_, double& dLong_, double& dLat_, unsigned char bProj);
    void GISGetLatLong (const double dOrgLong_, const double dOrgLat_,const double dRange_, const double dBrg_,double& dLong_, double& dLat_, unsigned char ucMethod );
    void GetCorrectXY (double dX1, double dY1, double dX2, double dY2,int& iX1, int& iY1, int& iX2, int& iY2);
    void DrawArrows (int iX1, int iY1, int iX2, int iY2, QPainter* pPntr);
    void GISGetRngBrg(double dLong1_, double dLat1_, double dLong2_, double dLat2_, double &dRange_, double &dBrg_, unsigned char ucMethod_);
    void GISGetLatLong (double dLat, double dLong, QString &ocLat, QString &ocLong);
    QPointF GetClickedPoint();
   int getLatLongS (char* pchLat_, char* pchLong_, double &dLat_, double &dLong_);
   void getLatLong(QString ocLat_, QString ocLong_,double &dLat_, double &dLong_);
  static GisView * GetInstance();
  static GisView * GetInstance(QWidget *parent);
  static GisView * gisview;
  ENCLoader *m_encLoader ;
  TrackLayerDef * tracklayer;
  polygonlayerdef * polygon_layer;
  CGPointer <CGDataPipe> pipe;
  trackClusterLayerDefinition * track_cluster_layer;


public slots:
    void mouseWheelHandler(QWheelEvent *event);

    void mouseDownEventHandler(QMouseEvent *event);

    void mouseMoveEventHandler(QMouseEvent *event);

    void mouseReleaseEventHandler(QMouseEvent *event);
signals:
   void emitClickedPoint(QPointF);

private:
   explicit GisView(QWidget *parent = 0);

    Ui::GisView *ui;
    void openMap(QString mapName);
    CGConnection *createConnection(QString fileName);
    QPoint m_StartPoint;
    CGPointer<CGDataPipe> openPipe(CGConnection *activeConn);
    void resetOperations();

    CGVectorPipe* overlayPipe;
    CGRTMapView* mapView;
    QPointF clickedPoint;
    /////////// Track Data Pipe /////////////////////
    CGSensorPipe* trackpipe;


   // double Clickedlon ,Clickedlat ;

    inline void toWindowCoordinate(double lon,double lat,QPoint &point)
    {
        double z=0;
         CGCoordinateSystemMgr csMgr = CGCoordinateSystemMgr(CGProjection::ID_Geographic,  CGDatum::Type_WGS84 );


        if(mapView->coordinateSystem().getProjectionID()!=CGProjection::ID_Geographic)
            csMgr.transform(lon,lat,z,mapView->coordinateSystem() );
        mapView->worldToWindow(lon,lat,point);


    }
    void toWorldCoordinate(QPoint pointwin,QPointF &pointworld)
    {
        CGCoordinateSystemMgr csMgr = CGCoordinateSystemMgr(CGProjection::ID_Geographic,  CGDatum::Type_WGS84 );
        mapView->windowToWorld(pointwin,pointworld);
        double z=0;
        double x=pointworld.x();
        double y=pointworld.y();
        if(mapView->coordinateSystem().getProjectionID()!=CGProjection::ID_Geographic )
        {
            mapView->coordinateSystem().transform(x,y,z,csMgr);
            pointworld.setX(x);
            pointworld.setY(y);
        }

    }
    bool CalcDrawPoints (double dOrgX, double dAreaWidh, double dLong1, double dLong2, double& dGLong1, double& dGLong2)
    {

      bool bStatus = true;
      if (dOrgX > 0.0) {

        if (dLong1 < 0.0 && dLong2 > 0.0 && dLong2 < 179.99999)
          { dGLong1 += dAreaWidh; }
        else if (dLong1 > 0.0 && dLong2 < 0.0 && dLong1 < 179.99999)
          { dGLong2 += dAreaWidh; }
        else if (dLong1 > 0.0 && dLong2 > 0.0 && dLong1 > 179.99999 && dLong2 < 179.99999)
          { dGLong1 += dAreaWidh; }
        else if (dLong1 > 0.0 && dLong2 > 0.0 && dLong1 < 179.99999 && dLong2 > 179.99999)
          { dGLong2 += dAreaWidh; }
        else if (dLong1 > 0.0 && dLong2 > 0.0 && dLong1 > 179.99999 && dLong2 > 179.99999)
          { dGLong1 += dAreaWidh; dGLong2 += dAreaWidh; }
        else if (dLong1 < 0.0 && dLong2 < 0.0 && dLong1 > -179.99999 && dLong2 < -179.99999)
          { dGLong1 += dAreaWidh; }
        else if (dLong1 < 0.0 && dLong2 < 0.0 && dLong1 < -179.99999 && dLong2 > -179.99999)
          { dGLong2 += dAreaWidh; }
        else if (dLong1 < 0.0 && dLong2 < 0.0 && dLong1 > -179.99999 && dLong2 > -179.99999)
          { dGLong1 += dAreaWidh; dGLong2 += dAreaWidh; }
        else
          { bStatus = false; }
      }
      else
      {

        if (dLong1 < 0.0 && dLong2 > 0.0 && dLong2 < 179.99999)
          { dGLong2 -= dAreaWidh; }
        else if (dLong1 > 0.0 && dLong2 < 0.0 && dLong1 < 179.99999)
          { dGLong1 -= dAreaWidh; }
        else if (dLong1 > 0.0 && dLong2 > 0.0 && dLong1 > 179.99999 && dLong2 < 179.99999)
          { dGLong2 -= dAreaWidh; }
        else if (dLong1 > 0.0 && dLong2 > 0.0 && dLong1 < 179.99999 && dLong2 > 179.99999)
          { dGLong1 -= dAreaWidh; }
        else if (dLong1 > 0.0 && dLong2 > 0.0 && dLong1 < 179.99999 && dLong2 < 179.99999)
          { dGLong1 -= dAreaWidh; dGLong2 -= dAreaWidh;}
        else if (dLong1 < 0.0 && dLong2 < 0.0 && dLong1 < -179.99999 && dLong2 < -179.99999)
          { dGLong1 -= dAreaWidh; dGLong2 -= dAreaWidh; }
        else if (dLong1 < 0.0 && dLong2 < 0.0 && dLong1 > -179.99999 && dLong2 < -179.99999)
          { dGLong2 -= dAreaWidh; }
        else if (dLong1 < 0.0 && dLong2 < 0.0 && dLong1 < -179.99999 && dLong2 > -179.99999)
          { dGLong1 -= dAreaWidh; }
        else
          { bStatus = false; }
      }

      return bStatus;
    }

//protected:

//    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
};

#endif // GISVIEW_H
