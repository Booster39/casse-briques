#include "Game.h"

Map *createMap(int nbrbomb, char **map, int x, int y)
{
    Map *Playground = malloc(sizeof(Map));
    Playground->map = map;
    Playground->x = x;
    Playground->y = y;
    return Playground;
}

Bomb *createBomb(int range2, int x2, int y2)
{
    Bomb *Bombe = malloc(sizeof(Bomb));
    Bombe->range = range2;
    Bombe->bombX = x2;
    Bombe->bombY = y2;
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
    player->x = x1;
    player->y = y1;
    return player;
}

void checkWinMap1()
{
    // si -5 == 0winner
    // si -2 == G gagne
    // si -1 == P gagne
    int compteur = 0;

    for (int i = 2; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (map1[i][j] == 'g')
            {
                compteur += 3;
            }
            if (map1[i][j] == 'p')
            {
                compteur += 2;
            }
            if (map1[i][j] == '*')
            {
                compteur += 4;
            }
            if (map1[i][j] == "#")
            {
                compteur += 8;
            }
        }
    }

    if (compteur == 3)
    {
        printf("\n  PLAYER g WIN!!!! \n");
        exit(0);
    }
    if (compteur == 2)
    {
        printf("\n PLAYER p WIN !!!! \n");
        exit(0);
    }
    else
    {
        printf("");
    }
}
void checkWinMap2()
{
    // si -5 == 0winner
    // si -2 == G gagne
    // si -1 == P gagne
    int compteur = 0;

    for (int i = 2; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (map2[i][j] == 'g')
            {
                compteur += 3;
            }
            if (map2[i][j] == "#")
            {
                compteur += 1;
            }
            if (map2[i][j] == 'p')
            {
                compteur += 2;
            }
            if (map2[i][j] == '*')
            {
                compteur += 2;
            }
        }
    }
    if (compteur == 3)
    {
        printf("\n  PLAYER g WIN!!!! \n");
        exit(0);
    }
    if (compteur == 2)
    {
        printf("\n PLAYER p WIN !!!! \n");
        printf("compteur = %d", compteur);
        exit(0);
    }
    else
    {
        printf("");
    }
}
void menu()
{
    printf("Menu :\n\n");
    printf("[1] Play alone :\n");
    printf("[2] Play with a friend :\n");
    printf("[3] Quit : \n\n");
    printf("Enter your choice :\n\n");
}

void choicPlayground()
{
    printf("\n\nChoose your PlayGround :\n\n");
    int i = 0;
    int j = 0;
    printf("    Map 1 \n");
    for (i = 2; i < 7; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf("%c ", map1[i][j]);
        }
        printf("\n");
        j = 0;
    }
    printf("\n");
    printf("________________________\n");
    printf("\n");
    printf("    Map 2 \n");

    for (i = 2; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", map2[i][j]);
        }
        printf("\n");
        j = 0;
    }
    printf("\n");
    printf("________________________\n");
    printf("\n");
    printf("    Map 3 \n");

    for (i = 2; i < 14; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%c ", map3[i][j]);
        }
        printf("\n");
        j = 0;
    }
    printf("\nEnter your choice : 1 or 2 or 3 for exit\n\n");
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
        system("clear");
        printf("Game Mode : Normal\n");
        choicPlayground();
        break;
    }
    case 2:
    {
        printf("Play with a friend : ");
        choicPlayground();
        break;
    }
    case 3:
    {
        printf("Quit : ");
        exit(0);
        break;
    }
    default:
        printf("Incorrect Number : \n");
        menu();
    }
    return c;
}

Map *getMap(int i)
{
    Map *map11 = createMap(1, map1, 7, 9);
    Map *map22 = createMap(1, map2, 10, 5);
    if (i == 1)
    {
        return map11;
    }
    if (i == 2)
    {
        return map22;
    }

    return NULL;
}

