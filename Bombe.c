#include "Game.h"

int timeDown()
{
    int i = 5;
    while (i > 0)
    {
        i--;
        sleep(1);
    }
    return 0;
} 

void checkExplode(Map *map, Bomb *bomb)
{
    for (int i = 0; i < map->y; i++)
    {
       for (int j = 0; j < map->x; j++)
       {
           if (map->map[i][j] == 'B')
           {
                if (timeDown() == 0)
                {   
                    map->map[i][j] = '-';
                    explode(map, bomb, i, j);
                }
                
           }
       }
    }
}


void explode(Map *map, Bomb *bomb, int x, int y)
{
    //verif droit
    for (int i = 0; i < bomb->range; i++)
    {
        if (map->map[x][y + i] == 'm')
            map->map[x][y + i] = '-';
        if (map->map[x][y + i] == 'p')
            map->map[x][y + i] = '0';
        if (map->map[x][y + i] == 'g')
            map->map[x][y + i] = '0';
    }
    // verif gauche 
    for (int i = 0; i < bomb->range; i++)
    {
        if (map->map[x][y - i] == 'm')
            map->map[x][y - i] = '-';
        if (map->map[x][y - i] == 'p')
            map->map[x][y - i] = '0';
        if (map->map[x][y - i] == 'g')
            map->map[x][y - i] = '0';
        if (map->map[x][y - i] == '-')
            map->map[x][y - i] = '-';
    }
    for (int i = 0; i < bomb->range; i++)
    {
        if (map->map[x + i][y] == 'm')
            map->map[x + i][y] = '-';

        if (map->map[x + i][y] == 'p')
            map->map[x + i][y] = '0';
        if (map->map[x + i][y] == 'g')
            map->map[x + i][y] = '0';
    }
    for(int i = 0; i < bomb->range; i++)
    {
        if (map->map[x - i][y] == 'm')
            map->map[x - i][y] = '-';
        if (map->map[x - i][y] == 'p')
            map->map[x - i][y] = '0';
        if (map->map[x - i][y] == 'g')
            map->map[x - i][y] = '0';
        if (map->map[x - i][y] == '-')
            map->map[x - i][y] = '-';
    }
}

void putBomb(Map *map, int x, int y, Player *player, Player *bomb)
{
        map->map[x][y] = 'B';
        player->nbrBombe--;
        player->bomb->x = x;
        player->bomb->y = y;
        checkExplode(map, bomb);
}

int checkWin(Map *map, Player *player)
{
    // si -5 == 0winner
    // si -2 == G gagne 
    // si -1 == P gagne
    int compteur = 0;
    for (int i = 0; i < map->y; i++)
    {
        for (int j = 0; j < map->x; j++)
        {
            if (map->map[i][j] == '0')
            {
                compteur++;
            }
            if(map->map[i][j] == 'g')
            {
                compteur-=3;
            }
            if(map->map[i][j] == 'p')
            {
                compteur-=2;
            }
        }
        if (compteur == -1)
        {
            return 1;
        }
        if(compteur == -2)
        {
            return 2;
        }
        else 
        {
            return 0;
        }
    }
    
    return 0;
}
/*
if (compteur == -1)
    {
        system("clear");
        printf("Le joueur P a win GG !\n");
        exit(0);
    }
    if (compteur == -2)
    {
        system("clear");
        printf("Le joueur G a win GG !\n");
        exit(0);
    }
*/