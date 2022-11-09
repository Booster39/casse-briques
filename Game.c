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
    player->x = x1;
    player->y = y1;
    return player;
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
    int i=0;
    int j=0;
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
    printf("\nEnter your choice : 1 or 2 \n\n");
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
    printf("Map à choisir : ");
    scanf("%d", &number);
    int c = number;
    switch (c)
    {
    case 1:
    {
       
        printf("You choosed MAP1 %d:\n", c);
        getMap(c);
        Play(c, withFriend);
        break;
    }
    case 2:
    {
        
        printf("You choosed MAP2 %d:\n", c);
        getMap(c);
        Play(c, withFriend);
        break;
    }
    default:
        printf("Incorrect number :\n");
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

int movementsBeforeExplosion(int count)
{
    count--;
    return count;
}

void playInMap1(Player *player1, char scan, Move *Move, char var, char bomb, char touch)
{
        if (scan == touch)
            map1[player1->x][player1->y] = bomb;

        if(scan == Move->right && map1[player1->x][player1->y + 1] != 'm' && map1[player1->x][player1->y + 1] != 'x')
        {
            if (map1[player1->x][player1->y] != bomb)
                map1[player1->x][player1->y] = '-';
            player1->y++;
            map1[player1->x][player1->y] = var;
        }

        if (scan == Move->left && map1[player1->x][player1->y - 1] != 'm' && map1[player1->x][player1->y - 1] != 'x')
        {
            if (map1[player1->x][player1->y] != bomb)
                map1[player1->x][player1->y] = '-';
            player1->y--;
            map1[player1->x][player1->y] = var;
        }
        if (scan == Move->up && map1[player1->x - 1][player1->y] != 'm' && map1[player1->x - 1][player1->y] != 'x')
        {
            if (map1[player1->x][player1->y] != bomb)
                map1[player1->x][player1->y] = '-';
            player1->x--;
            map1[player1->x][player1->y] = var;
        }

        if (scan == Move->down && map1[player1->x + 1][player1->y] != 'm' && map1[player1->x + 1][player1->y] != 'x')
        {
            if (map1[player1->x][player1->y] != bomb)
                map1[player1->x][player1->y] = '-';
            player1->x++;
            map1[player1->x][player1->y] = var;
        }
}

void playInMap2(Player *player1, char scan, Move* Move, char var, char bomb, char touch)
{
            if (scan == touch)
                map2[player1->x][player1->y] = bomb;
            
            if(scan == Move->right && map2[player1->x][player1->y + 1] != 'm' && map2[player1->x][player1->y + 1] != 'x')
        {
            if (map2[player1->x][player1->y] != bomb)
                map2[player1->x][player1->y] = '-';
            player1->y++;
            map2[player1->x][player1->y] = var;
        }

        if (scan == Move->left && map2[player1->x][player1->y - 1] != 'm' && map2[player1->x][player1->y - 1] != 'x')
        {
            if (map2[player1->x][player1->y] != bomb)
                map2[player1->x][player1->y] = '-';
            player1->y--;
            map2[player1->x][player1->y] = var;
        }

        if (scan == Move->left && player1->x == 4 && player1->y == 1)
        {   
            if (map2[player1->x][player1->y] != bomb)
                map2[player1->x][player1->y] = '-';
            player1->y--;
            map2[player1->x][player1->y] = var;
        }
        if (scan == Move->up && map2[player1->x - 1][player1->y] != 'm' && map2[player1->x - 1][player1->y] != 'x')
        {
            if (map2[player1->x][player1->y] != bomb)
                map2[player1->x][player1->y] = '-';
            player1->x--;
            map2[player1->x][player1->y] = var;
        }

        if (scan == Move->down && map2[player1->x + 1][player1->y] != 'm' && map2[player1->x + 1][player1->y] != 'x')
        {
            if (map2[player1->x][player1->y] != bomb)
                map2[player1->x][player1->y] = '-';
            player1->x++;
            map2[player1->x][player1->y] = var;
        }
}

void Play(int map, int withFriend)
{
    Move *Move = createMove('d', 'q', 'z', 's');
    Player *player1 = createPlayer(1, 3, 3, 1, createBomb(1, 5, 3));
    Player *player2 = createPlayer(1, 3, 5, 3, createBomb(1, 3, 1));

    int i = 0;
    int j = 0;
    char scan;
    int toYou = 1;

    if (withFriend == 1)
    {
        map1[5][3] = '-';
        map2[5][3] = '-';
    }

    printf("\nEnter your move : ");
    scanf("%c", &scan);
    printf("\n\n");

    while (scan != 'f')
    {
        if (withFriend == 1)
        {
            if (map == 1)
                playInMap1(player1, scan, Move, 'p', '*', 'b');
            else
                playInMap2(player1, scan, Move, 'p', '*', 'b');

        }
        if (map == 1  && withFriend == 2)
        {
            if ((toYou % 2) == 0)
            {
                playInMap1(player1, scan, Move, 'p', '*', 'b');
            }
            else if ((toYou % 2) == 1)
            {
                playInMap1(player2, scan, Move, 'g', '#', 'b');
            }
        }

        if (map == 2  && withFriend == 2)
        {
            if ((toYou % 2) == 0)
            {
                playInMap2(player1, scan, Move, 'p', '*', 'b');
            }
            else if ((toYou % 2) == 1)
            {
                playInMap2(player2, scan, Move, 'g', '#', 'b');
            }
        }

        for (i = 2; i < 7; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (map == 1)
                printf("%c ", map1[i][j]);
                
            }
            printf("\n");
            j = 0;
        }

        for (i = 2; i < 10; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (map == 2)
                printf("%c ", map2[i][j]);
            }
            printf("\n");
            j = 0;
        }
        printf("\ntoYou = %d\n", toYou);
        printf("\nEnter your move : \n");
        scan = getchar();
        putchar(scan);
        if (scan == 'd')
            toYou++;
        if (scan == 'z')
            toYou++;
        if (scan == 's')
            toYou++;
        if (scan == 'q')
            toYou++;
        if (scan == 'b')
            toYou++;
        random1to21();
    
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
    }
}

int main(int argc, char const *argv[])
{
    
    menu();
    int withFriend = resultMenu();
    resultChoicPlayground(withFriend);
    int choiceOfMap = resultChoicPlayground(withFriend);
    Map *map = getMap(choiceOfMap);
    Play(choiceOfMap, withFriend);
    return 0;
}