#include "Data.h"
#include <fstream>
#include <iostream>

using namespace std;

Data::Data()
:scene(0, 0)
{

}

void Data::load(const char* filename)
{
	// Load the data
	fstream fin(filename, ios::in);
	if(!fin)
		cerr<<"Error: Can't load "<<filename<<"."<<endl;
	char hash;
	fin>>hash;
	int ni, nj;
	fin>>ni>>nj;
	fin.ignore(1000000, '\n');

	scene.resize(ni, nj);
	for(int i=0; i<ni; i++)
		for(int j=0; j<nj; j++)
			fin>>scene(i, j);
	fin.close();
}

