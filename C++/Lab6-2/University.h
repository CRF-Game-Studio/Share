#ifndef UNIVeRSITY_H
#define UNIVeRSITY_H
#include <fstream>
#include <vector>
#include "College.h"
using namespace std;

class University
{
public:
	University(istream &infile);
	~University(void);
	void print(std::ostream &os);
private:
	char m_name[40];
	vector<College> m_colleges;
};
#endif