int resultChoicPlayground(int withFriend)
{
    int number;
    printf("Enter your choice : 1 or 2 or 3 for exit\n\n");
    scanf("%d", &number);

    int c = number;
    switch (c)
    {
    case 1:
    {

        printf("You choosed MAP %d:\n", c);
        Play(c, withFriend);
        break;
    }
    case 2:
    {

        printf("You choosed MAP %d:\n", c);
        Play(c, withFriend);
        break;
    }
    case 3:
    {
        printf("You choosed MAP %d:\n", c);
        Play(c, withFriend);
        break;
    }
    default:
        printf("Incorrect number : %d\n");
    }
    return c;
}

int checkBonusMap3(Player *player1, int x, int y)
{
    if (map3[x][y] == 'U')
        BombUp(player1);
    if (map3[x][y] == 'D')
        BombDown(player1);
    if (map3[x][y] == 'J')
        RangeYelow(player1);
    if (map3[x][y] == 'B')
        RangeBlue(player1);
    if (map3[x][y] == 'R')
        rangeRed(player1);
    if (map3[x][y] == 'I')
        invincibility(player1);
}

int checkBonusMap2(Player *player1, int x, int y)
{
    if (map2[x][y] == 'U')
        BombUp(player1);
    if (map2[x][y] == 'D')
        BombDown(player1);
    if (map2[x][y] == 'J')
        RangeYelow(player1);
    if (map2[x][y] == 'B')
        RangeBlue(player1);
    if (map2[x][y] == 'R')
        rangeRed(player1);
    if (map2[x][y] == 'I')
        invincibility(player1);
}

int checkBonusMap1(Player *player1, int x, int y)
{
    if (map1[x][y] == 'U')
        BombUp(player1);
    if (map1[x][y] == 'D')
        BombDown(player1);
    if (map1[x][y] == 'J')
        RangeYelow(player1);
    if (map1[x][y] == 'B')
        RangeBlue(player1);
    if (map1[x][y] == 'R')
        rangeRed(player1);
    if (map1[x][y] == 'I')
        invincibility(player1);
}

