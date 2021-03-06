#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <stdlib.h>
#include <time.h>
#include <Vector2.h>

Application2D::Application2D()
{
}
Application2D::~Application2D()
{
}
bool Application2D::startup()
{
	srand(time(NULL));
	m_2dRenderer = new aie::Renderer2D();
	m_triangle = new aie::Texture("./textures/triangle.png");
	m_background = new aie::Texture("./textures/space.png");
	m_crews = new aie::Texture("./textures/crews.png");
	m_victory = new aie::Texture("./textures/victoryScreen.png");
	m_failure = new aie::Texture("./textures/failureScreen.png");
	m_title = new aie::Texture("./textures/title.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	gameStart = false;
	setup();
	return true;
}
void Application2D::shutdown()
{
	delete m_font;
	delete m_triangle;
	delete m_background;
	delete m_crews;
	delete m_victory;
	delete m_failure;
	delete m_title;
	delete m_2dRenderer;
}
void Application2D::setup()
{
	mPlayer = new Player;
	mLaser = new Laser[1];
	mEnemyLaser = new Laser[1];
	mBackground = new Entity;
	mBackground2 = new Entity;
	mBackground2->mPos.mY = 1080;
	numEnemies = 21;
	mEnemies = new Enemy[numEnemies];
	deadEnemies = 0;
	float enePosX = 340;
	float enePosY = 1000;
	//Initilizes and assigns all the enemies positions
	for (int i = 0; i < numEnemies; i++)
	{
		mEnemies[i].mPos.mX = enePosX;
		mEnemies[i].mPos.mY = enePosY;
		enePosX += 110;
		if (enePosX > 1000)
		{
			enePosX = 340;
			enePosY -= 100;
		}
	}
	mLaserNum = 0;
	mEnemyLaserNum = 0;
	gameWon = false;
	secret = false;
}
void Application2D::update(const float deltaTime)
{
	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();
	const Vector2 playerPos(mPlayer->mPos.mX, mPlayer->mPos.mY);
	const Vector2 enePos(mEnemies[29].mPos.mX, mEnemies[29].mPos.mY);
	if (gameStart)
	{
		//Player movement
		if (input->isKeyDown(aie::INPUT_KEY_A))
			mPlayer->mPos.mX -= 250.0f * deltaTime;
		if (input->isKeyDown(aie::INPUT_KEY_D))
			mPlayer->mPos.mX += 250.0f * deltaTime;
		mPlayer->mPos.mX = input->getMouseX();
		//Boundaries
		if (mPlayer->mPos.mX > 1250)
			mPlayer->mPos.mX = 1249;
		if (mPlayer->mPos.mX < 30)
			mPlayer->mPos.mX = 29;
		//Player Firing
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) || input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
		{
				if (mLaserNum != 0)
					mLaser[mLaserNum - 1].Fire(playerPos);
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
		//Checks if lasers hit an enemy
		for (int e = 0; e < numEnemies; e++)
			mEnemies[e].LaserCheck(mLaser, mLaserNum);
		mPlayer->LaserCheck(mEnemyLaser, mEnemyLaserNum);
		//Checking to see if all enemies are dead
		deadEnemies = 0;
		for (int e = 0; e < numEnemies; e++)
		{
			if (mEnemies[e].mIsAlive == false)
				deadEnemies++;
			if (deadEnemies == numEnemies)
				gameWon = true;
		}
		//Enemy Firing
		if(m_timer >= .3)
		{
			m_timer = 0;

			int randNum = rand() % 29 + 1;
			while (mEnemies[randNum].mIsAlive == false)
				randNum = rand() % 29 + 0;
			if (mEnemyLaserNum != 0)
				mEnemyLaser[mEnemyLaserNum - 1].Fire(mEnemies[randNum].mPos);
			else
				mEnemyLaser[mEnemyLaserNum].Fire(enePos);
			Laser *temp = new Laser[mEnemyLaserNum + 1];
			for (int i = 0; i < mEnemyLaserNum; i++)
				temp[i] = mEnemyLaser[i];
			delete[] mEnemyLaser;
			mEnemyLaser = new Laser[mEnemyLaserNum + 1];
			for (int i = 0; i < mEnemyLaserNum; i++)
				mEnemyLaser[i] = temp[i];
			delete[] temp;
			mEnemyLaserNum++;
		}
		//Updates the lasers postion
		for (int i = 0; i < mLaserNum; i++)
			mLaser[i].Update(deltaTime);
		for(int i = 0;i<mEnemyLaserNum;i++)
			mEnemyLaser[i].mPos.mY -= 500.0f* deltaTime;
		//Enemy Movement
		for (int i = 0; i < numEnemies; i++)
			mEnemies[i].Move(deltaTime);
		mBackground->mPos.mY -= 50.0f*deltaTime;
		if (mBackground->mPos.mY < -360)
			mBackground->mPos.mY = 1079;
		mBackground2->mPos.mY -= 50.0f*deltaTime;
		if (mBackground2->mPos.mY < -360)
			mBackground2->mPos.mY = 1079;
		//Checks to see if an enemy has touched the player or gotten past the player
		for (int i = 0; i < numEnemies; i++)
		{
			if (mEnemies[i].mPos.mY < 120)
				mPlayer->mIsAlive = false;
			if (mEnemies[i].mPos.mX > mPlayer->mPos.mX - (mPlayer->mScale.mX / 2) && mEnemies[i].mPos.mX < mPlayer->mPos.mX + (mPlayer->mScale.mX / 2))
				if (mEnemies[i].mPos.mY > mPlayer->mPos.mY - (mPlayer->mScale.mY / 2) && mEnemies[i].mPos.mY < mPlayer->mPos.mY + (mPlayer->mScale.mY / 2))
					mPlayer->mIsAlive = false;
		}
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
	m_2dRenderer->drawSprite(m_title, 640, 360, 1280, 720);
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		gameStart = true;
	if (gameStart)
	{
		m_2dRenderer->drawSprite(m_background, mBackground->mPos.mX, mBackground->mPos.mY, 1280, 720);
		m_2dRenderer->drawSprite(m_background, mBackground2->mPos.mX, mBackground2->mPos.mY, 1280, 720);
		if (input->wasKeyPressed(aie::INPUT_KEY_F3))
			secret = true;
		if (secret == true)
			m_2dRenderer->drawSprite(m_crews, 640, 360, 1280, 720);
		//Draws the player's sprite if they're still alive
		if (mPlayer->mIsAlive)
			m_2dRenderer->drawSprite(m_triangle, mPlayer->mPos.mX, mPlayer->mPos.mY, mPlayer->mScale.mX, mPlayer->mScale.mX);
		//Draws the lasers if they are fired
		for (int i = 0; i < mLaserNum; i++)
		{
			if (mLaser[i].mIsFired)
			{
				m_2dRenderer->setRenderColour(1, 1, 1, 1);
				m_2dRenderer->drawBox(mLaser[i].mPos.mX, mLaser[i].mPos.mY, mLaser[i].mScale.mX, mLaser[i].mScale.mY);
			}
		}
		//Draws enemies if they are alive
		for (int i = 0; i < numEnemies; i++)
		{
			if (mEnemies[i].mIsAlive)
			{
				m_2dRenderer->setRenderColour(1, 0, 0, 1);
				m_2dRenderer->drawBox(mEnemies[i].mPos.mX, mEnemies[i].mPos.mY, mEnemies[i].mScale.mX, mEnemies[i].mScale.mY);
			}
		}
		for (int i = 0; i<mEnemyLaserNum; i++)
		{
			if (mEnemyLaser[i].mIsFired)
			{
				m_2dRenderer->setRenderColour(0, 1, 0, 1);
				m_2dRenderer->drawBox(mEnemyLaser[i].mPos.mX, mEnemyLaser[i].mPos.mY, 10, 25);
			}
		}
		// output some text, uses the last used colour
		m_2dRenderer->setRenderColour(1, 1, 1, 1);
		char fps[32];
		sprintf_s(fps, 32, "FPS: %i", getFPS());
		m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
		m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	}
	//Draws the victory screen
	if (gameWon)
	{
		m_2dRenderer->drawSprite(m_victory, 640, 360, 1280, 720);
		m_2dRenderer->setRenderColour(0, 0, 0, 1);
		m_2dRenderer->drawText(m_font, "Would you like to play again? Y/N", 335, 360);
		if (input->isKeyDown(aie::INPUT_KEY_Y))
			setup();
		if (input->wasKeyPressed(aie::INPUT_KEY_N))
			quit();
	}
	//Draws the failure screen
	if (mPlayer->mIsAlive == false)
	{
		m_2dRenderer->drawSprite(m_failure, 640, 360, 1280, 720);
		m_2dRenderer->setRenderColour(1, 1, 1, 1);
		m_2dRenderer->drawText(m_font, "Would you like to play again? Y/N", 335, 360);
		if (input->wasKeyPressed(aie::INPUT_KEY_Y))
			setup();
		if (input->wasKeyPressed(aie::INPUT_KEY_N))
			quit();
	}
	// done drawing sprites
	m_2dRenderer->end();
}