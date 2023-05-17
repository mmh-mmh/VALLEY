#include "valley.h"

Game * gameSetup()
{
    Game * new_game = malloc(sizeof(Game));
    new_game->player = playerSetup();
    new_game->map = createMap(MAP_HEIGHT, MAP_WIDTH);	
    SetRandomSpawn(new_game);
    for(int i =0; i<300; i++)
    {
		AddMob(new_game->map->tiles);
		sleep(0.1);
	}
    return new_game;
}

void gameLoop(WINDOW * main_window)
{
    Game * game = gameSetup();
    Position position_offset;
    int input = 0;
    
    while (input != 'a')
    {
        position_offset = handleInput(input);

        checkPosition(position_offset, game);
        //moveMonsters(game);

        render(game, main_window);

        input = getch();
    }

}
