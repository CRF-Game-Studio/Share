#pragma once
#include <ostream>
using namespace std;

class Student
{
public:
	Student(const char *name, const char *ID, 
                const char *phone, const char *department);
	~Student(void);
	void display(ostream &os) const;
	bool IDEquals(char *id);
private:
        char *m_name;
        char *m_ID;
        char *m_phone;
        char *m_department;


};

