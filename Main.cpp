//GROUP MEMBERS
//NC Snawar Hussain
//NC Muhammad Usama Tahir
#include"DarkGDK.h"
#include"Map.h"
#include"Show_Map.h"
#include"variables.h"
#include"Mario Events.h"
//#include"Mario Movements.h"
void DarkGDK(void)
{
Map MapOne;	
ShowMap M1;
MarioEvents MarioEvent;

dbSyncOn();

dbSyncRate(60);

dbSetDisplayMode(800,600,32);
dbMaximizeWindow();
dbBackdropOn();
dbBackdropColor(dbRGB(44, 155, 100));

MarioEvent.resetEverything();
MapOne.LoadImages();
MapOne.LoadSound();
MapOne.LoadLevel(1);
while(LoopGDK())
{
MarioEvent.TickToc();

M1.displayLevel();
M1.displayInformation();
M1.playSounds();

dbSync();


}

return;

}