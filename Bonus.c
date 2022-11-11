int random1to21()
{
    int randomnumber;
    randomnumber = rand() % 21;
    printf("\nRandom: %d\n", randomnumber);
    return randomnumber;
}
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
//
//void resulteBonus(Map *map, int x, int y){
//    int number = random1to10();
//    if (number >= 0 && number < 6)
//    {
//        map->map[x][y] = '-';
//    }
//    if (number >= 6 && number < 9)
//    {
//        map->map[x][y] = 'U';
//    }
//    if (number >= 9 && number < 12)
//    {
//        map->map[x][y] = 'D';
//    }
//    if (number >= 12 && number < 14)
//    {
//        map->map[x][y] = 'J';
//    }
//    if (number >= 14 && number < 16)
//    {
//        map->map[x][y] = 'K';
//    }
//    if (number >= 16 && number < 17)
//    {
//        map->map[x][y] = 'R';
//    }
//    if (number >= 17 && number < 18)
//    {
//        map->map[x][y] = 'I';
//    }
//    if (number >= 18 && number < 20)
//    {
//        map->map[x][y] = 'C';
//    }
//    if (number >= 20 && number < 21)
//    {
//        map->map[x][y] = 'V';
//    }    
//}
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
    if(player->bomb->range > 0)
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
int invincibilityFunction( Player *player)
{
    player->invincibility = 1;
    return 0;
}