#include "Game.h"

typedef struct Map
    {
        /* data */
        int nbBomb;
        char **map;

    }Map;


typedef struct Game
{
    
} Game;


typedef struct Move
{
    char right;
    char left;
    char up;
    char down;
} Move;

typedef struct{
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
    Bomb* bomb;
} Player;

Bomb *createBomb(int range2, int x2,int y2){
    Bomb* Bombe = malloc(sizeof(Bomb));
    Bombe->range = range2;
    Bombe->x = x2;
    Bombe->y = y2;
    return Bombe;
}

Player *createPlayer(int nbrBombe1, int vie1, int x1, int y1, Bomb * bomb1)
{
    Player* player= malloc(sizeof(Player));
    player->bomb = malloc(sizeof(Bomb));
    player->nbrBombe = nbrBombe1;
    player->vie = vie1;
    player->Player1PosX = x1;
    player->Player1PosY = y1;
    return player;
}

    char map1[7][9] = {
    {'2'},
    {'9', ' ', '5'},
    {'x','x','x','x','x','x','x','x','x'},
    {'x','p','-','m','m','m','x','m','x'},
    {'-','-','m','m','m','m','m','-','-'},
    {'x','m','x','m','m','m','-','g','x'},
    {'x','x','x','x','x','x','x','x','x'}
};
//4 - 0 // 4 - 8

    char map2[10][5] = {
    {'1'},
    {'5', ' ', '8'},
    {'x','x','x','x','x'},
    {'x','p','-','m','x'},
    {'x','m','x','m','x'},
    {'-','-','m','-','-'},
    {'-','-','x','m','-'},
    {'x','m','x','m','x'},
    {'x','m','x','m','x'},
    {'x','x','x','x','x'}
};
// 5 - 0 // 6 - 0 // 5 - 4 // 6 - 4 //

void menu(){
    printf("Menu\n\n");
    printf("[1] Jouer\n");
    printf("[2] Jouer avec un amis\n");
    printf("[3] Quitter\n");
    printf("Enter your choice:\n");
}

int resultMenu(){
    int number;
    scanf("%d", &number);
    int c = number;
    switch (c)
    {
    case 1:
    {

        printf("Jouer\n");
        Play();
        break;
        }
        case 2:
        {
            printf("Jouer avec un ami");
            break;
        }
        case 3:
        {
            printf("Quitter");
            break;
        }
        default:
            printf("Nombre incorrect\n");
        }
        return c;
}

void Play()
{
Map *Map = malloc(sizeof(Map));
    Player *Player = malloc(sizeof(Player));
    Move *Move = malloc(sizeof(Move));

    int i = 0;
    int j = 0;
    Move->right = 'd';
    Move->left = 'g';
    Move->up = 'h';
    Move->down = 'b';
    char scan;
//l
    Player->Player1PosX = 3;
    Player->Player1PosY = 1;

printf("Enter your move : ");
    scanf("%c", &scan);
printf("\n");

while (scan != 'z')
{

    if (scan == Move->right && map1[Player->Player1PosX][Player->Player1PosY + 1] != 'm' && map1[Player->Player1PosX][Player->Player1PosY + 1] != 'x')
    {
        map1[Player->Player1PosX][Player->Player1PosY] = '-';
        Player->Player1PosY++;
        map1[Player->Player1PosX][Player->Player1PosY] = 'p';
    }


    if (scan == Move->left && map1[Player->Player1PosX][Player->Player1PosY - 1] != 'm' && map1[Player->Player1PosX][Player->Player1PosY - 1] != 'x')
    {
        map1[Player->Player1PosX][Player->Player1PosY] = '-';
        Player->Player1PosY--;
        map1[Player->Player1PosX][Player->Player1PosY] = 'p';
    }

    if (scan == Move->left && Player->Player1PosX == 4 && Player->Player1PosY == 1) {
        map1[Player->Player1PosX][Player->Player1PosY] = '-';
        Player->Player1PosY--;
        map1[Player->Player1PosX][Player->Player1PosY] = 'p';
    }
    if (scan == Move->up && map1[Player->Player1PosX - 1][Player->Player1PosY] != 'm' && map1[Player->Player1PosX - 1][Player->Player1PosY] != 'x')
    {
        map1[Player->Player1PosX][Player->Player1PosY] = '-';
        Player->Player1PosX--;
        map1[Player->Player1PosX][Player->Player1PosY] = 'p';
    }

    if (scan == Move->down && map1[Player->Player1PosX + 1][Player->Player1PosY] != 'm' && map1[Player->Player1PosX + 1][Player->Player1PosY] != 'x')
    {
        map1[Player->Player1PosX][Player->Player1PosY] = '-';
        Player->Player1PosX++;
        map1[Player->Player1PosX][Player->Player1PosY] = 'p';
    }

    else if (scan == Move->left && Player->Player1PosX == 4 && Player->Player1PosY == 0)
    {
        map1[Player->Player1PosX][Player->Player1PosY] = '-';
        Player->Player1PosY = 8;
        Player->Player1PosX == 4;
        map1[Player->Player1PosX][Player->Player1PosY] = 'p';
    }

    else if (scan == Move->right && Player->Player1PosX == 4 && Player->Player1PosY == 8)
    {
        map1[Player->Player1PosX][Player->Player1PosY] = '-';
        Player->Player1PosY = 0;
        Player->Player1PosX == 4;
        map1[Player->Player1PosX][Player->Player1PosY] = 'p';
    }

    for (i = 0 /*2*/; i < 7; i++)
    {
       for (j = 0; j < 9; j++)
        {
            printf("%c ", map1[i][j]);
        }
        printf("\n");
        j = 0;
    }

    printf("Enter your move : ");
    scanf("%c", &scan);
} 
}

int main(int argc, char const *argv[])
{
    menu();
    resultMenu();
    return 0;
}