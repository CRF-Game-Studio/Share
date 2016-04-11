#ifndef DICE_H
#define DICE_H

class Dice
{
public:
	Dice(double probability[]);
	~Dice(void);
	int randomThrow();
private:
	int boundary[6];
};

#endif