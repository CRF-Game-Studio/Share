#ifndef game_h
#define game_h

class Bag;

class Game
{
public:
    Bag *getABag();
    Game();
	double test();
	double test_2();
    ~Game();
private:
    Bag *m_bags[4];
	const int m_numberOfBags;
};

#endif