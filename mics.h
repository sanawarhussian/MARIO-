#pragma once 
class misc
{

int FindSprite(); 


};

int misc::FindSprite()
{
int i =10;
  while(dbSpriteExist(i))
  {
  i++;
  
  }
return i;

}

