#include "markercluster_.h"



MarkerCluster_::MarkerCluster_()
{

}

QList<clusterdt> MarkerCluster_::initialize(QRectF bounds,QList<markerdt> markers, qreal grid){
        reset();
        gridSize = grid;
        minClusterSize = 2;
        map_bound = getExtendedBounds(bounds);
        if(!markers.isEmpty()){
                for(int i=0; i < markers.size(); i++){
                        markerdt marker =  markers.at(i);
                        if(ifContain(map_bound, marker)){
                                markersInBound.append(marker);}}}
        for(int i=0; i < markersInBound.size(); i++){
                 markerdt marker =  markersInBound.at(i);
                 if(!marker.isAdded_){
                  //qDebug() << marker.isAdded_;
                        addToClosestCluster(marker);}}
        /*for(int t=0;t<clusters_.length();t++)
           {
               clusterdt cluster_ = clusters_.at(t);
               qDebug()<< cluster_.length_;
               qDebug() << cluster_.bound_;
               //qDebug()<< cluster_.markers_;
               //qDebug()<< cluster_.center_;
           }*/
        return clusters_;}

void MarkerCluster_::reset(){
        map_bound = QRectF();
        gridSize = 0;
        minClusterSize = 0;
        markersInBound.clear();
        clusters_.clear();
        return;}

bool MarkerCluster_::ifContain(QRectF bounds, markerdt marker){
        QPointF pos_ = getPosition(marker);
        if(bounds.contains(pos_.x(),pos_.y()))
                return true;
        return false;}

QPointF MarkerCluster_::getPosition(markerdt marker){
        return marker.pos;}

void MarkerCluster_::addToClosestCluster(markerdt marker){
        qreal dist = 40000;
        clusterdt clusterToAddTo;
        qDebug() << clusters_.size();
        for(int i=0; i<clusters_.size(); i++){
                clusterdt cluster = clusters_.at(i);
                markerdt center = cluster.center_;
                QPointF pos_ = center.pos;
                if(pos_.isNull()){
                        qreal d = distanceBetweenPoints(center, marker);
                        if(d<dist){
                                dist = d;
                                clusterToAddTo = cluster;}}}
    QPointF pos_ = clusterToAddTo.center_.pos;
    qDebug() << pos_.isNull();
    if(!pos_.isNull() && isMarkerInClusterBounds(clusterToAddTo, marker)){
        addMarker(clusterToAddTo, marker);}
    else{
        qDebug()<<"sahil";
        clusterdt newCluster;
        addMarker(newCluster, marker);
                clusters_.append(newCluster);}}

qreal MarkerCluster_::distanceBetweenPoints(markerdt m1, markerdt m2){
        QPointF p1 = m1.pos;
        QPointF p2 = m2.pos;
        if( p1.isNull() || p2.isNull())
                return 0;
        int R = 6371;
        qreal dLat = qRadiansToDegrees((p1.x()-p2.x()));
        qreal dLong = qRadiansToDegrees(p1.y()-p2.y());
        qreal a = qSin(dLat/2)*qSin(dLat/2) + qSin(dLong/2)*qSin(dLong/2) * qCos(qRadiansToDegrees(p1.x()))*qCos(qRadiansToDegrees(p2.x()));
        qreal c = 2*qAtan2(qSqrt(a),qSqrt(1-a));
        qreal d = R*c;
        return d;}

bool MarkerCluster_::isMarkerInClusterBounds(clusterdt cluster, markerdt marker){
        return ifContain(cluster.bound_, marker);}

void MarkerCluster_::addMarker(clusterdt cluster, markerdt marker){
    if(isMarkerAlreadyAdded(cluster, marker)){qDebug()<<"Marker is Added";
        return;}
    QPointF center = cluster.center_.pos;
    if(center.isNull()){
        qDebug()<<"Eneterd";
        cluster.center_ = marker;
                cluster.bound_ = calculateBounds(cluster);
                qDebug()<<cluster.center_.pos;

    qDebug()<<cluster.bound_;}
        marker.isAdded_=true;
                cluster.markers_.append(marker);
                qDebug()<<cluster.markers_.length();
                cluster.length_++;
        }

bool MarkerCluster_::isMarkerAlreadyAdded(clusterdt cluster, markerdt marker){
        if(cluster.markers_.isEmpty()){
        return false;}
    else{
                for(int i=0; i<cluster.markers_.size() ; i++){
                        markerdt m = cluster.markers_.at(i);
                        if(m.id_==marker.id_){
                                return true;}}}
    return false;}

QRectF MarkerCluster_::calculateBounds(clusterdt cluster){
        QSizeF size = QSizeF(2*gridSize,2*gridSize);
        QPointF topLeft;
        QPointF center = cluster.center_.pos;
        qreal x_ = center.x()-gridSize;
        qreal y_ = center.y()-gridSize;
        topLeft.setX(x_);
        topLeft.setY(y_);
        QPointF& tl = topLeft;
        QSizeF& s = size;
        QRectF Bound_(tl,s);
        return Bound_;}

QRectF MarkerCluster_::getExtendedBounds(QRectF bound){
        qreal ht = bound.height()+ (2*gridSize);
        qreal wth = bound.width()+(2*gridSize);
        QSizeF size=QSizeF(wth,ht);
        QPointF topLeft;
        qreal x_ = topLeft.x() - gridSize;
        qreal y_ = topLeft.y() - gridSize;
        topLeft.setX(x_);
        topLeft.setY(y_);
        QPointF& tl = topLeft;
        QSizeF& s = size;
        QRectF Bound_(tl,s);
        return Bound_;}





