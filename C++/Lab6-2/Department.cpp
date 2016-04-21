#include "Department.h"
#include <fstream>
#include <string.h>
using namespace std;


Department::Department(istream &infile)
{
    infile.getline(m_name, '\n'); // string m_name; �ǰ|�W��
}

Department::Department(Department& src){
	strcpy(m_name,src.m_name);        
}

Department::~Department(void)
{
}

void Department::print(ostream &os){
	os << "    " << "�Ǩt�W��" << m_name << endl;
}