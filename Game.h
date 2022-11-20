#if !defined(MACRO)
#define MACRO
    #include <stdio.h>
    #include <stdlib.h>

//Structures
typedef struct Move
{
    char right;
    char left;
    char up;
    char down;
    char bomb;
    char next;
} Move;

typedef struct Map
{
    char **map;
    int x;
    int y;

} Map;


typedef struct
{
    int range;
    int bombX;
    int bombY;
} Bomb;

typedef struct Player
{
    int nbrBombe;
    int vie;
    int x;
    int y;
    int invincibility;
    Bomb *bomb;
} Player;

// Int
char map1[7][9] = {
    {'2'},
    {'9', ' ', '5'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'p', '-', 'm', 'm', 'm', 'x', 'm', 'x'},
    {'x', '-', 'm', 'm', 'm', 'm', 'm', '-', '-'},
    {'-', '-', '-', 'g', '-', 'm', 'm', '-', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}};
// 4 - 0 // 4 - 8

char map2[13][5] = {
    {'1'},
    {'5', ' ', '8'},
    {'x', 'x', 'x', 'x', 'x'},
    {'x', 'p', '-', 'm', 'x'},
    {'x', '-', 'x', 'm', 'x'},
    {'x', 'm', 'm', 'g', 'm'},
    {'-', '-', 'm', '-', 'x'},
    {'x', 'm', 'x', '-', 'x'},
    {'x', 'm', 'm', 'm', 'x'},
    {'x', 'x', 'm', 'm', 'x'},
    {'x', 'm', 'x', 'x', 'x'},
    {'x', 'm', '-', '-', 'x'},
    {'x', 'm', 'm', 'm', 'x'},
    {'x', 'x', 'x', 'x', 'x'}};

char map3[14][10] = {
    {'1'},
    {'5', ' ', '8'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'p', '-', 'm', '-', '-', 'm', 'm', 'y', 'x'},
    {'x', 'm', 'x', 'm', 'x', 'm', 'm', 'm', '-', 'x'},
    {'-', '-', 'm', 'm', '-', 'x', 'x', '-', '-', 'x'},
    {'-', '-', 'x', '-', '-', 'x', 'x', '-', '-', 'x'},
    {'x', 'm', 'x', 'm', 'x', '-', 'm', 'm', 'm', 'x'},
    {'x', 'm', '-', 'm', 'x', 'm', 'm', '-', 'x', '-'},
    {'x', 'm', 'm', 'x', 'x', 'm', 'm', 'm', 'm', 'x'},
    {'x', '-', 'm', 'm', 'x', 'm', 'm', 'm', 'm', '-'},
    {'x', '-', '-', 'm', 'm', 'm', 'x', '-', '-', 'x'},
    {'x', 'b', 'm', 'm', '-', '-', 'm', '-', 'g', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}
    };

//Funtions

void menu();
int resultMenu();
Move *createMove(char right, char left, char up, char down);
int resultChoicPlayground(int withFriend);
void putBomb(Map *map, int x, int y, Player *player);
void Play(int i, int withFriend);
int movementsBeforeExplosion(int count);
char resulteBonus();
void checkWinMap1(); 
void checkWinMap2();
//void checkWinMap3();
int BombUp(Player *player);
int BombDown( Player *player);
int RangeYelow( Player *player);
int RangeBlue( Player *player);
int rangeRed( Player *player);
int invincibility(Player *player);
int checkBonusMap1(Player *player1, int x, int y);
int checkBonusMap2(Player *player1, int x, int y);
//int checkBonusMap3(Player *player1, int x, int y);
#endif