#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_triangle = new aie::Texture("./textures/triangle.png");
	m_bullet = new aie::Texture("./textures/bullet.png");
	m_background = new aie::Texture("./textures/space.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	mPlayer = new Player;
	mLaser = new Laser[255];
	mEnemy = new Enemy;
	mLaserNum = 0;
	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPlayer->mPos.mX -= 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPlayer->mPos.mX += 500.0f * deltaTime;
	if (mPlayer->mPos.mX > 1280)
		mPlayer->mPos.mX = 1279;
	if (mPlayer->mPos.mX < 0)
		mPlayer->mPos.mX = 1;
	Laser *temp = new Laser[mLaserNum];
	for (int i = 0; i < mLaserNum; i++)
		temp[i] = mLaser[i];
	delete mLaser;
	Laser *mLaser = new Laser[mLaserNum + 1];
	for (int i = 0; i < mLaserNum; i++)
		mLaser[i] = temp[i];
	delete temp;
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {
	// wipe the screen to the background colour
	clearScreen();
	aie::Input* input = aie::Input::getInstance();
	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	m_2dRenderer->drawSprite(m_background, 640, 360, 1280, 720);
	m_2dRenderer->drawSprite(m_triangle, mPlayer->mPos.mX, mPlayer->mPos.mY, 60, 60);
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(mEnemy->mPos.mX, mEnemy->mPos.mY, 150, 20);
	//// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// draw a moving purple circle
	/*m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);*/
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		mLaser[mLaserNum] = mPlayer->Shoot();
		mLaser[mLaserNum].Draw(m_2dRenderer, m_timer, mPlayer, m_bullet);
		mLaserNum++;
	}
	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	//
	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	// done drawing sprites
	m_2dRenderer->end();
}