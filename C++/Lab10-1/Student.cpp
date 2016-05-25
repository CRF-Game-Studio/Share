#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(const char *name, const char *ID, const char *phone, const char *department)
{
	m_name = new char[strlen(name) + 1];
	m_ID = new char[strlen(ID) + 1];
	m_phone = new char[strlen(phone) + 1];
	m_department = new char[strlen(department) + 1];

	strcpy(m_name, name);
	strcpy(m_ID, ID);
	strcpy(m_phone, phone);
	strcpy(m_department, department);
}


Student::~Student(void)
{
	delete [] m_name;
	delete [] m_ID;
	delete [] m_phone;
	delete [] m_department;
}

void Student::display(ostream &os) const{
	os << "姓名：" << m_name << "\nID：" << m_ID << "\n電話：" << m_phone 
		<< "\n就讀學系：" << m_department;
}

bool Student::IDEquals(char *id){
	if(!strcmp(id,m_ID))return true;
	return false;
}