#pragma once 
#include "Map.h"
#include"Mario Events.h"
MarioEvents myEvents;
//#include<iostream>
//using namespace std;


class ShowMap
{
public:
void PasteTiles(int, int , int ,int , int ,int );
void displayLevel();
void playSounds();
void displayInformation();

};


void ShowMap::playSounds()
{
	if(amIAlive)
	{
		//if checkpoint sound is on then reduce main song volume
		if(dbSoundPlaying(ScheckPoint))dbSetSoundVolume(SmainTheme, 80);
		else dbSetSoundVolume(SmainTheme, 100); 
		
		if(dbSoundPlaying(SmainTheme)==0 && levelOver == 0)dbPlaySound(SmainTheme);
	}
}
void ShowMap::displayInformation()
{
	dbSetTextSize(30);
	//displays points
	char points[100];
	sprintf_s ( points, 200, "Score \n ", score);
	//std::cout << points <<200<<"Score"<<std::endl<<score;
	dbText (50, 50, points);	
	
	{ dbSetTextSize(8);
		char Creator [50];char Class[50];
 sprintf_s(Creator,"NS Snawar Hussain \n");
 sprintf_s(Class, "DE_37_MTS\n " );
dbText (660, 25, Creator);
dbText (660, 50, Class);
	}
	{ dbSetTextSize(8);
		char Creator [50];char Class[50];
 sprintf_s(Creator,"NS Usama Tahir \n ");
 sprintf_s(Class, "DE_37_MTS\n " );
dbText (660, 75, Creator);
dbText (660, 100, Class);
	}
	 dbSetTextSize(30);

//sprintf_s ( points, 200, "Score \n ", score);
  	//displays coins
	char coinNum[100];
	sprintf_s ( coinNum, 200, "Coins \n %d", coins);
	dbText (150, 50, coinNum);	

	//displays level number
	char levelbeingPlayed[100];
	sprintf_s ( levelbeingPlayed, 200, "Level \n %d", level);
	dbText (300, 50, levelbeingPlayed);	

	//displays lifes number
	char Lifes[100];
	sprintf_s ( Lifes, 200, "Lifes \n %d", lifes);
	dbText (400, 50, Lifes);

	//displays time 
	char timeLeft[100];
	sprintf_s ( timeLeft, 200, "Time \n %d", time);
	dbText (500, 50, timeLeft);	
}



void ShowMap::PasteTiles(int x, int tilenumx,int y,int tilenumy, int tempx, int tempy)

