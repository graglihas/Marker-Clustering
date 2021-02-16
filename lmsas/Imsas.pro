#-------------------------------------------------
#
# Project created by QtCreator 2017-02-15T00:39:35
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Imsas
TEMPLATE = app

QMAKE_CFLAGS = -fpermissive
QMAKE_CXXFLAGS = -fpermissive
QMAKE_LFLAGS = -fpermissive

DEFINES += INCLUDE_S57
#INCLUDEDIR += /home/himanshu/ImsasDesign/Gis/CAIRGIS/include
#INCLUDEDIR += gis

#INCLUDEPATH += .
#INCLUDEPATH += ..
#INCLUDEPATH += $$INCLUDEDIR/
#INCLUDEPATH += $$INCLUDEDIR/Support
#INCLUDEPATH += $$INCLUDEDIR/CAIRGIS
#INCLUDEPATH += $$INCLUDEDIR/CAIRGIS/CGKernel
INCLUDEPATH += ./libCommonTrigun \
              ./common \
              ./Gis

#LIBS += -L/home/himanshu/ImsasDesign/Gis/CAIRGIS/lib/libCAIRGIS -lIndigisCore -lIndigisRT -lConnection -lProjection -lGeoComputation -lS52Renderer -lS57ReadWrite -lIVFReadWrite -lOGRReadWrite -lOGRConverter -lFileConnection -lQueryAnalysis -lDigitize

#LIBS += -L/home/himanshu/ImsasDesign/Gis/CAIRGIS/lib/libSupport -lproj -lspatialite -lrasterlite -lgeos -lgeos_c -lgdal



#INCLUDEDIR =  /home/himanshu/ImsasDesign/Gis/CAIRGIS/include
#CAIRGIS_INCLUDE =  INCLUDEDIR/CAIRGIS

#INCLUDEPATH += .
##INCLUDEPATH += $$INCLUDEDIR/includes
#INCLUDEPATH += $$INCLUDEDIR/CAIRGIS
#INCLUDEPATH += $$INCLUDEDIR/Support
#INCLUDEPATH += $$INCLUDEDIR
#INCLUDEPATH += $$INCLUDEDIR/CAIRGIS/CGKernel

#INCLUDEPATH += $$CAIRGIS_INCLUDE/CGKernel
#INCLUDEPATH += $$CAIRGIS_INCLUDE/CGVectorRW
#INCLUDEPATH += $$INCLUDEDIR/Support/spatialite
#INCLUDEPATH += $$INCLUDEDIR/Support/GDAL
#INCLUDEPATH += $$INCLUDEDIR/Support/DGN
#INCLUDEPATH += $$CAIRGIS_INCLUDE/CGS52Renderer

#LIBSDIR = /home/himanshu/ImsasDesign/Gis/CAIRGIS/lib

##DEFINES += STATIC_LIB

#CONFIG += $$DEFINES


#LIBS += -L$$LIBSDIR/libSupport/libusb/
#LIBS += $$LIBSDIR/libSupport/libusb/libusb-1.0.so

#LIBS += -L$$LIBSDIR/libSupport/libOled/
#LIBS += $$LIBSDIR/libSupport/libOled/libsmartkeys.so

#LIBS += -L$$LIBSDIR/libCAIRGIS/

#LIBS += $$LIBSDIR/libCAIRGIS/libTerrainAnalysis.so
#LIBS += $$LIBSDIR/libCAIRGIS/libS52Renderer.so
#LIBS += $$LIBSDIR/libCAIRGIS/libS57ReadWrite.so
#LIBS += $$LIBSDIR/libCAIRGIS/libGeoEvents.so
#LIBS += $$LIBSDIR/libCAIRGIS/libQueryAnalysis.so
#LIBS += $$LIBSDIR/libCAIRGIS/libDigitize.so
#LIBS += $$LIBSDIR/libCAIRGIS/libFileConnection.so
#LIBS += $$LIBSDIR/libCAIRGIS/libIVFReadWrite.so
#LIBS += $$LIBSDIR/libCAIRGIS/libDGNReadWrite.so
#LIBS += $$LIBSDIR/libCAIRGIS/libOGRReadWrite.so
#LIBS += $$LIBSDIR/libCAIRGIS/libOGRConverter.so
#LIBS += $$LIBSDIR/libCAIRGIS/libConnection.so
#LIBS += $$LIBSDIR/libCAIRGIS/libKernel.so
#LIBS += $$LIBSDIR/libCAIRGIS/libIMGRS.so
#LIBS += $$LIBSDIR/libCAIRGIS/libGeoComputation.so
#LIBS += $$LIBSDIR/libCAIRGIS/libProjection.so

