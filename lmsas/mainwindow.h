#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gisview.h"
#include "Polygon/polygon_form.h"
#include "Searches/search_from.h"
#include "qscrollarea.h"
#include "Track/track_form.h"
#include "Track/loadtracktogisview.h"
#include <dbconnectionform.h>
#include "Track/clustertracks.h"
#include "Track/filtertote.h"
#include "/home/trigun/Desktop/Final/MarkerClustering/markerclustering.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GisView *gisview;
    Searches_form *search;
    Polygon_Form *polygon;
    track_form *trackform;

    TrackRepository * trackrepo;
    LoadTrackToGisview *l;
    DBConnectionForm *dbconnection;
    ClusterTracks *clustertrackgui;
    filtertote *filtergui;
    double computePixelRatio(QRectF worldRectRotated,QRect windowRect,double zoomScale);
    QList<markerdt> markers;

public slots:

    void ViewMapScale();

protected:

    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::MainWindow *ui;
    QScrollArea *scrollSearch;
    QScrollArea *scrollPolygon;
};

#endif // MAINWINDOW_H
