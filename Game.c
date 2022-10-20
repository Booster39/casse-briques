#include "Game.h"

typedef struct Map
{
    /* data */
    int nbBomb;
    char **map;

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

Map *createMap(int nbrbomb, char *map)
{
    Map *playground = malloc(sizeof(map));
    playground->map = malloc(sizeof(map));
    playground->nbBomb = nbrbomb;
    return playground;
}
Bomb *createBomb(int range2, int x2, int y2)
{
    Bomb *Bombe = malloc(sizeof(Bomb));
    Bombe->range = range2;
    Bombe->x = x2;
    Bombe->y = y2;
    return Bombe;
}
Move *createMove(char right, char left, char up, char down)
{
    Move *move = malloc(sizeof(Move));
    move->right = right;
    move->left = left;
    move->up = up;
    move->down = down;
    return move;
}
Player *createPlayer(int nbrBombe1, int vie1, int x1, int y1, Bomb *bomb1)
{
    Player *player = malloc(sizeof(Player));
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
// 5 - 0 // 6 - 0 // 5 - 4 // 6 - 4 //
// menu //
void menu()
{
    printf("Menu\n\n");
    printf("[1] Jouer\n");
    printf("[2] Jouer avec un amis\n");
    printf("[3] Quitter\n");
    printf("Enter your choice:\n");
}
void choicPlayground()
{
    printf("Choisirez votre terrain de jeux\n\n");
    int i=0;
    int j=0;
    printf(" Map 1 \n");
    for (i = 2; i < 7; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%c ", map1[i][j]);
        }
        printf("\n");
        j = 0;
    }
    printf(" Map 2 \n");
    for (i = 2; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", map2[i][j]);
        }
        printf("\n");
        j = 0;
    }
    printf("Enter votre choice:\n");
}

int resultMenu()
{
    int number;
    scanf("%d", &number);
    int c = number;
    switch (c)
    {
    case 1:
    {

        printf("Jouer\n");
        choicPlayground();
        break;
    }
    case 2:
    {
        printf("Jouer avec un ami");
        choicPlayground();
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
Map *getMap(int i)
{
    Map *map1 = createMap(1, map1);
    Map *map2 = createMap(1, map2);
    if (i == 1)
    {
        return map1;
    }
    if (i == 2)
    {
        return map2;
    }

    return NULL;
}

int resultChoicPlayground()
{
    int number;
    scanf("%d", &number);
    int c = number;
    switch (c)
    {
    case 1:
    {
        printf("Vous Avez choisie MAP1\n");
        getMap(c);
        Play(c);
        break;
    }
    case 2:
    {
        printf("Vous Avez choisie MAP2");
        getMap(c);
        Play(c);
        break;
    }
    default:
        printf("Nombre incorrect\n");
    }
    return c;
}


Player *getPlayer2(int i)
{
    Player *player1 = createPlayer(1, 1, 6, 7, NULL);
    Player *player2 = createPlayer(1, 1, 9, 3, NULL);
    if (i == 1)
    {
        return player1;
    }
    if (i == 2)
    {
        return player2;
    }

    return NULL;
}
void Play(int g)
{
    Move *Move = createMove('d', 'q', 'z', 's');
    Player *player1 = createPlayer(1, 3, 3, 1, createBomb(1, 3, 1));
    Player *player2 = getPlayer2(g);

    int i = 0;
    int j = 0;
    char scan;

    printf("Enter your move : ");
    scanf("%c", &scan);
    printf("\n");

    while (scan != 'f')
    {

        if(scan == Move->right && map1[player1->Player1PosX][player1->Player1PosY + 1] != 'm' && map1[player1->Player1PosX][player1->Player1PosY + 1] != 'x')
        {
            map1[player1->Player1PosX][player1->Player1PosY] = '-';
            player1->Player1PosY++;
            map1[player1->Player1PosX][player1->Player1PosY] = 'p';
        }

        if (scan == Move->left && map1[player1->Player1PosX][player1->Player1PosY - 1] != 'm' && map1[player1->Player1PosX][player1->Player1PosY - 1] != 'x')
        {
            map1[player1->Player1PosX][player1->Player1PosY] = '-';
            player1->Player1PosY--;
            map1[player1->Player1PosX][player1->Player1PosY] = 'p';
        }

        if (scan == Move->left && player1->Player1PosX == 4 && player1->Player1PosY == 1)
        {
            map1[player1->Player1PosX][player1->Player1PosY] = '-';
            player1->Player1PosY--;
            map1[player1->Player1PosX][player1->Player1PosY] = 'p';
        }
        if (scan == Move->up && map1[player1->Player1PosX - 1][player1->Player1PosY] != 'm' && map1[player1->Player1PosX - 1][player1->Player1PosY] != 'x')
        {
            map1[player1->Player1PosX][player1->Player1PosY] = '-';
            player1->Player1PosX--;
            map1[player1->Player1PosX][player1->Player1PosY] = 'p';
        }

        if (scan == Move->down && map1[player1->Player1PosX + 1][player1->Player1PosY] != 'm' && map1[player1->Player1PosX + 1][player1->Player1PosY] != 'x')
        {
            map1[player1->Player1PosX][player1->Player1PosY] = '-';
            player1->Player1PosX++;
            map1[player1->Player1PosX][player1->Player1PosY] = 'p';
        }

        else if (scan == Move->left && player1->Player1PosX == 4 && player1->Player1PosY == 0)
        {
            map1[player1->Player1PosX][player1->Player1PosY] = '-';
            player1->Player1PosY = 8;
            player1->Player1PosX == 4;
            map1[player1->Player1PosX][player1->Player1PosY] = 'p';
        }

        else if (scan == Move->right && player1->Player1PosX == 4 && player1->Player1PosY == 8)
        {
            map1[player1->Player1PosX][player1->Player1PosY] = '-';
            player1->Player1PosY = 0;
            player1->Player1PosX == 4;
            map1[player1->Player1PosX][player1->Player1PosY] = 'p';
        }

        for (i = 2; i < 7; i++)
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
    resultChoicPlayground();
    int i = resultChoicPlayground();
    Map *map = getMap(i);
    Play(i);
    return 0;
}