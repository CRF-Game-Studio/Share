#include <cstdlib>
#include "complex.h"
#include <cmath>
#include <iostream>

using namespace std;

int main(){
	double a,b,c,D;
	cout <<  "a x^2 + b x + c\n" << "Please iuput the value of a, b, c : ";  
	cin >> a >> b >> c;
	D=b*b-4*a*c;
	if(D>=0){
		double x1,x2,output;
		x1=(-b+sqrt(D))/(2*a);
		x2=(-b-sqrt(D))/(2*a);
		output= (pow(x1,5) + pow(x2,5)) / (pow(x2,10) - pow(x1,7));
		cout << x1 << x2 <<"    ((x1)^5 + (x2)^5) / ((x2)^10 - (x1)^7) = " << output << '\n' ;
	}
	else{
		complex x1,x2,ch1,ch2,mo1,mo2;
		double real,im;
		int i;
		real=(-b)/(2*a);
		im=sqrt(-D)/(2*a);
		x1.setValue(real,im);ch1=x1;mo2=x1;
		x2.setValue(real,-im);ch2=x2;mo1=x2;
		for(i=0;i<4;i++){
			ch1.multiply(x1);
			ch2.multiply(x2);
		}
		ch1.add(ch2);
		for(i=0;i<9;i++)mo1.multiply(x2);
		for(i=0;i<6;i++)mo2.multiply(x1);
		mo1.subtract(mo2);
		x1.print();
		x2.print();
		if(!ch1.divide(mo1)){
			cout << "error !";
		}
		else{
			
			
			cout << "((x1)^5 + (x2)^5) / ((x2)^10 - (x1)^7) = ";
			ch1.print();
		} 
	}

	system("pause");

	return 0;
}