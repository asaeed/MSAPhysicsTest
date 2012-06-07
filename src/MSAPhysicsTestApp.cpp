#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

//#include "MSAPhysics.h"
#include "MSAPhysics2D.h"
#include "ParticleController.h"
#include "Globals.h"

using namespace ci;
using namespace ci::app;
using namespace std;

using namespace MSA;
using namespace Particles;

Physics::World2D physics;
gl::Texture ballImage;	
ParticleController particleController;

class MSAPhysicsTestApp : public AppBasic {
  public:
	void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void mouseUp( MouseEvent event );	
	void mouseMove( MouseEvent event );	
	void mouseDrag( MouseEvent event );
	void keyDown(KeyEvent event);
	void update();
	void draw();
	void addParticle(int posX, int posY);

  private:
	float width;
	float height;
	bool mousePressed;
	Vec2f mousePos;
	Vec2f mouseVel;
};

void MSAPhysicsTestApp::prepareSettings(Settings *settings)
{
	settings->setWindowSize( 1280, 720);
	settings->setFrameRate( 60.0f );
}

void MSAPhysicsTestApp::setup()
{
	ballImage = gl::Texture( loadImage( loadAsset( "ball.png" ) ) );
		
	width = getWindowWidth();
	height = getWindowHeight();
	mousePressed = false;
		
	physics.setGravity(Vec2f(0, global::GRAVITY));
	physics.setWorldSize(Vec2f(0, 0), Vec2f(width, height));
	physics.setSectorCount(1);
	physics.setDrag(0.57f);
	physics.setDrag(1);		// FIXTHIS
	physics.enableCollision();

	// initialize the particleController by passing in the physics world by reference
	particleController.setup(physics);
}

void MSAPhysicsTestApp::mouseDown( MouseEvent event )
{
	mousePressed = true;
}

void MSAPhysicsTestApp::mouseUp( MouseEvent event )
{
	mousePressed = false;
}

void MSAPhysicsTestApp::mouseMove( MouseEvent event )
{
	mouseVel = ( event.getPos() - mousePos );
	mousePos = event.getPos();
}

void MSAPhysicsTestApp::mouseDrag( MouseEvent event )
{
	mouseMove( event );
}

void MSAPhysicsTestApp::keyDown(KeyEvent event) {
		switch(event.getChar()) {
			case ' ': particleController.removeAll(); break;
		}
	}

void MSAPhysicsTestApp::update()
{
	if (mousePressed)
		particleController.addParticle(mousePos);
	particleController.update();
	physics.update();
}

void MSAPhysicsTestApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 

	particleController.draw();
}

CINDER_APP_BASIC( MSAPhysicsTestApp, RendererGl )
