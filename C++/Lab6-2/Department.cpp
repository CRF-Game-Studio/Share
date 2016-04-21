#include "Department.h"
#include <fstream>
#include <string.h>
using namespace std;


Department::Department(istream &infile)
{
    infile.getline(m_name, '\n'); // string m_name; 學院名稱
}

Department::Department(Department& src){
	strcpy(m_name,src.m_name);        
}

Department::~Department(void)
{
}

void Department::print(ostream &os){
	os << "    " << "學系名稱" << m_name << endl;
}