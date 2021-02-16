#ifndef MARKERCLUSTER__H
#define MARKERCLUSTER__H

#include <QObject>
#include <QtGlobal>
#include "qpoint.h"
#include "qrect.h"
#include "QtMath"
#include "QRectF"
#include "QList"
#include "QPointF"
#include "QSizeF"
#include "QtGlobal"
#include "QFile"
#include "QtDebug"
#include "qfile.h"

struct markerdt{
        QPointF pos = QPointF();
        qreal id_=0;
        bool isAdded_ = false;};

struct clusterdt{
        QList<markerdt> markers_;
        markerdt center_;
        QRectF bound_=QRectF();
        long long int length_ = 0;};

class MarkerCluster_
{
public:
    MarkerCluster_();


    QList<clusterdt> initialize(QRectF bounds,QList<markerdt> markers, qreal grid);


private:
    QRectF map_bound=QRectF();
    qreal gridSize = 0;
    int minClusterSize = 0;
    QList<markerdt> markersInBound;
    QList<clusterdt> clusters_;
    void reset();
    QPointF getPosition(markerdt marker);
    bool ifContain(QRectF bounds, markerdt marker);
    QRectF getExtendedBounds(QRectF bounds);
    qreal distanceBetweenPoints(markerdt m1, markerdt m2);
    bool isMarkerInClusterBounds(clusterdt cluster, markerdt marker);
    bool isMarkerAlreadyAdded(clusterdt cluster, markerdt marker);
    QRectF calculateBounds(clusterdt cluster);
    void addMarker(clusterdt cluster, markerdt marker);
    void addToClosestCluster(markerdt marker);
};

#endif // MARKERCLUSTER__H
