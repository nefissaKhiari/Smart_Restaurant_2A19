import QtQuick 2.0
import QtLocation 5.9
import QtPositioning 5.8

Rectangle {
    property double  oldlat: 25.6585
    property double oldlng: 100.3658
      Plugin {
        id: mapPulgin
        name:"osm"
     }
    Map {
    id: mapView
    plugin: mapPulgin
    anchors.fill: parent
    center : QtPositioning.coordinate(oldlat,oldlng);
    zoomLevel: 4
    }
    function setCenter(lat, lng){
        mapView.pan(oldlat - lat,oldlng - lng)
        oldlat =lat
        oldlng =lng


    }

}

