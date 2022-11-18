/*int randomNumber()
{
    return rand() % 4;
}
botMovement(Map *map, Player *player)
{
    int x = player->x;
    int y = player->y;
    int direction = randomNumber(4);
    switch (direction)
    {
    case 0:
        if (map->map[x][y + 1] == '-')
        {
            player->y++;
        }
        break;
    case 1:
        if (map->map[x][y - 1] == '-')
        {
            player->y--;
        }
        break;
    case 2:
        if (map->map[x + 1][y] == '-')
        {
            player->x++;
        }
        break;
    case 3:
        if (map->map[x - 1][y] == '-')
        {
            player->x--;
        }
        break;
    }
}

mouvementRight(){
    if (map->map[x][y + 1] == '-')
    {
        player->y++;
    }
    else{
        randomNumber();
    }
}
mouvementLeft(){
    if (map->map[x][y - 1] == '-')
    {
        player->y--;
    }
    else
    {
        randomNumber();
    }
}
mouvementTop(){
    if (map[x + 1][y] == '-')
    {
        player->x++;
    }
    else
    {
        randomNumber();
    }
}
mouvementBottom(){
    if (map->map[x - 1][y] == '-')
    {
        player->x--;
    }
    else
    {
        randomNumber();
    }
}*/