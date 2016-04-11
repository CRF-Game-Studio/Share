#include "complex.h"
#include <cmath>
#include <iostream>
#include <assert.h>

using namespace std;

complex::complex(void)
	: m_real(0)
	, m_imaginary(0)
{
}


complex::~complex(void)
{
}


void complex::setValue(double real, double imaginary)
{
	m_real=real;
	m_imaginary=imaginary;
}
void complex::add(complex x2){
	m_real+=x2.m_real;
	m_imaginary+=x2.m_imaginary;
}
void complex::subtract(complex x2){
	m_real-=x2.m_real;
	m_imaginary=x2.m_imaginary;
}
void complex::multiply(complex x2){
	double temp_r,temp_i;
	temp_r=(m_real*x2.m_real)-(m_imaginary*x2.m_imaginary);
	temp_i=(m_real*x2.m_imaginary)+(m_imaginary*x2.m_real);
	m_real=temp_r;
	m_imaginary=temp_i;
}
bool complex::divide (complex x2){
	if(!(x2.m_real || x2.m_imaginary))return false;
	double temp_r,temp_i,a;
	a=x2.m_real*x2.m_real+x2.m_imaginary*x2.m_imaginary;
	temp_r=((m_real*x2.m_real)+(m_imaginary*x2.m_imaginary))/a;
	temp_i=(-(m_real*x2.m_imaginary)+(m_imaginary*x2.m_real))/a;
	m_real=temp_r;
	m_imaginary=temp_i;
	return true;
}

double complex::length (){
	return sqrt(m_real*m_real + m_imaginary*m_imaginary);
}
bool complex::equal(complex x2,double range){
	double temp_r,temp_i;
	temp_r=m_real-x2.m_real;
	temp_i=m_imaginary-x2.m_imaginary;
	if(-range<temp_r&&temp_r<range)
		if(-range<temp_i&&temp_i<range)
			return true;
	return false;
}

void complex::print(){
	if(m_imaginary>0)
		cout << m_real << '+' << m_imaginary << " i\n" ;
	else if(m_imaginary<0)
		cout << m_real << m_imaginary << " i\n" ;
	else
		cout << m_real << '\n' ;
}

void complex::unitTest(){
	complex x1, x2, x3;
    x1.setValue(7, 3);
    x2.setValue(1, 1);
    x3.setValue(5, -2); // (7+3i)/(1+i) = (5-2i)
    assert(x1.divide(x2));
    assert(x1.equal(x3, 1e-10)); // C/C++ 常數 1e-10 代表 1x10-10
    x2.setValue(0, 0);
    assert(!x1.divide(x2));	
}