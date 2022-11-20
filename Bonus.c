
#include <stdlib.h>

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
char resulteBonus()
{
    srand(time(NULL));
    int number = rand() % 51;
    if (number >= 6 && number < 9)
    {
        return 'U';
    }
    if (number >= 9 && number < 12)
    {
        return 'Dz';
    }
    if (number >= 12 && number < 18)
    {
        return 'J';
    }
    if (number >= 18 && number < 20)
    {
        return 'B';
    }
    if (number >= 20 && number < 24)
    {
        return 'R';
    }
    if (number == 25)
    {
        return 'I';
    }
    else
    {
        return '-';
    }
}
int BombUp(Player *player)
{
    player->nbrBombe++;
    return 0;
}
int BombDown(Player *player)
{
    player->nbrBombe--;
    return 0;
}
int RangeYelow(Player *player)
{
    player->bomb->range++;
    return 0;
}
int RangeBlue(Player *player)
{
    if (player->bomb->range > 0)
    {
        player->bomb->range--;
    }
    return 0;
}
int rangeRed(Player *player)
{
    player->bomb->range = 7;
    return 0;
}
int invincibility( Player *player)
{
    player->invincibility = 1;
    return 0;
}