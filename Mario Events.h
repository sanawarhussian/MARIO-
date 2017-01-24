#pragma once
#include"Map.h"
#include"Show_Map.h"
#include"Variables.h"



class MarioEvents
{

public:
	void TickToc();
	void killMario();
	void createPlayer(int initial_X, int initial_Y);
	void playerAnimations();
	void resetEverything();

};

void MarioEvents::resetEverything()
	{
		checkPlayerX = playerX;
		checkPlayerY = playerY;
		time = 400;
		lifes = 3;
		score = 0;
		amIAlive = true;
	}
void MarioEvents::TickToc()
{

if(levelOver == 0)
	{
	if(dbTimer()-gameTimer >100)

		{		
		
		gameTimer = dbTimer();
		if(time>0)time--;
		else
			killMario();

		}
	}
if(time ==200)
	{
		dbPlaySound(StimeWarning);

	}


}
void MarioEvents::killMario()
	{
		if(amIAlive == true && dying == false && takingDamage == false)
		{
			dying = true;
			lifes --;
			amIAlive = false;
			dbPlaySound(Sdeath);
			deathFlash = dbRnd(1);
			if(dbSoundPlaying(SmainTheme)) dbStopSound(SmainTheme);
		}
	}



void MarioEvents::createPlayer(int initial_X, int initial_Y)
	{
		playerX = initial_X;
		playerY = initial_Y;
		currentMario = normalMario; 
		dbSprite(mario, playerX, playerY, mario);
		dbSetSprite(mario, 0, 1);
		dbSetSpritePriority(mario, 1);
	}