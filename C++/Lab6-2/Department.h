#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <fstream>
#include <vector>
using namespace std;

class Department
{
public:
	Department(istream &infile);
	Department(Department& src);
	~Department(void);
	void print(std::ostream &os);
private:
	char m_name[40];
	
};
#endif
