#pragma once

class variables
{
public:

};

//YOU CANNOT SURVIVE HERE WITHOUT READING  COMMENTS !!! .....................

#define normalMario 1
#define FireMario 2
#define bottom 1 //used to define the type of collision
#define top 2
#define M 0 //MARIO
#define a 1 //air tile
#define r 10 //restriction tile
#define g 11 //ground tile TOP
#define B 12 //ground tile Bottom
#define p1 13 //pipe tile top right
#define p2 14 // left
#define p3 15 // bottom right
#define p4 16 // bottom left

#define b 20 //brick tile

#define fr 150
#define fl 151
#define P1 152
#define P2 153
#define P3 154
#define P4 155
#define P5 156
#define P5l 157
#define P6 158
#define q 40 //question brick,  
#define qC 32 // q coins 
#define qF 33 // q flower 
#define e 34 // empty block, 
#define k 35 // other blocks scattered around
#define d 70 //d means death used to check if player fell in any of the holes in the map,
#define c 9 //clouds
#define L 99 // 1up boxes
#define C 100 //coins
#define SA 105 
#define f 300  //  fire flower 12 for the anims
#define fB 115 // checkpoint flag bottom
#define fT 116 // checkpoint flag top
#define gM 117 // green mushroom
#define maxAnimations 20 //limiting animations 
#define EPl 170 // enemies plant LEFT (takes  2 tiles) 
#define EPr 200 // enemies plant rIGHT
#define maxPiranhas 10 // limits  maximum number of plants allowed in the map
 
#define G 230 //walkers GOOMBA

#define IMAGE 2

int numoftilesx = 65;
int numoftilesy = 65;
int tilesizex = 65;          //Size of all images is 65x65
int tilesizey = 65;
int speedx = 5;
int speedy = 5; 
int screenCenterX = 380;
int screenCenterY = 280;
int playerX = screenCenterX;
int playerY = screenCenterY;
int mapX = 0;
int mapY = 0;
int oldmapX = 0;
int oldmapY = 0;
int oldx1 = 0;
int oldy1 = 0;
const int COLS = 170; //very high because the map is mostly columns
const int ROWS = 12;
int level = 1; //used to load the right map depending on the level
bool marioSpawned = false; //restricts mario spawns to only 1
bool CheckPointReached = false;

//animation based vars
int qBoxAnim = 0; //increment Question boxes animation
int questionBoxTimer = dbTimer(); //handles how often question box animations are cycled

int coinAnim = 0; //increment coin tiles animation
int coinTimer = dbTimer(); //handles how often coins animations are cycled

//the main map is stored here
bool spaceKeyPressed = false;
int map[COLS][ROWS];


//image used for the score animations
int score200_1 = 71;// 71 to 81
int score100_1 = 270;// 270 to 279 // used for when killing enemies
int score1000_1 = 82;// 82 to 93
int check_1 = 120; // checkpoint images 13 of them
int dust_1 = 133; // dust images 8 of them
int _1up_1 = 245; // 14 up images for the animation
int _1upText_1 = 280;

//display variables, e.g. time, coins
int coins = 0;
int time;
int gameTimer = dbTimer();
int score;
int lifes;


typedef struct extraAnimations 
{
	bool busy; // is there something happening on the current element of the struct, if so skip to the one ahead
	int SetImage; 	
	int frames; 
	int timer; 
	int id; // used to store the 2d and 1d element
	int typeOf; // animatuon sprite based or images based
	int y;
	int x;
	int HighestFrame; 
	int OriginalMapX;
	int FinalFrame; //is used for animations in which after the animation a change is required e.g. 1 up mushroom
	int animDelay; //used to specify what delay between animation each image has
} extraAnimations;

//used for all the plants actions
typedef struct piranhaAI 
{
	int id;//image and sprite id                                         
 	int typeOf; 
	bool tooClose; //if so then stop plant from rising
	bool isAlive; // plant is alive or not               
	int plantTimer; //animation speed
	int plantLoopTimer; //time until it comes back up again
	int plantAnim; 
	int distance;  // plant distance  from mario
	int ReferenceJ;
	int ReferenceI; 

} piranhaAI;


piranhaAI piranhaPlants[maxPiranhas*2]; // because each stores 1 plant e.g. left side or right

extraAnimations anims[maxAnimations]; // allows up to X animations at the same time to maintain performace


