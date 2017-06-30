#include "ofApp.h"

namespace {
    
    // 回転角度
    int m_AngleY = 0;
    int m_AngleX = 0;
    
    // シェーダ
    ofShader m_Shader;
    
    // テクスチャ
    ofImage m_Image;
    
    // カメラ
    ofCamera m_Cam;
    
    // メッシュ
    ofMesh  m_Mesh;
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    // これをしないとUV座標が[0.0, 1.0]にならない
    ofDisableArbTex();
    
    // カメラのセット
    {
        m_Cam.setPosition( 0.0f, 0.0f, 100.0f );
        m_Cam.lookAt( {0.0f, 0.0f, 0.0f} );
    }
    
    // メッシュのセットアップ
    {
        float radius = 10.0;
        
        m_Mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_STRIP);
        
        // 頂点
        m_Mesh.addVertex( { -radius, -radius, radius} );
        m_Mesh.addVertex( { radius,  -radius, radius} );
        m_Mesh.addVertex( { -radius, radius,  radius} );
        m_Mesh.addVertex( { radius,  radius,  radius} );
        m_Mesh.addVertex( { -radius, -radius, -radius} );
        m_Mesh.addVertex( { radius,  -radius, -radius} );
        m_Mesh.addVertex( { -radius, radius,  -radius} );
        m_Mesh.addVertex( { radius,  radius,  -radius} );
        
        // UV
        m_Mesh.addTexCoord({0.0, 1.0});
        m_Mesh.addTexCoord({1.0, 1.0});
        m_Mesh.addTexCoord({0.0, 0.0});
        m_Mesh.addTexCoord({1.0, 0.0});
        m_Mesh.addTexCoord({0.0, 1.0});
        m_Mesh.addTexCoord({1.0, 1.0});
        m_Mesh.addTexCoord({0.0, 0.0});
        m_Mesh.addTexCoord({1.0, 0.0});
        
        // インデックス
        m_Mesh.addIndex(0);
        m_Mesh.addIndex(1);
        m_Mesh.addIndex(2);
        m_Mesh.addIndex(3);
        m_Mesh.addIndex(7);
        m_Mesh.addIndex(1);
        m_Mesh.addIndex(5);
        m_Mesh.addIndex(4);
        m_Mesh.addIndex(7);
        m_Mesh.addIndex(6);
        m_Mesh.addIndex(2);
        m_Mesh.addIndex(4);
        m_Mesh.addIndex(0);
        m_Mesh.addIndex(1);
    }
    
    // シェーダのセット
    {
        m_Shader.load("texturemap.vert", "texturemap.frag");
    }
    
    // テクスチャのセット
    {
        m_Image.load("texture.jpg");
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    // 角度を更新
    m_AngleX += 1;
    m_AngleY += 2;
    m_AngleX %= 360;
    m_AngleY %= 360;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // デプステストを有効にする
    ofEnableDepthTest();
    
    // シェーダのバインド
    m_Shader.begin();
    {
        // カメラのバインド
        m_Cam.begin();
        {
            // 行列を退避
            ofPushMatrix();
            {
                // 回転
                ofRotateX(m_AngleX);
                ofRotateY(m_AngleY);
                
                // シェーダパラメータセット
                m_Shader.setUniformTexture("u_texture", m_Image, 0);
                
                // メッシュ描画
                m_Mesh.drawFaces();
            }
            ofPopMatrix();
        }
        m_Cam.end();
    }
    m_Shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
