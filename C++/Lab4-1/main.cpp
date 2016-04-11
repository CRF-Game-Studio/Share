#include "complex.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <algorithm>

using namespace std;

void readFile(vector<complex> *pVector);
bool mygreater(complex c1,complex c2);

int main(){
	vector<complex> Complex_v;
	readFile(&Complex_v);
	vector<complex>::iterator iter;
    complex sum;
	sum=Complex_v[0];
	for(iter=Complex_v.begin()+1;iter<Complex_v.end(); iter++){
		sum.multiply(*iter);
	}
    sum.print();
	complex result_check;
	result_check.setValue(-8.96419,-3.24387);
	assert(!sum.equal(result_check,1e-6));//­¼ªkµ²§ô

	sort(Complex_v.begin(),Complex_v.end(),mygreater);
	int i;
	for(i=0;i<Complex_v.size();i++){
		Complex_v[i].print();
	}
	system("pause");
	return 0;
}

void readFile(vector<complex> *pVector){
	ifstream fp("complex.dat");
	complex temp;
	double real,im;
	while(fp >> real >> im){
		temp.setValue(real,im);
		//temp.print();
		pVector->push_back(temp);
	}
}

bool mygreater(complex c1,complex c2){
	return c1.length()<c2.length();
}