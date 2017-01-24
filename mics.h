#pragma once 
class misc
{
public:
int FindSprite(); 
bool noEssentialKeyBeingPressed();

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

bool misc::noEssentialKeyBeingPressed()
	{
		if(!dbUpKey() && !dbLeftKey() && !dbRightKey() && !dbSpaceKey())
		{
			return true;
		}
		return false;
	}