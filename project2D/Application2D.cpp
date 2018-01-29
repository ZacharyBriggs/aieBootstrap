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
	mTexture = new aie::Texture("./textures/numbered_grid.tga");
	mShipTexture = new aie::Texture("./textures/ship.png");
	mEnemyShip = new aie::Texture("./textures/triangle.png");
	mFont = new aie::Font("./font/consolas.ttf", 32);
	mPlayer = new Player;
	mEnemy = new Enemy;
	mLaser = new Laser;
	mLaser2 = new Laser;
	mLasers = new LinkedListType<Laser>;
	mLasers->InitializeList();
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	return true;
}
void Application2D::shutdown()
{
	delete mFont;
	delete mTexture;
	delete mShipTexture;
	delete m_2dRenderer;
}
void Application2D::update(float deltaTime)
{
	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();
	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;
	//Moving Player
	if(input->isKeyDown(aie::INPUT_KEY_W))
		mPlayer->ChangePosY(mPlayer->GetPosY() + 500.0f * deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_S))
		mPlayer->ChangePosY(mPlayer->GetPosY() - 500.0f * deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_A))
		mPlayer->ChangePosX(mPlayer->GetPosX() - 500.0f * deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_D))
		mPlayer->ChangePosX(mPlayer->GetPosX() + 500.0f * deltaTime);
	//Firing Lasers
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		Laser  *newLaser = new Laser();
		newLaser->Fire(mPlayer->GetPosXY());
		if (mNumLasers > 1)
		{
			mLasers->InsertLast(*newLaser);
			std::cout << mLasers->Length() << std::endl;
		}
		else
			mLasers->InsertFirst(*newLaser);
		mNumLasers++;
	}
	Iter = mLasers->Begin();
	//Updates Laser Position
	for (int i = 0; i < mNumLasers; i++)
	{
		Iter.operator*().Update(deltaTime);
		Iter.operator++();
	}
	Iter = mLasers->Begin();
	//Boundaries
	if (mPlayer->GetPosY() > 720)
		mPlayer->ChangePosY(719);
	if (mPlayer->GetPosY() < 30)
		mPlayer->ChangePosY(29);
	if (mPlayer->GetPosX() > 1250)
		mPlayer->ChangePosX(1249);
	if (mPlayer->GetPosX() < 30)
		mPlayer->ChangePosX(29);
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}
void Application2D::draw()
{
	clearScreen();
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	m_2dRenderer->begin();
	if (mPlayer->mIsAlive == true)
	{
		m_2dRenderer->setRenderColour(1, 0, 0, 1);
		m_2dRenderer->drawCircle(mPlayer->GetPosX(), mPlayer->GetPosY(), mPlayer->mRadius);
	}
	for (int i = 0; i < mLasers->Length(); i++)
	{
		if (Iter.operator*().mIsAlive == true)
		{
			m_2dRenderer->setRenderColour(0, 0, 1, 1);
			m_2dRenderer->drawBox(Iter.operator*().GetPosX(), Iter.operator*().GetPosY(), 50, 50);
		}
		Iter.operator++();
	}
	Iter = mLasers->Begin();
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(mEnemyShip,mEnemy->GetPosX(),mEnemy->GetPosY(),mEnemy->GetWidth(),mEnemy->GetHeight());
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(mFont, fps, 0, 720 - 32);
	m_2dRenderer->drawText(mFont, "Press ESC to quit!", 0, 720 - 64);
	// done drawing sprites
	m_2dRenderer->end();
}