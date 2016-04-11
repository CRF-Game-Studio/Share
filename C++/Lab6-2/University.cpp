#include "University.h"
#include <fstream>
#include <vector>
using namespace std;


University::University(istream &infile)
{
	char buf[50];
    infile.getline(m_name, '\n');

    int numberOfColleges;
    infile >> numberOfColleges;
    infile.getline(buf, 50, '\n');

    int iDept;
    for (iDept=0; iDept<numberOfColleges; iDept++)
        m_colleges.push_back(new College(infile)); 
}


University::~University(void)
{
	vector<College>::iterator iter;
    for (iter=m_colleges.begin();iter<m_colleges.end();iter++)
        delete &iter;
}

void University::print(ostream &os)
    {
        os << "¾Ç®Õ¦WºÙ:" << m_name << endl;
        vector<College>::iterator iter;
        for (iter=m_colleges.begin();iter<m_colleges.end();iter++)
            (iter)->print(os);
    }