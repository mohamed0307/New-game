#include "game.h"
using namespace sf;

int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));
	Sound begin;
	SoundBuffer begin_B;
	begin_B.loadFromFile("C:\\Users\\Lenovo\\Documents\\new_application\\ConsoleApplication3\\images_balls\\begin.ogg");
	begin.setBuffer(begin_B);
	game game;
	bool gameS = true;
	while (game.running())
	{
		while (gameS) {
			
			if (game.PlayGame())
			{
				gameS = false;
			}
		}
		game.Update();
		game.Render();
	}
	return 0;
}


