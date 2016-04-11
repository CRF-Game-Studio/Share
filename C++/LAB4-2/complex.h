#pragma once
#include <iostream>

using namespace std;

class complex
{
public:
	complex(void);
	~complex(void);
private:
	double m_real;
	double m_imaginary;
public:
	static void unitTest();
	void setValue(double real, double imaginary);
	void add(complex x2);
	void subtract(complex x2);
	void multiply(complex x2);
	bool divide (complex x2);
	double length ();
	bool equal(complex x2,double range);
	void print();
	void setValue(complex &src);
	void print(ostream &out);
	
};
ostream &operator<<(ostream &os, complex &rhs);
ostream *operator<<(ostream *os, complex src);