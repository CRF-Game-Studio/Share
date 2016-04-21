#include "College.h"
#include "Department.h"
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

College::College(istream &infile)
{
	char buf[50];
    infile.getline(m_name, '\n'); // string m_name; 學院名稱

    int numberOfDepartments;
    infile >> numberOfDepartments;
    infile.getline(buf, 50, '\n');

    int iDept;
    for (iDept=0; iDept<numberOfDepartments; iDept++)
        m_departments.push_back(new Department(infile)); 
          // vector<Department *> m_departments;
}

College::College(College& src){
	strcpy(m_name,src.m_name);
	int i;
	for (i=0; i<(src.m_departments.end()-src.m_departments.begin()); i++){
		m_departments.push_back(new Department(&(src.m_departments[i]))); 
	}
        
}

College::~College(void)
{
	vector<Department>::iterator iter;
    for (iter=m_departments.begin();iter<m_departments.end();iter++)
        delete &iter;
}

void College::print(ostream &os)
    {
        os << "  " << "學院名稱:" << m_name << endl;
        vector<College>::iterator iter;
        for (iter=m_departments.begin();iter<m_departments.end();iter++)
            (iter)->print(os);
    }
