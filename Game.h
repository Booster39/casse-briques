#if !defined(MACRO)
#define MACRO
    #include <stdio.h>
    #include <stdlib.h>

//Structures

typedef struct Player;
typedef struct Bomb;
typedef struct Move;
typedef struct Map;

// Tableaux

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