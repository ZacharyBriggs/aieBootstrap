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
	m_triangle = new aie::Texture("./textures/triangle.png");
	m_bullet = new aie::Texture("./textures/bullet.png");
	m_background = new aie::Texture("./textures/space.png");
	m_victory = new aie::Texture("./textures/victoryScreen.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	mPlayer = new Player;
	mLaser = new Laser[1];
	mEnemyLaser = new Laser[1];
	mEnemies = new Enemy[15];
	deadEnemies = 0;
	int enePosX = 450;
	int enePosY = 600;
	for (int i = 0; i < 15; i++)
	{
		mEnemies[i].mPos.mX = enePosX;
		mEnemies[i].mPos.mY = enePosY;
		enePosX += 100;
		if (enePosX == 950)
		{
			enePosX = 450;
			enePosY -= 100;
		}
	}
	mLaserNum = 0;
	mEnemyLaserNum = 0;
	gameWon = false;
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
	Vector2 playerPos(mPlayer->mPos.mX, mPlayer->mPos.mY);
	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPlayer->mPos.mX -= 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPlayer->mPos.mX += 500.0f * deltaTime;
	if (mPlayer->mPos.mX > 1250)
		mPlayer->mPos.mX = 1249;
	if (mPlayer->mPos.mX < 30)
		mPlayer->mPos.mX = 29;

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		if (mLaserNum != 0)
			mLaser[mLaserNum - 1].Fire(playerPos);
		else
			mLaser[mLaserNum].Fire(playerPos);
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

	for (int i = 0; i < mLaserNum; i++)
	{
		for (int e = 0; e < 15; e++)
			if (mLaser[i].mPos.mX > mEnemies[e].mPos.mX - (mEnemies[e].mScale.mX / 2) && mLaser[i].mPos.mX < mEnemies[e].mPos.mX + (mEnemies[e].mScale.mX / 2))
			{
				if (mLaser[i].mPos.mY > mEnemies[e].mPos.mY - mEnemies[e].mScale.mY && mLaser[i].mPos.mY < mEnemies[e].mPos.mY + mEnemies[e].mScale.mY)
				{
					mEnemies[e].mIsAlive = false;
					mEnemies[e].mPos.mY = 0;
					mLaser[i].mIsFired = false;
				}
			}
	}
	deadEnemies = 0;
	for (int e = 0; e < 15; e++)
	{
		if (mEnemies[e].mIsAlive == false)
 			deadEnemies++;
		if (deadEnemies == 15)
			gameWon = true;
	}
	for (int i = 0; i < mLaserNum; i ++)
	{
		mLaser[i].Update(deltaTime);
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}
void Application2D::draw()
{
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
		{
			m_2dRenderer->setRenderColour(1, 1, 1, 1);
			m_2dRenderer->drawBox(mLaser[i].mPos.mX, mLaser[i].mPos.mY, mLaser[i].mScale.mX, mLaser[i].mScale.mY);
		}
	}
	/*for (int i = 0; i < mEnemyLaserNum; i++)
	{
		if (mLaser[i].mIsFired)
		{
			m_2dRenderer->setRenderColour(1, 0, 0, 1);
			m_2dRenderer->drawBox(mEnemy->mPos.mX, mEnemy->mPos.mY, mEnemyLaser[i].mScale.mX, mLaser[i].mScale.mY);
		}
	}*/
	for (int i = 0; i < 15; i++)
	{
		if (mEnemies[i].mIsAlive)
		{
			m_2dRenderer->setRenderColour(1, 0, 0, 1);
			m_2dRenderer->drawBox(mEnemies[i].mPos.mX, mEnemies[i].mPos.mY, mEnemies[i].mScale.mX, mEnemies[i].mScale.mY);
		}
	}
	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	if (gameWon)
	{
		m_2dRenderer->drawSprite(m_victory, 640, 360, 500, 500);
	}
	// done drawing sprites
	m_2dRenderer->end();
}