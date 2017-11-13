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
	mLaser = new Laser[1];
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

	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		if (mLaserNum != 0)
			mLaser[mLaserNum - 1] = mPlayer->Shoot();
		else
			mLaser[mLaserNum] = mPlayer->Shoot();
		Laser *temp = new Laser[mLaserNum + 1];
		for (int i = 0; i < mLaserNum; i++)
			temp[i] = mLaser[i];
		delete[] mLaser;
		mLaser = new Laser[mLaserNum + 1];
		for (int i = 0; i < mLaserNum; i++)
			mLaser[i] = temp[i];
		delete[] temp;
		mLaser[mLaserNum].mIsFired = true;
		mLaserNum++;
	}
	if (mLaser[mLaserNum].mPos.mX < 790 && mLaser[mLaserNum].mPos.mX > 490 && mLaser[mLaserNum].mPos.mY > 580 && mLaser[mLaserNum].mPos.mY < 620)
		mEnemy->mPos.mY += 500.0f * deltaTime;
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
	m_2dRenderer->drawSprite(m_triangle, mPlayer->mPos.mX, mPlayer->mPos.mY, mPlayer->mScale.mX, mPlayer->mScale.mX);

	for (int i = 0; i < mLaserNum; i++)
	{
		if (mLaser[i].mIsFired)
			m_2dRenderer->drawBox(mLaser[i].mPos.mX, mLaser[i].mPos.mY, 20, 20);
	}
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(mEnemy->mPos.mX, mEnemy->mPos.mY, mEnemy->mScale.mX, mEnemy->mScale.mY);
	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	// done drawing sprites
	m_2dRenderer->end();
}