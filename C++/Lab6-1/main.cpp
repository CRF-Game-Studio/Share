#include "Game.h"
#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // srand() system()
#include <ctime>
#include <iostream>
#include <assert.h>

void main()
{ 
	Game game;
	srand((unsigned int)time(0));
	
    std::cout << "The probability that remaining ball is red = " 
		<< game.test() << "\n";
	
	std::cout << "The probability that the ball is white at step 4 = "
		<< game.test_2() << "\n";

    system("pause");
}