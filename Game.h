#if !defined(MACRO)
#define MACRO
    #include <stdio.h>
    #include <stdlib.h>

//Structures

typedef struct Map
{
    /* data */
int dos;
int map2x;
int map1y;
int map2y;
    int nbBomb;
    char **map;
    int x;
    int y;

} Map;
typedef struct Move
{
    char right;
    char left;
    char up;
    char down;
} Move;

typedef struct
{
    int range;
    int x;
    int y;
} Bomb;

typedef struct Player
{
    int nbrBombe;
    int vie;
    int Player1PosX;
    int Player1PosY;
    Bomb *bomb;
} Player;

// Int
char map1[7][9] = {
    {'2'},
    {'9', ' ', '5'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'p', '-', 'm', 'm', 'm', 'x', 'm', 'x'},
    {'-', '-', 'm', 'm', 'm', 'm', 'm', '-', '-'},
    {'x', 'm', 'x', 'm', 'm', 'm', '-', 'g', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}};
// 4 - 0 // 4 - 8

char map2[10][5] = {
    {'1'},
    {'5', ' ', '8'},
    {'x', 'x', 'x', 'x', 'x'},
    {'x', 'p', '-', 'm', 'x'},
    {'x', 'm', 'x', 'm', 'x'},
    {'-', '-', 'm', '-', '-'},
    {'-', '-', 'x', 'm', '-'},
    {'x', 'm', 'x', 'm', 'x'},
    {'x', 'm', 'x', 'm', 'x'},
    {'x', 'x', 'x', 'x', 'x'}};

//Funtions

void menu();
int resultMenu();
int resultChoicPlayground();

void Play(int i);

#endif