/**
 * This code is using C++11.
 */

#include <iostream>

#include "game_window.h"
#undef main

using namespace std;

int main()
{
	GameWindow lWindow;
	if(lWindow.run() == false)
	{
		cerr << "Cannot initialize a SDL game window !" << endl;
	}

	return 0;
}
