#include <iostream>
#include "complex.h"
#include <assert.h>
using namespace std;

int main(){
	complex *p = new complex[10];
	int i;
	for(i=0;i<10;i++){
		(p+i)->setValue(i+1,i+1);
	}
	for(i=1;i<10;i++){
		p->add(*(p+i));
	}
	p->print();
	complex sum;
	sum.setValue(*p);
	delete[] p;
	sum.print();
	complex x, y;

    x.setValue(3, 4); y.setValue(5, 6);

    cout << '(' << x << ") * (" << y << ')'<<endl;
	operator<<(operator<<(operator<<(operator<<(operator<<(cout, '('), x),") * ("),y),")\n") ;
	operator<<(*operator<<(&operator<<(*operator<<(&operator<<(cout, '('), x)," * "),y),')') ;
	system ("pause");
}

