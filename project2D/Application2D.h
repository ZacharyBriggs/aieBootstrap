#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Entity.h"
#include "Laser.h"
#include "Enemy.h"
#include "Player.h"
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
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_background;
	aie::Texture*		m_crews;
	aie::Texture*		m_triangle;
	aie::Texture*		m_bullet;
	aie::Texture*		m_victory;
	aie::Texture*		m_failure;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;
	Player *mPlayer;
	Laser *mLaser;
	Laser *mEnemyLaser;
	Enemy *mEnemies;
	int deadEnemies;
	int mLaserNum;
	int mEnemyLaserNum;
	bool gameWon;
	bool secret;
};