void playInMap1(Player *player1, char scan, Move *Move, char var, char bomb, char touch, int count)
{
    if (scan == touch && player1->nbrBombe != 0)
    {
        map1[player1->x][player1->y] = bomb;
        player1->bomb->bombX = player1->x;
        player1->bomb->bombY = player1->y;
        player1->nbrBombe--;
    }
    if (player1->nbrBombe == 0)
        printf("\n Plus aucune bombes restantes le joueur %c\n", var);
    if (count == 0 && map1[player1->bomb->bombX][player1->bomb->bombY] == bomb)
    {
        int i = 1;
        map1[player1->bomb->bombX][player1->bomb->bombY] = '-';

        if (map1[player1->bomb->bombX][player1->bomb->bombY + i] == 'p' || map1[player1->bomb->bombX][player1->bomb->bombY + i] == 'g')
            map1[player1->bomb->bombX][player1->bomb->bombY + i] = '-';
        if (map1[player1->bomb->bombX][player1->bomb->bombY + i] != 'x' &&
            map1[player1->bomb->bombX][player1->bomb->bombY + i] != '-' &&
            map1[player1->bomb->bombX][player1->bomb->bombY + i] != 'U' &&
            map1[player1->bomb->bombX][player1->bomb->bombY + i] != 'D' &&
            map1[player1->bomb->bombX][player1->bomb->bombY + i] != 'J' &&
            map1[player1->bomb->bombX][player1->bomb->bombY + i] != 'B' &&
            map1[player1->bomb->bombX][player1->bomb->bombY + i] != 'R' &&
            map1[player1->bomb->bombX][player1->bomb->bombY + i] != 'I')
            map1[player1->bomb->bombX][player1->bomb->bombY + i] = resulteBonus();

        if (map1[player1->bomb->bombX][player1->bomb->bombY - i] == 'p' || map1[player1->bomb->bombX][player1->bomb->bombY - i] == 'g')
            map1[player1->bomb->bombX][player1->bomb->bombY - i] = '-';
        if (map1[player1->bomb->bombX][player1->bomb->bombY - i] != 'x' &&
            map1[player1->bomb->bombX][player1->bomb->bombY - i] != '-' &&
            map1[player1->bomb->bombX][player1->bomb->bombY - i] != 'U' &&
            map1[player1->bomb->bombX][player1->bomb->bombY - i] != 'D' &&
            map1[player1->bomb->bombX][player1->bomb->bombY - i] != 'J' &&
            map1[player1->bomb->bombX][player1->bomb->bombY - i] != 'B' &&
            map1[player1->bomb->bombX][player1->bomb->bombY - i] != 'R' &&
            map1[player1->bomb->bombX][player1->bomb->bombY - i] != 'I')
            map1[player1->bomb->bombX][player1->bomb->bombY - i] = resulteBonus();

        if (map1[player1->bomb->bombX + i][player1->bomb->bombY] == 'p' || map1[player1->bomb->bombX + i][player1->bomb->bombY] == 'g')
            map1[player1->bomb->bombX + i][player1->bomb->bombY] = '-';
        if (map1[player1->bomb->bombX + i][player1->bomb->bombY] != 'x' &&
            map1[player1->bomb->bombX + i][player1->bomb->bombY] != '-' &&
            map1[player1->bomb->bombX + i][player1->bomb->bombY] != 'U' &&
            map1[player1->bomb->bombX + i][player1->bomb->bombY] != 'D' &&
            map1[player1->bomb->bombX + i][player1->bomb->bombY] != 'J' &&
            map1[player1->bomb->bombX + i][player1->bomb->bombY] != 'B' &&
            map1[player1->bomb->bombX + i][player1->bomb->bombY] != 'R' &&
            map1[player1->bomb->bombX + i][player1->bomb->bombY] != 'I')
            map1[player1->bomb->bombX + i][player1->bomb->bombY] = resulteBonus();

        if (map1[player1->bomb->bombX - i][player1->bomb->bombY] == 'p' || map1[player1->bomb->bombX - i][player1->bomb->bombY + 1] == 'g')
            map1[player1->bomb->bombX - i][player1->bomb->bombY] = '-';
        if (map1[player1->bomb->bombX - i][player1->bomb->bombY] != 'x' &&
            map1[player1->bomb->bombX - i][player1->bomb->bombY] != '-' &&
            map1[player1->bomb->bombX - i][player1->bomb->bombY] != 'U' &&
            map1[player1->bomb->bombX - i][player1->bomb->bombY] != 'D' &&
            map1[player1->bomb->bombX - i][player1->bomb->bombY] != 'J' &&
            map1[player1->bomb->bombX - i][player1->bomb->bombY] != 'B' &&
            map1[player1->bomb->bombX - i][player1->bomb->bombY] != 'R' &&
            map1[player1->bomb->bombX - i][player1->bomb->bombY] != 'I')
            map1[player1->bomb->bombX - i][player1->bomb->bombY] = resulteBonus();
    }

    if (scan == Move->right && map1[player1->x][player1->y + 1] != 'm' && map1[player1->x][player1->y + 1] != 'x')
    {
        checkBonusMap1(player1, player1->x, player1->y + 1);
        if (map1[player1->x][player1->y] != bomb)
            map1[player1->x][player1->y] = '-';
        player1->y++;
        map1[player1->x][player1->y] = var;
    }

    if (scan == Move->left && map1[player1->x][player1->y - 1] != 'm' && map1[player1->x][player1->y - 1] != 'x')
    {
        checkBonusMap1(player1, player1->x, player1->y - 1);
        if (map1[player1->x][player1->y] != bomb)
            map1[player1->x][player1->y] = '-';
        player1->y--;
        map1[player1->x][player1->y] = var;
    }
    if (scan == Move->up && map1[player1->x - 1][player1->y] != 'm' && map1[player1->x - 1][player1->y] != 'x')
    {
        checkBonusMap1(player1, player1->x - 1, player1->y);
        if (map1[player1->x][player1->y] != bomb)
            map1[player1->x][player1->y] = '-';
        player1->x--;
        map1[player1->x][player1->y] = var;
    }

    if (scan == Move->down && map1[player1->x + 1][player1->y] != 'm' && map1[player1->x + 1][player1->y] != 'x')
    {
        checkBonusMap1(player1, player1->x + 1, player1->y);
        if (map1[player1->x][player1->y] != bomb)
            map1[player1->x][player1->y] = '-';
        player1->x++;
        map1[player1->x][player1->y] = var;
    }
}

