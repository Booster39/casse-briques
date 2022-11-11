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
    Bomb *bomb;
} Player;

// Int
char map1[7][9] = {
    {'2'},
    {'9', ' ', '5'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'p', '-', 'm', 'm', 'm', 'x', 'm', 'x'},
    {'-', '-', 'm', 'm', 'm', 'm', 'm', '-', '-'},
    {'x', 'm', '-', 'g', '-', '-', '-', '-', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}};
// 4 - 0 // 4 - 8

char map2[10][5] = {
    {'1'},
    {'5', ' ', '8'},
    {'x', 'x', 'x', 'x', 'x'},
    {'x', 'p', '-', 'm', 'x'},
    {'x', 'm', 'x', 'm', 'x'},
    {'-', '-', 'm', 'g', '-'},
    {'-', '-', 'x', '-', '-'},
    {'x', 'm', 'x', 'm', 'x'},
    {'x', 'm', 'x', 'm', 'x'},
    {'x', 'x', 'x', 'x', 'x'}};

//Funtions

void menu();
int resultMenu();
int resultChoicPlayground(int withFriend);
void putBomb(Map *map, int x, int y, Player *player);
void Play(int i, int withFriend);
int randomNum(int max);
int movementsBeforeExplosion(int count);
int BombUp( Player *player);
int BombDown( Player *player);
int RangeYelow( Player *player);
int RangeBlue( Player *player);
int rangeRed( Player *player);
#endif