{


	//===================================================================================
	if(map[x + tilenumx][y + tilenumy] == qC || map[x + tilenumx][y + tilenumy] == qF)
	{ 
		if(dbTimer() - questionBoxTimer > 75) //animation frames change every 75 ms
		{
			questionBoxTimer = dbTimer();
			qBoxAnim++;
			if(qBoxAnim == 26) qBoxAnim = 0;
		}
		dbPasteImage( q + qBoxAnim, ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy );
	}
	//coins
	else if(map[x + tilenumx][y + tilenumy] == C)
	{ 
		if(dbTimer() - coinTimer > 100) //animation frames change every 75 ms
		{
			coinTimer = dbTimer();
			coinAnim++;
			if(coinAnim == 6) coinAnim = 0;
		}
		dbPasteImage( map[x + tilenumx][y + tilenumy]+ coinAnim, ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy );
	}
	else if(map[x + tilenumx][y + tilenumy] == EPl)
	{ 
		for(int i = 0; i < maxPiranhas; i ++)
		{ 
						if(piranhaPlants[i].ReferenceJ == x + tilenumx && piranhaPlants[i].ReferenceI == y + tilenumy)
			{
				if(dbSpriteVisible(piranhaPlants[i].id)==0)
				{
					dbShowSprite(piranhaPlants[i].id);
				}
				dbPasteImage( map[x + tilenumx][y + tilenumy] + piranhaPlants[i+1].plantAnim, ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy );
				dbSprite(piranhaPlants[i].id, ( x * tilesizex ),( y * tilesizey ), map[x + tilenumx][y + tilenumy] + piranhaPlants[i+1].plantAnim);
					break; 
			}
		}
	}
	
	else if(map[x + tilenumx][y + tilenumy] == EPr)
	{ 
		for(int i = 0; i < maxPiranhas; i ++)
		{
			
			if(piranhaPlants[i].ReferenceJ == x + tilenumx && piranhaPlants[i].ReferenceI == y + tilenumy)
			{
				if(dbSpriteVisible(piranhaPlants[i].id)==0)
				{
					dbShowSprite(piranhaPlants[i].id);
				}
				if(dbTimer() - piranhaPlants[i].plantTimer > 100 && dbTimer() - piranhaPlants[i].plantLoopTimer > 1400) //animation frames change every 100 ms
				{
					piranhaPlants[i].plantTimer = dbTimer();
					
					if(piranhaPlants[i].tooClose == true && piranhaPlants[i].plantAnim == 0)
					{
						piranhaPlants[i].plantLoopTimer = dbTimer();
						
					}
					//check if player is very close to left plant, if so then keep it down once it finishes anim
					else if(piranhaPlants[i-1].tooClose == true && piranhaPlants[i].plantAnim == 0)
					{
						piranhaPlants[i].plantLoopTimer = dbTimer();
						//if mario is too close to the plant then stop it from rising again until hes at a specific distance
					}
					else 
					{
						piranhaPlants[i].plantAnim++;
						if(piranhaPlants[i].plantAnim == 5 || piranhaPlants[i].plantAnim == 10 || piranhaPlants[i].plantAnim == 15 || piranhaPlants[i].plantAnim == 25 )
						{
							if(piranhaPlants[i].distance < 500)
							{
								
							}
						}
					}
					if(piranhaPlants[i].plantAnim == 30)
					{
						piranhaPlants[i].plantAnim = 0;
						piranhaPlants[i].plantLoopTimer = dbTimer();
					}
				}
				dbPasteImage( map[x + tilenumx][y + tilenumy] + piranhaPlants[i].plantAnim, ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy );
				dbSprite(piranhaPlants[i].id, ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy, map[x + tilenumx][y + tilenumy] + piranhaPlants[i].plantAnim);
				break; 
			}

		}
	}
	//fire  flower
	else if(map[x + tilenumx][y + tilenumy] == f)
	{ 
		dbPasteImage( map[x + tilenumx][y + tilenumy], ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy );
	}
	//Displays all kinds of tile based animations
	else if(map[x + tilenumx][y + tilenumy] == SA)
	{
		bool foundRightElement = false; 		for(int i = 0; i < maxAnimations && foundRightElement == false; i++)
		{
			if(anims[i].busy == true)
			{
				if(anims[i].typeOf == IMAGE)
				{
					//if id matches the element within the 2d array
					if(anims[i].id == map[x + tilenumx][y + tilenumy]/*Makes sure that tiles arent overwritten when there are multiple anims*/ && anims[i].x == x + tilenumx && anims[i].y == y + tilenumy)
					{
						foundRightElement = true;
						//1000 score animation
						if(dbTimer() - anims[i].timer > 80) //animation frames change every 75 ms
						{
							anims[i].timer = dbTimer();
							anims[i].frames++;
										
							if(anims[i].frames == anims[i].HighestFrame)
							{
								anims[i].busy = false;
								//turn that into an air tile or an object such as 1up mushroom
								map[x + tilenumx][y + tilenumy] = anims[i].FinalFrame;
							}  
						}
						dbPasteImage( anims[i].SetImage + anims[i].frames, ( x * tilesizex ) - tempx,  ( y * tilesizey ) - tempy );
					}
				}
			}
		}

	}
	//GOOMBAS before first spawn
	else if(map[x + tilenumx][y + tilenumy] == G)
	{ 
		map[x + tilenumx][y + tilenumy] = a;
		//if user is trying to spawn more than one mario then create an air tile instead
		
		//enemy SOMETHING
	}
	//mario spawn spot, if any more than 1 are found they are converted into air tiles
	else if(map[x + tilenumx][y + tilenumy] == M)
	{ 
		map[x + tilenumx][y + tilenumy] = a;
		//if user is trying to spawn more than one mario then create an air tile instead
		if(marioSpawned == false)
		{
			marioSpawned = true;
			myEvents.createPlayer((( x * tilesizex ) - tempx),  (y * tilesizey ) - tempy);
		}
	}
	//1up box before being seen
	else if(map[x + tilenumx][y + tilenumy] == L)
	{ 
	   dbPasteImage( map[x + tilenumx][y + tilenumy], ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy );
	}
	//Green mushroom +1 life
	else if(map[x + tilenumx][y + tilenumy] == gM)
	{ 
	   dbPasteImage( _1up_1+16, ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy );
	}
	else// displays a normal tile(without any animations)
    {
	   dbPasteImage( map[x + tilenumx][y + tilenumy], ( x * tilesizex ) - tempx, ( y * tilesizey ) - tempy );
	}

}
void ShowMap:: displayLevel()
{	
      int tilenumx = mapX / numoftilesx;
   int tilenumy = mapY / numoftilesy;
   
    
     
   int tempx = mapX - ( tilenumx * tilesizex );
   int tempy = mapY - ( tilenumy * tilesizey );
  

   //Pasting images
   int i =0;
   int j =170;
   for (int y = 0; y <= 12; y++ ) //Displaying 15 Rows each time on screen 
   {

      for (int x = 0; x <= 15; x++ ) 
	  {     
		  PasteTiles(x, tilenumx, y, tilenumy, tempx, tempy);
		 
		  
		  
			
		  if(dbRightKey() == 1)

		   { 
			   	if(i >170-25)
				{   mapX= mapX-35;
					break;
				}
				mapX++;
				i++;
		  
		  }
		  if(dbLeftKey() == 1)

		   {
			   if(j <25)
				{   mapX= mapX+35;
					break;
				}	
				mapX--;
				j--;
		  }	 
		  		  
	  }
   }

}
