#include <iostream>
#include <stdlib.h>
#include "sources/Game.hpp"

using namespace std;

int main (int argc, char* argv[])
{
	cout << "Let's play Bowling Game !" << endl;

	Game game;
	game.play();	

	return 0;
}