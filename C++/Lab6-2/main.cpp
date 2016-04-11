#include <iostream>
#include <fstream>
#include "University.h"
using namespace std;

void main(){
	fstream infile("ntou1.txt");
	if (!infile)
            std::cout << "Cannot open ntou1.txt!!\n";
    else
    {
        University ntou(infile);
        ntou.print(cout);
    }

}