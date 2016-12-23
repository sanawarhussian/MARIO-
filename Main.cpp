#include"DarkGDK.h"
#include"Map.h"
#include"Show_Map.h"
#include"variables.h"
void DarkGDK(void)
{
	
ShowMap M1;
dbSyncOn();

dbSyncRate(60);

dbSetDisplayMode(800,600,32);
dbMaximizeWindow();
dbBackdropOn();
dbBackdropColor(dbRGB(44, 155, 100));
MapOne.LoadImages();
MapOne.LoadLevel(1);
MapOne.LoadSound();


while(LoopGDK())
{
M1.displayLevel();
M1.displayInformation();
dbSync();


}
return;

}