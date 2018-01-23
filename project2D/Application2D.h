#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Application.h"
#include "Renderer2D.h"
#include "Laser.h"
#include <LinkedList.h>
class Application2D : public aie::Application
{
public:
	Application2D();
	virtual ~Application2D();
	virtual bool startup();
	virtual void shutdown();
	virtual void update(float deltaTime);
	virtual void draw();
protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		mTexture;
	aie::Texture*		mShipTexture;
	aie::Texture*		mEnemyShip;
	aie::Font*			mFont;
	Player *mPlayer;
	Enemy *mEnemy;
	Laser *mLaser;
	Laser *mLaser2;
	LinkedListType<Laser> *mLasers;
	LinkedListIterator<Laser> Iter;
	int mNumLasers = 0;
	float m_cameraX, m_cameraY;
	float m_timer;
};