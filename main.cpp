#include <QCoreApplication>
#include "markercluster_.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
/*
    QFile file("/home/trigun/Training/data_ship2.txt");
    if(!file.open(QIODevice::ReadOnly)){
            qDebug() << "error opening file: " << file.error();}

    QTextStream instream(&file);

    while(!instream.atEnd()){
            QString line = instream.readLine();
            QString str1 = "ship_id:";//8
            QString str2 = "latitude:";//9
            QString str3 = "";//9
            int i = line.indexOf(str1);
            int j = line.indexOf(str2);
            int k = line.indexOf(str3);
            i+=8;

            }

    file.close();*/

    QPointF pt1=QPointF(16.02779961,66.22720337);
    QPointF pt2=QPointF(16.31469917,67.70529938);
    QPointF pt3=QPointF(16.12730026,67.77469635);
    QPointF pt4=QPointF(13.72299957,71.28549957);
    QPointF pt5=QPointF(16.31529999,67.49500275);
    QPointF pt6=QPointF(12.84619999,66.00350189);
    QPointF pt7=QPointF(16.70299911,72.95149994);
    QPointF pt8=QPointF(9.720829964,76.17359924);
    QPointF pt9=QPointF(16.73550034,72.99849701);
    QPointF pt10=QPointF(11.16679955,93.66519928);
    QPointF pt11=QPointF(16.78199959,71.02850342);
    QPointF pt12=QPointF(16.78199959,71.02829742);
    QPointF pt13=QPointF(17.30970001,71.27300262);
    QPointF pt14=QPointF(16.41309929,70.40720367);
    QPointF pt15=QPointF(17.35029984,71.42230225);
    QPointF pt16=QPointF(17.27050018,71.33450317);
    QPointF pt17=QPointF(-21.08769989,52.35129929);
    QPointF pt18=QPointF(-28.57640076,36.97449875);
    QPointF pt19=QPointF(0.576300025,43.45050049);
    QPointF pt20=QPointF(24.1779995,53.98460007);
    QPointF pt21=QPointF(24.23789978,54.02539825);
    QPointF pt22=QPointF(24.16220093,54.03099823);
    QPointF pt23=QPointF(24.17639923,53.98519897);
    QPointF pt24=QPointF(24.25740051,53.95349884);
    QPointF pt25=QPointF(24.23959923,53.94020081);
    markerdt marker1;
    marker1.id_=1;
    marker1.pos = pt1;
    markerdt marker2;
    marker2.id_=2;
    marker2.pos = pt2;
    markerdt marker3;
    marker3.id_=3;
    marker3.pos = pt3;
    markerdt marker4;
    marker4.id_=4;
    marker4.pos = pt4;
    markerdt marker5;
    marker5.id_=5;
    marker5.pos = pt5;
    markerdt marker6;
    marker6.id_=6;
    marker6.pos = pt6;
    markerdt marker7;
    marker7.id_=7;
    marker7.pos = pt7;
    markerdt marker8;
    marker8.id_=8;
    marker8.pos = pt8;
    markerdt marker9;
    marker9.id_=9;
    marker9.pos = pt9;
    markerdt marker10;
    marker10.id_=10;
    marker10.pos = pt10;
    markerdt marker11;
    marker11.id_=11;
    marker11.pos = pt11;
    markerdt marker12;
    marker12.id_=12;
    marker12.pos = pt12;
    markerdt marker13;
    marker13.id_=13;
    marker13.pos = pt13;
    markerdt marker14;
    marker14.id_=14;
    marker14.pos = pt14;
    markerdt marker15;
    marker15.id_=15;
    marker15.pos = pt15;
    markerdt marker16;
    marker16.id_=16;
    marker16.pos = pt16;
    markerdt marker17;
    marker17.id_=17;
    marker17.pos = pt17;
    markerdt marker18;
    marker18.id_=18;
    marker18.pos = pt18;
    markerdt marker19;
    marker19.id_=19;
    marker19.pos = pt19;
    markerdt marker20;
    marker20.id_=20;
    marker20.pos = pt20;
    markerdt marker21;
    marker21.id_=21;
    marker21.pos = pt21;
    markerdt marker22;
    marker22.id_=22;
    marker22.pos = pt22;
    markerdt marker23;
    marker23.id_=23;
    marker23.pos = pt23;
    markerdt marker24;
    marker24.id_=24;
    marker24.pos = pt24;
    markerdt marker25;
    marker25.id_=25;
    marker25.pos = pt25;

    markerdt& m1=marker1;
    markerdt& m2=marker2;
    markerdt& m3=marker3;
    markerdt& m4=marker4;
    markerdt& m5=marker5;
    markerdt& m6=marker6;
    markerdt& m7=marker7;
    markerdt& m8=marker8;
    markerdt& m9=marker9;
    markerdt& m10=marker10;
    markerdt& m11=marker11;
    markerdt& m12=marker12;
    markerdt& m13=marker13;
    markerdt& m14=marker14;
    markerdt& m15=marker15;
    markerdt& m16=marker16;
    markerdt& m17=marker17;
    markerdt& m18=marker18;
    markerdt& m19=marker19;
    markerdt& m20=marker20;
    markerdt& m21=marker21;
    markerdt& m22=marker22;
    markerdt& m23=marker23;
    markerdt& m24=marker24;
    markerdt& m25=marker25;


    QList<markerdt> markers;
    markers.append(m1);
    markers.append(m2);
    markers.append(m3);
    markers.append(m4);
    markers.append(m5);
    markers.append(m6);
    markers.append(m7);
    markers.append(m8);
    markers.append(m9);
    markers.append(m10);
    markers.append(m11);
    markers.append(m12);
    markers.append(m13);
    markers.append(m14);
    markers.append(m15);
    markers.append(m16);
    markers.append(m17);
    markers.append(m18);
    markers.append(m19);
    markers.append(m20);
    markers.append(m21);
    markers.append(m22);
    markers.append(m23);
    markers.append(m24);
    markers.append(m25);

    QPointF topLeft;
    topLeft.setX(-180);
    topLeft.setY(-90);
    QSizeF size = QSizeF(360,180);
    QPointF& tL = topLeft;
    QSizeF& s = size;
    qreal gridSize = 5;
    QRectF bound = QRectF(tL,s);
    qDebug()<< bound;
    qDebug()<< gridSize;



    MarkerCluster_ test_object;
         QList<clusterdt> clusters =test_object.initialize(bound, markers, gridSize);
  /*for(int t=0;t<clusters.length();t++)
   {
       clusterdt cluster_ = clusters.at(t);
       qDebug()<< cluster_.length_;
       qDebug() << cluster_.bound_;
       //qDebug()<< cluster_.markers_;
       //qDebug()<< cluster_.center_;
   }*/

    return a.exec();
}

/*
*/
