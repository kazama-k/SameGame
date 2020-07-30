#include <iostream>
#include <SameAction/Game.h>

int main(int argc, const char** argv)
{
	samegame::SameActionGame game(100, 100, 1024, 768);
	bool success = game.Initialize();

	if (success)
	{
		game.RunLoop();
	}

	game.Shutdown();

	return 0;
}