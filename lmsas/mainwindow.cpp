#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QHBoxLayout"
#include  "Polygon/polygon_form.h"
#include "Searches/search_from.h"
#include <CGProjection/cgimportfrmwkt.h>
#include <dbconnectionform.h>
#include "Track/clustertracks.h"
#include "Track/filtertote.h"
#include "QDesktopWidget"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //QDesktopWidget *d = QApplication.desktop();
    this->setGeometry(QDesktopWidget().geometry());
    //resize(QDesktopWidget().geometry());

    gisview = GisView::GetInstance(ui->GisWidget);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(gisview);
    ui->GisWidget->setLayout(layout);
    //ui->GisWidget->setGeometry(this->x(),this->y,(this->width())-ui->tabWidget->width(),this->height());
    connect(gisview->getMapView(),SIGNAL(settingsChanged()),this,SLOT(ViewMapScale()));

    dbconnection = new DBConnectionForm();


    search = new Searches_form();
    search->setMapView(gisview);
    scrollSearch = new QScrollArea;
    scrollSearch->setBackgroundRole(QPalette::Dark);
    scrollSearch->setWidget(search);


    //createLayerDefs();
    polygon = new Polygon_Form();
    polygon->setMapView(gisview);
    scrollPolygon = new QScrollArea;
    scrollPolygon->setBackgroundRole(QPalette::Dark);
    scrollPolygon->setWidget(polygon);    

    trackform = new track_form();

    /////////// Create Track Repo Object /////////////////
    trackrepo = TrackRepository::getInstance();
    l= new LoadTrackToGisview();
    l->start();

    clustertrackgui=new ClusterTracks;
    clustertrackgui->setMapView(gisview);
    qDebug()<<clustertrackgui->size();
    filtergui=new filtertote();


    ui->tabWidget->addTab(dbconnection,"DB Connection");
    ui->tabWidget->addTab(scrollSearch,"Searches");
    ui->tabWidget->addTab(scrollPolygon,"Polygon");
    ui->tabWidget->addTab(trackform,"Track");
    ui->tabWidget->addTab(clustertrackgui,"Track Clustering");
    ui->tabWidget->addTab(filtergui,"Track Filter");

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(ui->GisWidget);
    layout1->addWidget(ui->tabWidget);
    this->setLayout(layout1);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

   ui->tabWidget->setGeometry(this->geometry().topRight().x()-400,this->geometry().y(),400,900);
   ui->GisWidget->setGeometry(this->geometry());
   //lwidget->setGeometry(mapView->geometry().x(),mapView->geometry().y(),300,400);

   QWidget::resizeEvent(event);
}

void MainWindow::ViewMapScale()
{
    ui->statusBar->showMessage("Map Scale:1cm="+QString::number(gisview->getMapView()->viewScale()/100000)+"km",40000);

}

double MainWindow::computePixelRatio(QRectF worldRectRotated,
                                            QRect windowRect,
                                            double zoomScale)
{
    int mvHeight = windowRect.height();

    int mvWidth =  windowRect.width();

    if ( !mvHeight || !mvWidth)
    {
        return;
    }

    double pixelRatio;

    double aspectRatioMap = worldRectRotated.width()/worldRectRotated.height();

    double aspectRatioWindow = (double)mvWidth / mvHeight;

    if ( aspectRatioWindow > aspectRatioMap  )
    {
        pixelRatio = worldRectRotated.height() / mvHeight;
    }
    else
    {
        pixelRatio = worldRectRotated.width() / mvWidth;
    }

    pixelRatio *= zoomScale;

    return pixelRatio;
}
