#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

void Read(int arr[][],int *num,int *edge){
	char fname[64],i,j,len;
	cout << "Please input file name:";
	cin >>¡@fname;
	ifstream in (fname);
	in >> *num;
	in.ignore(80, '\n');
	in >> *edge;
	in.ignore(80, '\n');
	while(in >> i >> j >> len){		
		arr[j][i]=arr[i][j]=len;
		in.ignore(08,'\n');
	}

}