void playInMap2(Player *player1, char scan, Move *Move, char var, char bomb, char touch, int count)
{
    if (scan == touch && player1->nbrBombe != 0)
    {
        map2[player1->x][player1->y] = bomb;
        player1->bomb->bombX = player1->x;
        player1->bomb->bombY = player1->y;
        player1->nbrBombe--;
    }
    if (player1->nbrBombe == 0)
        printf("\n Plus aucune bombes restantes le joueur %c\n", var);

    if (count == 0 && map2[player1->bomb->bombX][player1->bomb->bombY] == bomb)
    {
        int i = 1;
        map2[player1->bomb->bombX][player1->bomb->bombY] = '-';

        if (map2[player1->bomb->bombX][player1->bomb->bombY + i] == 'p' || map2[player1->bomb->bombX][player1->bomb->bombY + i] == 'g')
            map2[player1->bomb->bombX][player1->bomb->bombY + i] = '-';
        if (map2[player1->bomb->bombX][player1->bomb->bombY + i] != 'x' &&
            map2[player1->bomb->bombX][player1->bomb->bombY + i] != '-' &&
            map2[player1->bomb->bombX][player1->bomb->bombY + i] != 'U' &&
            map2[player1->bomb->bombX][player1->bomb->bombY + i] != 'D' &&
            map2[player1->bomb->bombX][player1->bomb->bombY + i] != 'J' &&
            map2[player1->bomb->bombX][player1->bomb->bombY + i] != 'B' &&
            map2[player1->bomb->bombX][player1->bomb->bombY + i] != 'R' &&
            map2[player1->bomb->bombX][player1->bomb->bombY + i] != 'I')
            map2[player1->bomb->bombX][player1->bomb->bombY + i] = resulteBonus();

        if (map2[player1->bomb->bombX][player1->bomb->bombY - i] == 'p' || map2[player1->bomb->bombX][player1->bomb->bombY - i] == 'g')
            map2[player1->bomb->bombX][player1->bomb->bombY - i] = '-';
        if (map2[player1->bomb->bombX][player1->bomb->bombY - i] != 'x' &&
            map2[player1->bomb->bombX][player1->bomb->bombY - i] != '-' &&
            map2[player1->bomb->bombX][player1->bomb->bombY - i] != 'U' &&
            map2[player1->bomb->bombX][player1->bomb->bombY - i] != 'D' &&
            map2[player1->bomb->bombX][player1->bomb->bombY - i] != 'J' &&
            map2[player1->bomb->bombX][player1->bomb->bombY - i] != 'B' &&
            map2[player1->bomb->bombX][player1->bomb->bombY - i] != 'R' &&
            map2[player1->bomb->bombX][player1->bomb->bombY - i] != 'I')
            map2[player1->bomb->bombX][player1->bomb->bombY - i] = resulteBonus();

        if (map2[player1->bomb->bombX + i][player1->bomb->bombY] == 'p' || map2[player1->bomb->bombX + i][player1->bomb->bombY] == 'g')
            map2[player1->bomb->bombX + i][player1->bomb->bombY] = '-';
        if (map2[player1->bomb->bombX + i][player1->bomb->bombY] != 'x' &&
            map2[player1->bomb->bombX + i][player1->bomb->bombY] != '-' &&
            map2[player1->bomb->bombX + i][player1->bomb->bombY] != 'U' &&
            map2[player1->bomb->bombX + i][player1->bomb->bombY] != 'D' &&
            map2[player1->bomb->bombX + i][player1->bomb->bombY] != 'J' &&
            map2[player1->bomb->bombX + i][player1->bomb->bombY] != 'B' &&
            map2[player1->bomb->bombX + i][player1->bomb->bombY] != 'R' &&
            map2[player1->bomb->bombX + i][player1->bomb->bombY] != 'I')
            map2[player1->bomb->bombX + i][player1->bomb->bombY] = resulteBonus();

        if (map2[player1->bomb->bombX - i][player1->bomb->bombY] == 'p' || map2[player1->bomb->bombX - i][player1->bomb->bombY] == 'g')
            map2[player1->bomb->bombX - i][player1->bomb->bombY] = '-';
        if (map2[player1->bomb->bombX - i][player1->bomb->bombY] != 'x' &&
            map2[player1->bomb->bombX - i][player1->bomb->bombY] != '-' &&
            map2[player1->bomb->bombX - i][player1->bomb->bombY] != 'U' &&
            map2[player1->bomb->bombX - i][player1->bomb->bombY] != 'D' &&
            map2[player1->bomb->bombX - i][player1->bomb->bombY] != 'J' &&
            map2[player1->bomb->bombX - i][player1->bomb->bombY] != 'B' &&
            map2[player1->bomb->bombX - i][player1->bomb->bombY] != 'R' &&
            map2[player1->bomb->bombX - i][player1->bomb->bombY] != 'I')
            map2[player1->bomb->bombX - i][player1->bomb->bombY] = resulteBonus();
    }

    if (scan == Move->right && map2[player1->x][player1->y + 1] != 'm' && map2[player1->x][player1->y + 1] != 'x')
    {
        checkBonusMap2(player1, player1->x, player1->y + 1);
        if (map2[player1->x][player1->y] != bomb)
            map2[player1->x][player1->y] = '-';
        player1->y++;
        map2[player1->x][player1->y] = var;
    }

    if (scan == Move->left && map2[player1->x][player1->y - 1] != 'm' && map2[player1->x][player1->y - 1] != 'x')
    {
        checkBonusMap2(player1, player1->x, player1->y - 1);
        if (map2[player1->x][player1->y] != bomb)
            map2[player1->x][player1->y] = '-';
        player1->y--;
        map2[player1->x][player1->y] = var;
    }

    if (scan == Move->left && player1->x == 4 && player1->y == 1)
    {
        checkBonusMap2(player1, player1->x, player1->y - 1);
        if (map2[player1->x][player1->y] != bomb)
            map2[player1->x][player1->y] = '-';
        player1->y--;
        map2[player1->x][player1->y] = var;
    }
    if (scan == Move->up && map2[player1->x - 1][player1->y] != 'm' && map2[player1->x - 1][player1->y] != 'x')
    {
        checkBonusMap2(player1, player1->x - 1, player1->y);
        if (map2[player1->x][player1->y] != bomb)
            map2[player1->x][player1->y] = '-';
        player1->x--;
        map2[player1->x][player1->y] = var;
    }

    if (scan == Move->down && map2[player1->x + 1][player1->y] != 'm' && map2[player1->x + 1][player1->y] != 'x')
    {
        checkBonusMap2(player1, player1->x + 1, player1->y);
        if (map2[player1->x][player1->y] != bomb)
            map2[player1->x][player1->y] = '-';
        player1->x++;
        map2[player1->x][player1->y] = var;
    }
}

