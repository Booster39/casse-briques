#if !defined(MACRO)
#define MACRO
    #include <stdio.h>
    #include <stdlib.h>

//Structures

typedef struct Player;
typedef struct Bomb;
typedef struct Move;
typedef struct Map;

//Funtions

void menu();
int resultMenu();
int resultChoicPlayground();

void Play(int i);

#endif