#LIBS += -L$$LIBSDIR/libSupport/

#LIBS += $$LIBSDIR/libSupport/libproj.so.0.6.6
#LIBS += $$LIBSDIR/libSupport/libspatialite.so.1.1.3
#LIBS += $$LIBSDIR/libSupport/librasterlite.so.1.0.0
#LIBS += $$LIBSDIR/libSupport/libgeos-3.2.3.so
#LIBS += $$LIBSDIR/libSupport/libgeos_c.so.1.6.3
#LIBS += $$LIBSDIR/libSupport/libgdal.so.1.15.1

#LIBS += $$LIBSDIR/libSupport/libcurl.so.3

CAIRGIS_INCLUDE = /home/trigun/gis/CAIRGIS/include/CAIRGIS
SUPPORT_INCLUDE = /home/trigun/gis/CAIRGIS/include/Support

INCLUDEPATH += .
INCLUDEPATH += $$CAIRGIS_INCLUDE/
INCLUDEPATH += $$CAIRGIS_INCLUDE/CGKernel
INCLUDEPATH += $$SUPPORT_INCLUDE

LIBS += -L/home/trigun/gis/CAIRGIS/lib/libSupport

LIBS += -lproj
LIBS += -lspatialite
LIBS += -lrasterlite
LIBS += -lgeos
LIBS += -lgeos_c
LIBS += -lgdal

LIBS += -L/home/trigun/gis/CAIRGIS/lib/libCAIRGIS

LIBS += -lKernel
LIBS += -lGeoEvents
LIBS += -lQueryAnalysis
LIBS += -lConnection
LIBS += -lProjection
LIBS += -lGeoComputation
LIBS += -lS52Renderer
LIBS += -lS57ReadWrite
LIBS += -lOGRReadWrite
LIBS += -lOGRConverter
LIBS += -lDGNReadWrite
LIBS += -lIMGRS
LIBS += -lFileConnection
LIBS += -lcurl
LIBS += -lDigitize
LIBS += -L./libCommonTrigun -lCommonTrigun




SOURCES += main.cpp\
        mainwindow.cpp \
    gisview.cpp \
    Polygon/polygon.cpp \
    Polygon/polygon_controller.cpp \
    Polygon/polygon_form.cpp \
    Polygon/polygon_model.cpp \
    Searches/search_form.cpp \
    Searches/expandingsquaresearch_form.cpp \
    Searches/TrigunESS.cpp \
    Searches/TrigunSearch.cpp \
    Searches/S52ViewAPI.cpp \
    common/colorcoding.cpp \
    common/CommonFuncts.cpp \
    common/HeartBeat.cpp \
    common/IPAddressDialog.cpp \
    common/parser.cpp \
    common/TrigunMessage.cpp \
    Track/track_form.cpp \
    Track/Track.cpp \
    Track/TrackReadFromSource.cpp \
    Track/tracktrail.cpp \
    Controller.cpp \
    Track/manualtrack.cpp \
    Track/trackrepository.cpp \
    Track/track_controller.cpp \
    Track/tracklayerdef.cpp \
    Track/loadtracktogisview.cpp \
    Track/trackreadfromdb.cpp \
    Track/merchanttrack.cpp \
    Track/airtrack.cpp \
    Track/warship.cpp \
    dbconnectionform.cpp \
    Track/clustertracks.cpp \
    Track/clustertrackcontroller.cpp \
    Track/filtertote.cpp \
    Track/filter_criteria.cpp \
    Track/updatetrackfilterstatus.cpp \
    Gis/MapLoading/encloader.cpp \
    Gis/MapLoading/maploader.cpp \
    Gis/MapLoading/mapmetadata.cpp \
    Gis/MapLoading/rastermaploader.cpp \
    Gis/MapLoading/vectormaploader.cpp \
    Polygon/polygonlayerdef.cpp \
    ../../Desktop/Final/MarkerClustering/markerclustering.cpp \
    Track/trackclusterlayerdefinition.cpp