void playInMap3(Player *player1, char scan, Move *Move, char var, char bomb, char touch, int count)
{
    if (scan == touch && player1->nbrBombe != 0)
    {
        map3[player1->x][player1->y] = bomb;
        player1->bomb->bombX = player1->x;
        player1->bomb->bombY = player1->y;
        player1->nbrBombe--;
    }
    if (player1->nbrBombe == 0)
        printf("\n player %c have 0 bomb\n", var);

    if (count == 0 && map3[player1->bomb->bombX][player1->bomb->bombY] == bomb)
    {
        int i = 1;
        map3[player1->bomb->bombX][player1->bomb->bombY] = '-';

        if (map3[player1->bomb->bombX][player1->bomb->bombY + i] == 'p' || map3[player1->bomb->bombX][player1->bomb->bombY + i] == 'g' || map3[player1->bomb->bombX][player1->bomb->bombY + i] == 'y' || map3[player1->bomb->bombX][player1->bomb->bombY + i] == 'b')
            map3[player1->bomb->bombX][player1->bomb->bombY + i] = '-';

        if (map3[player1->bomb->bombX][player1->bomb->bombY + i] != 'x' &&
            map3[player1->bomb->bombX][player1->bomb->bombY + i] != '-' &&
            map3[player1->bomb->bombX][player1->bomb->bombY + i] != 'U' &&
            map3[player1->bomb->bombX][player1->bomb->bombY + i] != 'D' &&
            map3[player1->bomb->bombX][player1->bomb->bombY + i] != 'J' &&
            map3[player1->bomb->bombX][player1->bomb->bombY + i] != 'B' &&
            map3[player1->bomb->bombX][player1->bomb->bombY + i] != 'R' &&
            map3[player1->bomb->bombX][player1->bomb->bombY + i] != 'I')
            map3[player1->bomb->bombX][player1->bomb->bombY + i] = resulteBonus();

        if (map3[player1->bomb->bombX][player1->bomb->bombY - i] == 'p' || map3[player1->bomb->bombX][player1->bomb->bombY - i] == 'g' || map3[player1->bomb->bombX][player1->bomb->bombY - i] == 'y' || map3[player1->bomb->bombX][player1->bomb->bombY - i] == 'b')
            map3[player1->bomb->bombX][player1->bomb->bombY - i] = '-';
        if (map3[player1->bomb->bombX][player1->bomb->bombY - i] != 'x' &&
            map3[player1->bomb->bombX][player1->bomb->bombY - i] != '-' &&
            map3[player1->bomb->bombX][player1->bomb->bombY - i] != 'U' &&
            map3[player1->bomb->bombX][player1->bomb->bombY - i] != 'D' &&
            map3[player1->bomb->bombX][player1->bomb->bombY - i] != 'J' &&
            map3[player1->bomb->bombX][player1->bomb->bombY - i] != 'B' &&
            map3[player1->bomb->bombX][player1->bomb->bombY - i] != 'R' &&
            map3[player1->bomb->bombX][player1->bomb->bombY - i] != 'I')
            map3[player1->bomb->bombX][player1->bomb->bombY - i] = resulteBonus();

        if (map3[player1->bomb->bombX + i][player1->bomb->bombY] == 'p' || map3[player1->bomb->bombX + i][player1->bomb->bombY] == 'g' || map3[player1->bomb->bombX][player1->bomb->bombY + i] == 'y' || map3[player1->bomb->bombX][player1->bomb->bombY + i] == 'b')
            map3[player1->bomb->bombX + i][player1->bomb->bombY] = '-';
        if (map3[player1->bomb->bombX + i][player1->bomb->bombY] != 'x' &&
            map3[player1->bomb->bombX + i][player1->bomb->bombY] != '-' &&
            map3[player1->bomb->bombX + i][player1->bomb->bombY] != 'U' &&
            map3[player1->bomb->bombX + i][player1->bomb->bombY] != 'D' &&
            map3[player1->bomb->bombX + i][player1->bomb->bombY] != 'J' &&
            map3[player1->bomb->bombX + i][player1->bomb->bombY] != 'B' &&
            map3[player1->bomb->bombX + i][player1->bomb->bombY] != 'R' &&
            map3[player1->bomb->bombX + i][player1->bomb->bombY] != 'I')
            map3[player1->bomb->bombX + i][player1->bomb->bombY] = resulteBonus();

        if (map3[player1->bomb->bombX - i][player1->bomb->bombY] == 'p' || map3[player1->bomb->bombX - i][player1->bomb->bombY] == 'g' || map3[player1->bomb->bombX][player1->bomb->bombY + i] == 'y' || map3[player1->bomb->bombX][player1->bomb->bombY + i] == 'b')
            map3[player1->bomb->bombX - i][player1->bomb->bombY] = '-';
        if (map3[player1->bomb->bombX - i][player1->bomb->bombY] != 'x' &&
            map3[player1->bomb->bombX - i][player1->bomb->bombY] != '-' &&
            map3[player1->bomb->bombX - i][player1->bomb->bombY] != 'U' &&
            map3[player1->bomb->bombX - i][player1->bomb->bombY] != 'D' &&
            map3[player1->bomb->bombX - i][player1->bomb->bombY] != 'J' &&
            map3[player1->bomb->bombX - i][player1->bomb->bombY] != 'B' &&
            map3[player1->bomb->bombX - i][player1->bomb->bombY] != 'R' &&
            map3[player1->bomb->bombX - i][player1->bomb->bombY] != 'I')
            map3[player1->bomb->bombX - i][player1->bomb->bombY] = resulteBonus();
    }

    if (scan == Move->right && map3[player1->x][player1->y + 1] != 'm' && map3[player1->x][player1->y + 1] != 'x')
    {
        checkBonusMap3(player1, player1->x, player1->y + 1);
        if (map3[player1->x][player1->y] != bomb)
            map3[player1->x][player1->y] = '-';
        player1->y++;
        map3[player1->x][player1->y] = var;
    }

    if (scan == Move->left && map3[player1->x][player1->y - 1] != 'm' && map3[player1->x][player1->y - 1] != 'x')
    {
        checkBonusMap3(player1, player1->x, player1->y - 1);
        if (map3[player1->x][player1->y] != bomb)
            map3[player1->x][player1->y] = '-';
        player1->y--;
        map3[player1->x][player1->y] = var;
    }

    if (scan == Move->left && player1->x == 4 && player1->y == 1)
    {
        checkBonusMap3(player1, player1->x, player1->y - 1);
        if (map3[player1->x][player1->y] != bomb)
            map3[player1->x][player1->y] = '-';
        player1->y--;
        map3[player1->x][player1->y] = var;
    }
    if (scan == Move->up && map3[player1->x - 1][player1->y] != 'm' && map3[player1->x - 1][player1->y] != 'x')
    {
        checkBonusMap3(player1, player1->x - 1, player1->y);
        if (map3[player1->x][player1->y] != bomb)
            map3[player1->x][player1->y] = '-';
        player1->x--;
        map3[player1->x][player1->y] = var;
    }

    if (scan == Move->down && map3[player1->x + 1][player1->y] != 'm' && map3[player1->x + 1][player1->y] != 'x')
    {
        checkBonusMap3(player1, player1->x + 1, player1->y);
        if (map3[player1->x][player1->y] != bomb)
            map3[player1->x][player1->y] = '-';
        player1->x++;
        map3[player1->x][player1->y] = var;
    }
}

