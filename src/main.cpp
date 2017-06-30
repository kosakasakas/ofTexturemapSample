#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    // GLバージョンをしていしなくてはいけない
    ofGLWindowSettings settings;
    settings.setGLVersion(4,1); /// < select your GL Version here
    ofCreateWindow(settings); ///< create your window here
    ofRunApp(new ofApp());

}