HEADERS  += mainwindow.h \
    gisview.h \
    Polygon/polygon.h \
    Polygon/polygon_controller.h \
    Polygon/polygon_form.h \
    Polygon/polygon_model.h \
    Searches/search_from.h \
    Searches/expandingsquaresearch_form.h \
    Searches/TrigunESS.h \
    Searches/TrigunSearch.h \
    Searches/TrigunSrchStructs.h \
    Searches/S52ViewAPI.h \
    libCommonTrigun/access.h \
    libCommonTrigun/Blowfish.h \
    libCommonTrigun/Blowfishentries.h \
    libCommonTrigun/commonSocket.h \
    libCommonTrigun/commonThread.h \
    libCommonTrigun/Crc.h \
    libCommonTrigun/dataTypes.h \
    libCommonTrigun/debug.h \
    libCommonTrigun/imo.h \
    libCommonTrigun/nmea.h \
    libCommonTrigun/portable.h \
    libCommonTrigun/protectedQueue.h \
    libCommonTrigun/seaway.h \
    libCommonTrigun/sixbit.h \
    libCommonTrigun/utility.h \
    libCommonTrigun/vdm_parse.h \
    common/colorcoding.h \
    common/CommonFuncts.h \
    common/Constants.h \
    common/HeartBeat.h \
    common/IPAddressDialog.h \
    common/NmeaFormat.h \
    common/parser.h \
    common/sensorMsgStruct.h \
    common/TrigunMessage.h \
    common/Blowfish.h \
    common/Blowfishentries.h \
    common/Crc.h \
    Track/track_form.h \
    Track/Track.h \
    Track/TrackReadFromSource.h \
    Track/tracktrail.h \
    Controller.h \
    Track/manualtrack.h \
    Track/trackrepository.h \
    Track/track_controller.h \
    Track/tracklayerdef.h \
    Track/loadtracktogisview.h \
    Track/trackreadfromdb.h \
    Track/merchanttrack.h \
    Track/airtrack.h \
    Track/warship.h \
    dbconnectionform.h \
    Track/clustertracks.h \
    Track/clustertrackcontroller.h \
    Track/filtertote.h \
    Track/filter_criteria.h \
    Track/updatetrackfilterstatus.h \
    Gis/MapLoading/encloader.h \
    Gis/MapLoading/maploader.h \
    Gis/MapLoading/mapmetadata.h \
    Gis/MapLoading/rastermaploader.h \
    Gis/MapLoading/vectormaploader.h \
    ui_clustertracks.h \
    ui_dbconnectionform.h \
    ui_expandingsquaresearch_form.h \
    ui_filtertote.h \
    ui_gisview.h \
    ui_mainwindow.h \
    ui_polygon_form.h \
    ui_search_from.h \
    ui_track_form.h \
    Polygon/polygonlayerdef.h \
    ../../Desktop/Final/MarkerClustering/markerclustering.h \
    Track/trackclusterlayerdefinition.h



FORMS    += mainwindow.ui \
    gisview.ui \
    Polygon/polygon_form.ui \
    Searches/search_from.ui \
    Searches/expandingsquaresearch_form.ui \
    Track/track_form.ui \
    dbconnectionform.ui \
    Track/clustertracks.ui \
    Track/filtertote.ui
