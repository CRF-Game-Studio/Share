#ifndef COLLEGE_H
#define COLLEGE_H
#include <fstream>
#include <vector>
#include "Department.h"
using namespace std;

class College
{
public:
	College(istream &infile);
	College(College& src);
	~College(void);
	void print(std::ostream &os);
private:
	char m_name[40];
	vector<Department *> m_departments; 
	
};
#endif
