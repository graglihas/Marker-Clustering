function MarkerClusterer(map, opt_markers, opt_options) {                       // MarkerClusterer implements
  this.extend(MarkerClusterer,google.maps.OverlayView);                         // google.maps.OverlayView interface. We use the
  this.map_ = map;                                                              // extend function to extend MarkerClusterer with
                                                                                // google.maps.OverlayView because it might not always
                                                                                // be available when the code is defined so we look
                                                                                // for it at the last possible moment. If it doesn't
                                                                                // exist now then there is no point going ahead :)
                                                                                
  this.markers_ = [];                                                           // @type {Array.<google.maps.Marker>} //@private
  
  this.clusters_ = [];                                                          // @type {Array.<Cluster>}
  
  this.sizes = [53, 56, 66, 78, 90];
  
  this.styles_ = [];                                                            // @private
  
  this.ready_ = false;                                                          // @type {boolean} // @private
  
  var options = opt_options || {};
  
  this.gridSize_ = options['gridSize'] || 60;                                   // @type {number} // @private
  
  this.minClusterSize_ = options['minimumClusterSize'] || 2;                    // @private
  
  this.maxZoom_ = options['maxZoom'] || null;                                   // @type {?number} // @private
  
  this.styles_ = options['styles'] || [];
  
  this.imagePath_ = options['imagePath'] || this.MARKER_CLUSTER_IMAGE_PATH_;    // @type {string} //@private
  
  this.imageExtension_ = options['imageExtension'] ||                           // @type {string} // @private
                                           this.MARKER_CLUSTER_IMAGE_EXTENSION_;
                                           
  this.zoomOnClick_ = true;                                                     // @type {boolean} // @private
  
  if (options['zoomOnClick'] != undefined){
        this.zoomOnClick_ = options['zoomOnClick'];}
        
  this.averageCenter_ = false;                                                  // @type {boolean} //@private
  
  if (options['averageCenter'] != undefined) {
        this.averageCenter_ = options['averageCenter'];}
        
  this.setupStyles_();
  
  this.setMap(map);
  
  this.prevZoom_ = this.map_.getZoom();                                         // @type {number} // @private
  
  var that = this;                                                              // Add the map event Listeners
  
  google.maps.event.addListener(this.map_, 'zoom_changed', function() {
    var zoom = that.map_.getZoom();                                             // Determine the map type & prevent illegal zoom levels
    var minZoom = that.map_.minZoom || 0;
    var maxZoom = Math.min(that.map_.maxZoom || 100,
                         that.map_.mapTypes[that.map_.getMapTypeId()].maxZoom);
    zoom = Math.min(Math.max(zoom,minZoom),maxZoom);
    if (that.prevZoom_ != zoom) {
      that.prevZoom_ = zoom;
      that.resetViewport();}});
      
  google.maps.event.addListener(this.map_, 'idle', function() {
    that.redraw();});
    
  if (opt_markers && (opt_markers.length || Object.keys(opt_markers).length)) { // Finally add the markers
    this.addMarkers(opt_markers, false);}}
    
  MarkerClusterer.prototype.MARKER_CLUSTER_IMAGE_PATH_ = '../images/m';         // The marker cluster img path // @type{string} // pvt.
  
  MarkerClusterer.prototype.MARKER_CLUSTER_IMAGE_EXTENSION_ = 'png';            // The marker cluster img path // @type{string} // pvt.
  
  MarkerClusterer.prototype.extend = function(obj1, obj2) {                     // Extends a objects prototype by anothers
    return (function(object) {                                                  // @param {Object} obj1 The object to be extended.
      for (var property in object.prototype) {                                  // @param {Object} obj2 The object to extend with.
        this.prototype[property] = object.prototype[property];}                 // @return {Object} The new extended object.
      return this;}).apply(obj1, [obj2]);};                                     // @ignore
      
  MarkerClusterer.prototype.onAdd = function() {                                // Implementation of the interface method.
    this.setReady_(true);};                                                     // @ignore

  MarkerClusterer.prototype.draw = function() {};                               // Implementation of the interface method // @ignore

  MarkerClusterer.prototype.setupStyles_ = function() {                         // Sets up the styles object
    if (this.styles_.length) {                                                  // @private
      return;}

  for (var i = 0, size; size = this.sizes[i]; i++) {
    this.styles_.push({
      url: this.imagePath_ + (i + 1) + '.' + this.imageExtension_,
      height: size,
      width: size});}};

  MarkerClusterer.prototype.fitMapToMarkers = function() {                      // Fit th emap to the bounds of the markers in the
    var markers = this.getMarkers();                                            // clusterer.
    var bounds = new google.maps.LatLngBounds();
    for (var i = 0, marker; marker = markers[i]; i++) {
      bounds.extend(marker.getPosition());}
    this.map_.fitBounds(bounds);};

  MarkerClusterer.prototype.setStyles = function(styles) {                      // Sets the styles.
    this.styles_ = styles;};                                                    // @param {Object} styles The style to set.

  MarkerClusterer.prototype.getStyles = function() {                            // Gets the styles.
    return this.styles_;};                                                      // @return {Object} The styles object.

  MarkerClusterer.prototype.isZoomOnClick = function() {                        // Wether zoon on click is set.
    return this.zoomOnClick_;};                                                 // @return {boolean} True if zoomOnClick_ is set.

  MarkerClusterer.prototype.isAverageCenter = function() {                      // Whether average center is set.
    return this.averageCenter_;};                                               // @return {boolean} true if averageCenter_ is set.

  MarkerClusterer.prototype.getMarkers = function() {                           // Returns the array of markers i the clusterer.
    return this.markers_;};                                                     // @return {Array.<google.maps.Marker>} The markers.

  MarkerClusterer.prototype.getTotalMarkers = function() {                      // Returns the number of markers in the clusterer.
    return this.markers_.length;};                                              // @return {Number} The number of markers.

  MarkerClusterer.prototype.setMaxZoom = function(maxZoom) {                    // Sets the max zoom for the clusterer.
    this.maxZoom_ = maxZoom;};                                                  // @param {number} maxZoom The max zoom level

  MarkerClusterer.prototype.getMaxZoom = function() {                           // Gets the max zoom for the clusterer.
    return this.maxZoom_;};                                                     // @return {number} The max zoom level.

  MarkerClusterer.prototype.calculator_ = function(markers, numStyles) {        // The function for calculating the cluster icon image.
    var index = 0;                                                              // @param {Array.<google.maps.Marker>} markers The
    var count = markers.length;                                                 // markers in the clusterer.
    var dv = count;                                                             // @param {number} numStyles The number of styles
    while (dv !== 0) {                                                          // available.        
      dv = parseInt(dv / 10, 10);                                               // @return {Object} A object properties: 'text'
      index++;}                                                                 // (string) and 'index' (number)
    index = Math.min(index, numStyles);                                         // @private
    return { text: count, index: index};};

  MarkerClusterer.prototype.setCalculator = function(calculator) {              // Set the calculator function
    this.calculator_ = calculator;};                                            // @param {function(Array, number)} calculator The
                                                                                // function to set as the calculator. The function
                                                                                // should return a object properties: 'test' (string)
                                                                                // and 'index' (number)

  MarkerClusterer.prototype.getCalculator = function() {                        // Get the calculator function.
    return this.calculator_;};                                                  // @return {function(Array,number)} the calclator fx.

  MarkerClusterer.prototype.addMarkers = function(markers, opt_nodraw) {        // Add an array of markers to the clusterer.
    if (markers.length) {                                                       // @param {Array.<google.maps.Marker>} markers The 
      for (var i = 0, marker; marker = markers[i]; i++) {                       //markers to add.
        this.pushMarkerTo_(marker);}}                                           // @param {boolean=} opt_nodraw Whether to redraw 
    else if (Object.keys(markers).length) {                                     // the clusters.
      for (var marker in markers) {
        this.pushMarkerTo_(markers[marker]);}}
    if (!opt_nodraw) {
      this.redraw();}};

  MarkerClusterer.prototype.pushMarkerTo_ = function(marker) {                  // Pushes a marker to the clusterer.
    marker.isAdded = false;                                                     // @param {google.maps.Marker} marker The marker to add
    if (marker['draggable']) {                                                  // @private
      var that = this;                                                          // If the marker is draggable add a listener so we  
      google.maps.event.addListener(marker, 'dragend', function() {             // update th eclusters on the drag end.
        marker.isAdded = false;
        that.repaint();});}
    this.markers_.push(marker);};

  MarkerClusterer.prototype.addMarker = function(marker, opt_nodraw) {          // Adds a marker to the clusterer and redraws if needed
    this.pushMarkerTo_(marker);                                                 // @param {google.maps.Marker} marker The marker to add
    if (!opt_nodraw) {                                                          // @param {boolean=} opt_nodraw Whether yo redraw the 
      this.redraw();}};                                                         // clusters.

  MarkerClusterer.prototype.removeMarker_ = function(marker) {                  // Removes a marker and returns true if removed, false
    var index = -1;                                                             // if not
    if (this.markers_.indexOf) {                                                // @param {google.maps.Marker} marker The marker to
      index = this.markers_.indexOf(marker);}                                   // remove
    else {                                                                      // @return {boolean} Whether the marker was removed
      for (var i = 0, m; m = this.markers_[i]; i++) {                           // or not
        if (m == marker) {                                                      // @private
          index = i;
          break;}}}
    if (index == -1) {                                                          // Marker is not in our list of markers.
      return false;}
    marker.setMap(null);
    this.markers_.splice(index, 1);
    return true;};

  MarkerClusterer.prototype.removeMarker = function(marker, opt_nodraw) {       // Remove a marker from the cluster.
    var removed = this.removeMarker_(marker);                                   // @param {google.maps.Marker} marker The marker to
    if (!opt_nodraw && removed) {                                               // remove.
      this.resetViewport();                                                     // @param {boolean=} opt_nodraw Optional boolean to
      this.redraw();                                                            // force no redraw.
      return true;}                                                             // @return {boolean} True if the marker was removed.
    else {
     return false;}};

  MarkerClusterer.prototype.removeMarkers = function(markers, opt_nodraw) {     // Removes an array of markers form the cluster.
    var markersCopy = markers === this.getMarkers() ? markers.slice() : markers;// @param {Array.<google.mpas.Marker>} markers The 
    var removed = false;                                                        // markers to remove
    for (var i = 0, marker; marker = markersCopy[i]; i++) {                     // @param {boolean=} opt_nodraw Optional boolean to 
      var r = this.removeMarker_(marker);                                       // force no redraw.
      removed = removed || r;}                                                  // create a local copy of markers if required.  
    if (!opt_nodraw && removed) {                                               // ( removeMarker_ modifies the getMarker() array in
      this.resetViewport();                                                     // place )
      this.redraw();
      return true;}};

  MarkerClusterer.prototype.setReady_ = function(ready) {                       // Sets the clusterer's ready state.
    if (!this.ready_) {                                                         // @param {boolean} ready the state.
      this.ready_ = ready;                                                      // @private
      this.createClusters_();}};

  MarkerClusterer.prototype.getTotalClusters = function() {                     // Returns the number of clusters in the clusterer.
    return this.clusters_.length;};                                             // @return {number} The number of clusters.

  MarkerClusterer.prototype.getMap = function() {                               // Returns th egoogle map that the clusterer is 
    return this.map_;};                                                         // associated with.

  MarkerClusterer.prototype.setMap = function(map) {                            // Sets the google map that the clusterer is assosiated
    this.map_ = map;};                                                          // with.
                                                                                // @param {google.maps.Map} map The map.

  MarkerClusterer.prototype.getGridSize = function() {                          // Returns the size of the grid.
    return this.gridSize_;};                                                    // @return {number} The grid size.

  MarkerClusterer.prototype.setGridSize = function(size) {                      // Sets the size of the grid.
    this.gridSize_ = size;};                                                    // @param {number} size The grid size.

  MarkerClusterer.prototype.getMinClusterSize = function() {                    // Returns the min cluster size.
    return this.minClusterSize_;};                                              // @return {number} The grid size.

  MarkerClusterer.prototype.setMinClusterSize = function(size) {                // Sets the min cluster size.
    this.minClusterSize_ = size;};                                              // @param {number} size The grid size.

  MarkerClusterer.prototype.getExtendedBounds = function(bounds) {              // Extends a bounds object by the grid size.
    var projection = this.getProjection();                                      // @param {google.maps.LatLngBounds} Bounds to extend.
                                                                                // @return {google.maps.LatlngBounds} Extended bounds.
    var tr = new google.maps.LatLng(bounds.getNorthEast().lat(),                // Turn the bounds into latlng.
        bounds.getNorthEast().lng());
    var bl = new google.maps.LatLng(bounds.getSouthWest().lat(),
        bounds.getSouthWest().lng());
    var trPix = projection.fromLatLngToDivPixel(tr);                            // Convert th epoints to pixels and the extend out by
    trPix.x += this.gridSize_;                                                  // the grid size.
    trPix.y -= this.gridSize_;
    var blPix = projection.fromLatLngToDivPixel(bl);
    blPix.x -= this.gridSize_;
    blPix.y += this.gridSize_;
    var ne = projection.fromDivPixelToLatLng(trPix);                            // Convert the pixel points back to LatLng
    var sw = projection.fromDivPixelToLatLng(blPix);
    bounds.extend(ne);                                                          // Extend the bounds to contain th enew bounds.
    bounds.extend(sw);
    return bounds;};

  MarkerClusterer.prototype.isMarkerInBounds_ = function(marker, bounds) {      // Determines if a marker is contained in a bounds.
    return bounds.contains(marker.getPosition());};                             // @param {google.maps.Marker} marker The marker to     
                                                                                // check.
                                                                                // @param {google.maps.LatLngBounds} bounds The bounds
                                                                                // to check against.
                                                                                // @return {boolean} True if marker is in the bounds.
                                                                                // @private.

  MarkerClusterer.prototype.clearMarkers = function() {                         // Clears all clusters and markers from the clusterer.
    this.resetViewport(true);
    this.markers_ = [];};                                                       // Set the markers a empty array.

  MarkerClusterer.prototype.resetViewport = function(opt_hide) {                // Clears all existing clusters and recreate them.
    for (var i = 0, cluster; cluster = this.clusters_[i]; i++) {                // @param {boolean} opt_hide To also hide the marker.
      cluster.remove();}                                                        // Remove all the clusters
    for (var i = 0, marker; marker = this.markers_[i]; i++) {                   // Reset the markers to not be added and to be invisible
      marker.isAdded = false;
      if (opt_hide) {
        marker.setMap(null);}}
    this.clusters_ = [];};

  MarkerClusterer.prototype.repaint = function() {
    var oldClusters = this.clusters_.slice();
    this.clusters_.length = 0;
    this.resetViewport();
    this.redraw();
    window.setTimeout(function() {                                              // Remove the old clusters.
      for (var i = 0, cluster; cluster = oldClusters[i]; i++) {                 // Do it in a timeout so the other clusters have been
        cluster.remove();}}, 0);};                                              // drawn first.

  MarkerClusterer.prototype.redraw = function() {                               // Redraws the clusters.
    this.createClusters_();};

  MarkerClusterer.prototype.distanceBetweenPoints_ = function(p1, p2) {         // Calculates the dist b/w 2 latlng locations in km
    if (!p1 || !p2) {                                                           // @param {google.maps.LatLng} p1 The 1st latlng pt.
      return 0;}                                                                // @param {google.maps.LatLng} p2 The 2nd latlng pt.
    var R = 6371;                                                               // @return {number} The dist b/w 2 pts in km.
    var dLat = (p2.lat() - p1.lat()) * Math.PI / 180;                           // @private.
    var dLon = (p2.lng() - p1.lng()) * Math.PI / 180;                           // R = 6371 is Radius of Earth in km.
    var a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
      Math.cos(p1.lat() * Math.PI / 180) * Math.cos(p2.lat() * Math.PI / 180) *
      Math.sin(dLon / 2) * Math.sin(dLon / 2);
    var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
    var d = R * c;
    return d;};

  MarkerClusterer.prototype.addToClosestCluster_ = function(marker) {           // Add a marker to cluster, or creates a new cluster.
    var distance = 40000;                                                       // @param {google.maps.Marker}marker The marker to add. 
    var clusterToAddTo = null;                                                  // @private.
    var pos = marker.getPosition();                                             // dist = 40000 is just choosing some large number.
    for (var i = 0, cluster; cluster = this.clusters_[i]; i++) {
      var center = cluster.getCenter();
      if (center) {
        var d = this.distanceBetweenPoints_(center, marker.getPosition());
        if (d < distance) {
          distance = d;
          clusterToAddTo = cluster;}}}
    if (clusterToAddTo && clusterToAddTo.isMarkerInClusterBounds(marker)) {
      clusterToAddTo.addMarker(marker);}
    else {
      var cluster = new Cluster(this);
      cluster.addMarker(marker);
      this.clusters_.push(cluster);}};

  MarkerClusterer.prototype.createClusters_ = function() {                      // Creates the clusters.
    if (!this.ready_) {                                                         // @private
      return;}
    var mapBounds =                                                             // Get our current map view bounds
              new google.maps.LatLngBounds(this.map_.getBounds().getSouthWest(),// Create a new bounds object so we don't affect map.
              this.map_.getBounds().getNorthEast());
    var bounds = this.getExtendedBounds(mapBounds);
    for (var i = 0, marker; marker = this.markers_[i]; i++) {
    if (!marker.isAdded && this.isMarkerInBounds_(marker, bounds)) {
      this.addToClosestCluster_(marker);}}};

  function Cluster(markerClusterer) {                                           // A cluster that contains markers.
    this.markerClusterer_ = markerClusterer;                                    // @param {MarkerClusterer} markerClusterer The 
    this.map_ = markerClusterer.getMap();                                       // markerClusterer that this cluster is associated with
    this.gridSize_ = markerClusterer.getGridSize();                             // @constructor
    this.minClusterSize_ = markerClusterer.getMinClusterSize();                 // @private
    this.averageCenter_ = markerClusterer.isAverageCenter();
    this.center_ = null;
    this.markers_ = [];
    this.bounds_ = null;
    this.clusterIcon_ = new ClusterIcon(this, markerClusterer.getStyles(),
        markerClusterer.getGridSize());}

  Cluster.prototype.isMarkerAlreadyAdded = function(marker) {                   // Determines if a marker is already added to cluster.
    if (this.markers_.indexOf) {                                                // @param {google.maps.Marker} The marker to check.
      return this.markers_.indexOf(marker) != -1;}                              // @return {boolean} True if marker is already added.
    else {
      for (var i = 0, m; m = this.markers_[i]; i++) {
        if (m == marker) {
          return true;}}}
    return false;};

  Cluster.prototype.addMarker = function(marker) {                              // Add a marker to the cluster.
    if (this.isMarkerAlreadyAdded(marker)) {                                    // @param {google.maps.Marker} marker The marker to add.
      return false;}                                                            // @return {boolean} True if the marker was added.
    if (!this.center_) {
      this.center_ = marker.getPosition();
      this.calculateBounds_();}
    else {
      if (this.averageCenter_) {
        var l = this.markers_.length + 1;
        var lat = (this.center_.lat() * (l-1) + marker.getPosition().lat()) / l;
        var lng = (this.center_.lng() * (l-1) + marker.getPosition().lng()) / l;
        this.center_ = new google.maps.LatLng(lat, lng);
        this.calculateBounds_();}}
    marker.isAdded = true;
    this.markers_.push(marker);
    var len = this.markers_.length;
    if (len < this.minClusterSize_ && marker.getMap() != this.map_) {
    marker.setMap(this.map_);}                                                  // Min cluster size not reached so show the marker.
    if (len == this.minClusterSize_) {
      for (var i = 0; i < len; i++) {                                           // Hide the markers that were showing.
        this.markers_[i].setMap(null);}}
    if (len >= this.minClusterSize_) {
      marker.setMap(null);}
    this.updateIcon();
    return true;};

  Cluster.prototype.getMarkerClusterer = function() {                           // Returns the marker clusterer that the cluster is 
    return this.markerClusterer_;};                                             // associated with.
                                                                                // @return {MarkerClusterer} The associated marker 
                                                                                // clusterer.

  Cluster.prototype.getBounds = function() {                                    // Returns the bounds of the cluster.
    var bounds = new google.maps.LatLngBounds(this.center_, this.center_);      // @return {google.maps.LatLngBounds} the cluster 
    var markers = this.getMarkers();                                            // bounds.
    for (var i = 0, marker; marker = markers[i]; i++) {
      bounds.extend(marker.getPosition());}
    return bounds;};

  Cluster.prototype.remove = function() {                                       // Removes the cluster
    this.clusterIcon_.remove();
    this.markers_.length = 0;
    delete this.markers_;};

  Cluster.prototype.getSize = function() {                                      // Returns the number of markers in the cluster.
    return this.markers_.length;};                                              // @return {number} The number of markers in the cluster

  Cluster.prototype.getMarkers = function() {                                   // Returns a list of the markers in the cluster.
    return this.markers_;};                                                     // @return {Array.<google.maps.Marker>} The markers in 
                                                                                // the cluster.

  Cluster.prototype.getCenter = function() {                                    // Returns the center of the cluster.
    return this.center_;};                                                      // @return {google.maps.LatLng} The cluster center.

  Cluster.prototype.calculateBounds_ = function() {                             // Calculated the extended bounds of the cluster with 
    var bounds = new google.maps.LatLngBounds(this.center_, this.center_);      // the grid.
    this.bounds_ = this.markerClusterer_.getExtendedBounds(bounds);};           // @private

  Cluster.prototype.isMarkerInClusterBounds = function(marker) {                // Determines if a marker lies in the clusters bounds.
    return this.bounds_.contains(marker.getPosition());};                       // @param {google.maps.Marker}marker The marker to check
                                                                                // @return {boolean} True if the marker lies in bounds.

  Cluster.prototype.getMap = function() {                                       // Returns the map that the cluster is associated with.
    return this.map_;};                                                         // @return {google.maps.Map} The map.

  Cluster.prototype.updateIcon = function() {                                   // Updates the cluster icon
    var zoom = this.map_.getZoom();
    var mz = this.markerClusterer_.getMaxZoom();
    if (mz && zoom > mz) {
      for (var i = 0, marker; marker = this.markers_[i]; i++) {                 // The zoom is greater than our max zoom so show all 
        marker.setMap(this.map_);}                                              // the markers in cluster.
    return;}
    if (this.markers_.length < this.minClusterSize_) {
    this.clusterIcon_.hide();                                                   // Min cluster size not yet reached.
    return;}
    var numStyles = this.markerClusterer_.getStyles().length;
    var sums = this.markerClusterer_.getCalculator()(this.markers_, numStyles);
    this.clusterIcon_.setCenter(this.center_);
    this.clusterIcon_.setSums(sums);
    this.clusterIcon_.show();};

  function ClusterIcon(cluster, styles, opt_padding) {                          // A cluster icon
    cluster.getMarkerClusterer().extend(ClusterIcon, google.maps.OverlayView);  // @param {Cluster} The cluster to be associated with.
    this.styles_ = styles;                                                      // @param {Object} styles An object that has style 
    this.padding_ = opt_padding || 0;                                           // properties:
    this.cluster_ = cluster;                                                    //      'url': (string) The image url.
    this.center_ = null;                                                        //      'height': (number) The image height.
    this.map_ = cluster.getMap();                                               //      'width': (number) The image width.
    this.div_ = null;                                                           //      'anchor': (Array) anchor position of label text.
    this.sums_ = null;                                                          //      'textColor': (string) The text color.
    this.visible_ = false;                                                      //      'textSize': (number) The text size.
    this.setMap(this.map_);}                                                    //      'backgroundPosition:(string) background pos x,y.
                                                                                // @param {number=} opt_padding Optional padding to 
                                                                                // apply to the cluster icon.
                                                                                // @constructor // @ignore
                                                                                // @extends google.maps.OverlayView

  ClusterIcon.prototype.triggerClusterClick = function() {                      // Triggers the clusterclick event and zoom's if the 
    var markerClusterer = this.cluster_.getMarkerClusterer();                   // option is set.
    google.maps.event.trigger(markerClusterer.map_,'clusterclick',this.cluster_);// Trigger the clusterclick event.
    if (markerClusterer.isZoomOnClick()) {
    this.map_.fitBounds(this.cluster_.getBounds());}};                          // Zoom into the cluster.

  ClusterIcon.prototype.onAdd = function() {                                    // Adding the cluster icon to the dom.
    this.div_ = document.createElement('DIV');                                  // @ignore
    if (this.visible_) {
      var pos = this.getPosFromLatLng_(this.center_);
      this.div_.style.cssText = this.createCss(pos);
      this.div_.innerHTML = this.sums_.text;}
    var panes = this.getPanes();
    panes.overlayMouseTarget.appendChild(this.div_);
    var that = this;
    google.maps.event.addDomListener(this.div_, 'click', function() {
      that.triggerClusterClick();});};

  ClusterIcon.prototype.getPosFromLatLng_ = function(latlng) {                  // Returns the position to place the div depending on 
    var pos = this.getProjection().fromLatLngToDivPixel(latlng);                // the latlng.
    pos.x -= parseInt(this.width_ / 2, 10);                                     // @param {google.maps.LatLng} latlng position in latlng
    pos.y -= parseInt(this.height_ / 2, 10);                                    // @return {google.maps.Point} The position in pixels.
    return pos;};                                                               // @private

  ClusterIcon.prototype.draw = function() {                                     // Draw the icon.
    if (this.visible_) {                                                        // @ignore.
      var pos = this.getPosFromLatLng_(this.center_);
      this.div_.style.top = pos.y + 'px';
      this.div_.style.left = pos.x + 'px';
      this.div_.style.zIndex = google.maps.Marker.MAX_ZINDEX + 1;}};

  ClusterIcon.prototype.hide = function() {                                     // Hide the icon.
    if (this.div_) {
      this.div_.style.display = 'none';}
    this.visible_ = false;};

  ClusterIcon.prototype.show = function() {                                     // Position and show the icon.
    if (this.div_) {
      var pos = this.getPosFromLatLng_(this.center_);
      this.div_.style.cssText = this.createCss(pos);
      this.div_.style.display = '';}
    this.visible_ = true;};

  ClusterIcon.prototype.remove = function() {                                   // Remove the icon from the map
    this.setMap(null);};

  ClusterIcon.prototype.onRemove = function() {                                 // Implementation of the onRemove interface.
    if (this.div_ && this.div_.parentNode) {                                    // @ignore
      this.hide();
      this.div_.parentNode.removeChild(this.div_);
      this.div_ = null;}};

  ClusterIcon.prototype.setSums = function(sums) {                              // Set the sums of the icon.
    this.sums_ = sums;                                                          // @param {Object} sums The sums containing:
    this.text_ = sums.text;                                                     //      'text': (string) The text to display in the icon
    this.index_ = sums.index;                                                   //      'index': (number) The style index of the icon.
    if (this.div_) {
      this.div_.innerHTML = sums.text;}
    this.useStyle();};

  ClusterIcon.prototype.useStyle = function() {                                 // Sets the icon to the the styles.
    var index = Math.max(0, this.sums_.index - 1);
    index = Math.min(this.styles_.length - 1, index);
    var style = this.styles_[index];
    this.url_ = style['url'];
    this.height_ = style['height'];
    this.width_ = style['width'];
    this.textColor_ = style['textColor'];
    this.anchor_ = style['anchor'];
    this.textSize_ = style['textSize'];
    this.backgroundPosition_ = style['backgroundPosition'];};

  ClusterIcon.prototype.setCenter = function(center) {                          // Sets the center of the icon.
    this.center_ = center;};                                                    // @param {google.maps.LatLng} center The latlng to set 
                                                                                // as the center.

  ClusterIcon.prototype.createCss = function(pos) {                             // Create the css text based on the position of the icon
    var style = [];                                                             // @param {google.maps.Point} pos The position.
    style.push('background-image:url(' + this.url_ + ');');                     // @return {string} The css style text.
    var backgroundPosition=this.backgroundPosition_?this.backgroundPosition_:'0 0';
    style.push('background-position:' + backgroundPosition + ';');
    if (typeof this.anchor_ === 'object') {
      if (typeof this.anchor_[0] === 'number' && this.anchor_[0] > 0 &&
          this.anchor_[0] < this.height_) {
        style.push('height:' + (this.height_ - this.anchor_[0]) +
            'px; padding-top:' + this.anchor_[0] + 'px;');}
      else {
        style.push('height:' + this.height_ + 'px; line-height:' + this.height_
           + 'px;');}
      if (typeof this.anchor_[1] === 'number' && this.anchor_[1] > 0 &&
          this.anchor_[1] < this.width_) {
        style.push('width:' + (this.width_ - this.anchor_[1]) +
            'px; padding-left:' + this.anchor_[1] + 'px;');}
      else {
        style.push('width:' + this.width_ + 'px; text-align:center;');}}
    else {
      style.push('height:' + this.height_ + 'px; line-height:' +
          this.height_ + 'px; width:' +this.width_ + 'px; text-align:center;');}
    var txtColor = this.textColor_ ? this.textColor_ : 'black';
    var txtSize = this.textSize_ ? this.textSize_ : 11;
    style.push('cursor:pointer; top:' + pos.y + 'px; left:' +
        pos.x + 'px; color:' + txtColor + '; position:absolute; font-size:' +
        txtSize + 'px; font-family:Arial,sans-serif; font-weight:bold');
    return style.join('');};