void Play(int map, int withFriend)
{
    Move *Move = createMove('d', 'q', 'z', 's');
    Player *player1 = createPlayer(1, 3, 3, 1, createBomb(1, 5, 3));
    Player *player2 = createPlayer(1, 3, 5, 3, createBomb(1, 3, 1));

    Player *player11 = createPlayer(4, 3, 3, 1, createBomb(1, 3, 1));
    Player *player21 = createPlayer(4, 3, 12, 8, createBomb(1, 4, 1));
    Player *player31 = createPlayer(4, 3, 3, 8, createBomb(1, 5, 1));
    Player *player41 = createPlayer(4, 3, 12, 1, createBomb(1, 6, 1));

    Player *playerbot = createPlayer(1, 3, 5, 3, createBomb(1, 3, 1));

    int i = 0;
    int j = 0;
    char scan;
    int toYou = 1;
    int countb = 0;
    int counts = 0;
    int countd = 0;
    int countf = 0;

    if (withFriend == 1)
    {
        map1[5][3] = '?';
        map2[5][3] = '?';
        map3[12][8] = '?';
        map3[3][8] = '-';
        map3[3][12] = '-';
    }

    printf("\nEnter your move : ");
    scanf("%c", &scan);
    printf("\n\n");

    while (scan != 'f')
    {

        if (scan == 'b')
            countb = 5;
        if (scan == 'r')
            counts = 5;
        if (scan == 't')
            countd = 5;
        if (scan == 'n')
            countf = 5;

        if (withFriend == 1)
        {
            if (map == 1)
                playInMap1(player1, scan, Move, 'p', '*', 'b', countb);
            if(map == 2)
                playInMap2(player1, scan, Move, 'p', '*', 'b', countb);
            if (map == 3)
                playInMap3(player1, scan, Move, 'p', '*', 'b', countb);
        }
        if (map == 1 && withFriend == 2)
        {
            if ((toYou % 2) == 0)
            {
                playInMap1(player1, scan, Move, 'p', '*', 'b', countb);
            }
            else if ((toYou % 2) == 1)
            {
                playInMap1(player2, scan, Move, 'g', '#', 'r', counts);
            }
        }
        printf("\n %d Mouvements avant l'explosion de la Bombe 1 !\n", countb);
        printf("\n %d Mouvements avant l'explosion de la Bombe 2 !\n", counts);
        if (map == 3 && withFriend == 2)
        {
            printf("\n %d Mouvements avant l'explosion de la Bombe 3 !\n", countd);
            printf("\n %d Mouvements avant l'explosion de la Bombe 4 !", countf);
        }
        if (map == 2 && withFriend == 2)
        {
            if ((toYou % 2) == 0)
            {
                playInMap2(player1, scan, Move, 'p', '*', 'b', countb);
            }
            else if ((toYou % 2) == 1)
            {
                playInMap2(player2, scan, Move, 'g', '#', 'r', counts);
            }
        }
        if (map == 3 && withFriend == 2)
        {
            toYou == 1;
            if ((toYou % 4) == 1)
            {
                playInMap3(player11, scan, Move, 'p', '*', 'b', countb);
            }
            else if ((toYou % 4) == 2)
            {
                playInMap3(player21, scan, Move, 'g', '#', 'r', counts);
            }
            else if ((toYou % 4) == 3)
            {
                playInMap3(player31, scan, Move, 'y', '!', 't', countd);
            }
            else if ((toYou % 4) == 0)
            {
                playInMap3(player41, scan, Move, 'b', '$', 'n', countf);
            }
        }

        for (i = 2; i < 7; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (map == 1)
                {
                    printf("%c ", map1[i][j]);
                }
            }
            printf("\n");
            j = 0;
        }

        for (i = 2; i < 10; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (map == 2)
                {
                    printf("%c ", map2[i][j]);
                }
            }
            printf("\n");
            j = 0;
        }
        for (i = 2; i < 14; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (map == 3)
                {
                    printf("%c ", map3[i][j]);
                }
            }
            printf("\n");
            j = 0;
        }
        if (map == 2 && withFriend == 2)
        {
            checkWinMap2();
        }
        else if (map == 1 && withFriend == 2)
        {
            checkWinMap1();
        }
        else if (map == 3 && withFriend == 2)
        {
            //checkWinMap3();
        }
        printf("\ntoYou = %d\n", toYou); // a sup
        printf("\nEnter your move : \n");
        scan = getchar();
        putchar(scan);
        if (scan == 'd')
        {
            toYou++;
            if (countb != 0)
                countb--;
            if (counts != 0)
                counts--;
        }
        if (scan == 'z')
        {
            toYou++;
            if (countb != 0)
                countb--;
            if (counts != 0)
                counts--;
        }
        if (scan == 's')
        {
            toYou++;
            if (countb != 0)
                countb--;
            if (counts != 0)
                counts--;
        }
        if (scan == 'q')
        {
            toYou++;
            if (countb != 0)
                countb--;
            if (counts != 0)
                counts--;
        }
        if (scan == 'r')
        {
            toYou++;
            if (countb != 0)
                countb--;
            if (counts != 0)
                counts--;
        }
        if (scan == 'b')
        {
            toYou++;
            if (countb != 0)
                countb--;
            if (counts != 0)
                counts--;
        }

        if (player1->x == 4 && player1->y == 8 && scan == Move->right)
        {
            map1[4][8] = '-';
            player1->y = 0;
            player1->x = 4;
            map1[player1->x][player1->y] = 'p';
        }
        if (player1->x == 4 && player1->y == 0 && scan == Move->left)
        {

            map1[player1->x][player1->y] = '-';
            player1->y = 9;
            player1->x = 4;
            map1[player1->x][player1->y] = 'p';
        }
        // checkWinMap1();
        // checkWinMap2();
    }
}

int main()
{

    menu();
    int withFriend = resultMenu();
    resultChoicPlayground(withFriend);
    int choiceOfMap = resultChoicPlayground(withFriend);
    Map *map = getMap(choiceOfMap);
    Play(choiceOfMap, withFriend);
    return 0;
}