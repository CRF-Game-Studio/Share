#include "Game.h"
#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // rand()
#include <assert.h>
#include <ctime>   // time()
#include <iostream>
#include "Dice.h"

Game::Game()
	 :m_numberOfBags(4)
{
	m_bags[0] = new Bag(Ball::Red, Ball::Red, Ball::Red);
	m_bags[1] = new Bag(Ball::Red, Ball::Red, Ball::White);
    m_bags[2] = new Bag(Ball::Red, Ball::White, Ball::White);
	m_bags[3] = new Bag(Ball::White, Ball::White, Ball::White);
}

Game::~Game()
{
    int i;
    for (i=0; i<m_numberOfBags; i++)
        delete m_bags[i];
}

Bag *Game::getABag()
{
    return m_bags[rand()%m_numberOfBags];
}
double Game::test(){
	int   i, totalCount=0,thirdIsAlsoRed=0;
    Game  theGame;
	Bag  *pickedBag;
    Ball *pickedBall;

	for (i=0; i<10000; i++)
    {
        pickedBag = theGame.getABag();
        pickedBall = pickedBag->getABall();
		if (pickedBall->isRed())
        { 
			if (pickedBag->getABall()->isRed()){
				totalCount++;
				if(pickedBag->getABall()->isRed()){
					thirdIsAlsoRed++;
				}
			}
        }
        pickedBag->putBallsBack();
    }
	
	return ((double)thirdIsAlsoRed/totalCount) ;
 
}

double Game::test_2(){
	Dice  *dice[2];
    double prob1[] = {1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6};
    dice[0] = new Dice(prob1);
	double prob2[] = {1.0/4, 1.0/4, 1.0/6, 1.0/6, 1.0/12, 1.0/12};
    dice[1] = new Dice(prob2);

	Game  theGame;
	Bag  *pickedBag;
    Ball *pickedBall;
	int i,total=0,n_white=0;

	for(i=0;i<10000;i++){
		pickedBag=getABag();
		pickedBall=pickedBag->getABall();
		while (pickedBall->isRed()){
			pickedBag->putBallsBack();
			pickedBag = theGame.getABag();
			pickedBall = pickedBag->getABall();
		}
        if (dice[rand()%2]->randomThrow()%2 == 0)
			pickedBag->getABall();

		total++;
		if(!pickedBag->getABall()->isRed())
			n_white++;
		pickedBag->putBallsBack();
	}
	
	delete dice[0];
	delete dice[1];

	return ((double)n_white/total);
}