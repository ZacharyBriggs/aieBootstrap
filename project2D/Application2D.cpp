#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D()
{
}
Application2D::~Application2D()
{
}
bool Application2D::startup()
{
	m_2dRenderer = new aie::Renderer2D();
	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	mPlayer = new Entity;
	mCursor = new Entity;
	mLaser = new Laser[1];
	mLaserNum = 0;
	setShowCursor(false);
	return true;
}
void Application2D::shutdown()
{
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}
void Application2D::update(float deltaTime)
{
	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();
	// use arrow keys to move camera
	/*if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;*/
	if (input->isKeyDown(aie::INPUT_KEY_W))
		mPlayer->mY += 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_S))
		mPlayer->mY -= 500.0f*deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPlayer->mX -= 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPlayer->mX += 500.0f*deltaTime;
	//Player Firing
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		mCursorPosX = input->getMouseX();
		mCursorPosY = input->getMouseY();
		if (mLaserNum != 0)
			mLaser[mLaserNum - 1].Fire(mCursorPosX,mCursorPosY);
		Laser *temp = new Laser[mLaserNum + 1];
		for (int i = 0; i < mLaserNum; i++)
			temp[i] = mLaser[i];
		delete[] mLaser;
		mLaser = new Laser[mLaserNum + 1];
		for (int i = 0; i < mLaserNum; i++)
			mLaser[i] = temp[i];
		delete[] temp;
		mLaserNum++;
	}
	mCursor->mX = input->getMouseX();
	mCursor->mY = input->getMouseY();
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}
void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();
	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	// begin drawing sprites
	m_2dRenderer->begin();
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawBox(mPlayer->mX, mPlayer->mY, 50, 50);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawCircle(mCursor->mX, mCursor->mY, 10, 10);
	for (int i = 0; i < mLaserNum; i++)
	{
		if (mLaser[i].mIsFired)
		{
			m_2dRenderer->setRenderColour(1, 1, 1, 1);
			m_2dRenderer->drawBox(mLaser[i].mX, mLaser[i].mY, 20, 20);
		}
	}
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	// done drawing sprites
	m_2dRenderer->end();
}