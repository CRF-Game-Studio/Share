#include "Dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice(double probability[]){
	int i;
	double cumulativeProbability = 0;
	for (i=0; i<6; i++)
	{
		cumulativeProbability += probability[i];
		boundary[i] = cumulativeProbability * RAND_MAX;
	}
}


Dice::~Dice(void){
}

int Dice::randomThrow(){
	int i,x;
	x = rand();
	for (i=0; i<6; i++){
		if (x < boundary[i]){
			return i;
		}    
	} 
}