// Export Symbols for Closure. If you are not going to compile with closure then you can remove the code below.
  window['MarkerClusterer'] = MarkerClusterer;
  MarkerClusterer.prototype['addMarker'] = MarkerClusterer.prototype.addMarker;
  MarkerClusterer.prototype['addMarkers'] = MarkerClusterer.prototype.addMarkers;
  MarkerClusterer.prototype['clearMarkers'] = MarkerClusterer.prototype.clearMarkers;
  MarkerClusterer.prototype['fitMapToMarkers'] = MarkerClusterer.prototype.fitMapToMarkers;
  MarkerClusterer.prototype['getCalculator'] = MarkerClusterer.prototype.getCalculator;
  MarkerClusterer.prototype['getGridSize'] = MarkerClusterer.prototype.getGridSize;
  MarkerClusterer.prototype['getExtendedBounds'] = MarkerClusterer.prototype.getExtendedBounds;
  MarkerClusterer.prototype['getMap'] = MarkerClusterer.prototype.getMap;
  MarkerClusterer.prototype['getMarkers'] = MarkerClusterer.prototype.getMarkers;
  MarkerClusterer.prototype['getMaxZoom'] = MarkerClusterer.prototype.getMaxZoom;
  MarkerClusterer.prototype['getStyles'] = MarkerClusterer.prototype.getStyles;
  MarkerClusterer.prototype['getTotalClusters'] = MarkerClusterer.prototype.getTotalClusters;
  MarkerClusterer.prototype['getTotalMarkers'] = MarkerClusterer.prototype.getTotalMarkers;
  MarkerClusterer.prototype['redraw'] = MarkerClusterer.prototype.redraw;
  MarkerClusterer.prototype['removeMarker'] = MarkerClusterer.prototype.removeMarker;
  MarkerClusterer.prototype['removeMarkers'] = MarkerClusterer.prototype.removeMarkers;
  MarkerClusterer.prototype['resetViewport'] = MarkerClusterer.prototype.resetViewport;
  MarkerClusterer.prototype['repaint'] = MarkerClusterer.prototype.repaint;
  MarkerClusterer.prototype['setCalculator'] = MarkerClusterer.prototype.setCalculator;
  MarkerClusterer.prototype['setGridSize'] = MarkerClusterer.prototype.setGridSize;
  MarkerClusterer.prototype['setMaxZoom'] =  MarkerClusterer.prototype.setMaxZoom;
  MarkerClusterer.prototype['onAdd'] = MarkerClusterer.prototype.onAdd;
  MarkerClusterer.prototype['draw'] = MarkerClusterer.prototype.draw;

  Cluster.prototype['getCenter'] = Cluster.prototype.getCenter;
  Cluster.prototype['getSize'] = Cluster.prototype.getSize;
  Cluster.prototype['getMarkers'] = Cluster.prototype.getMarkers;

  ClusterIcon.prototype['onAdd'] = ClusterIcon.prototype.onAdd;
  ClusterIcon.prototype['draw'] = ClusterIcon.prototype.draw;
  ClusterIcon.prototype['onRemove'] = ClusterIcon.prototype.onRemove;

  Object.keys = Object.keys || function(o) {
      var result = [];
      for(var name in o) {
          if (o.hasOwnProperty(name))
            result.push(name);}
      return result;};
