//Author: Stephen Nguyen
//Description: Homework #1 Water Jug
#include <iostream>
#include "fileio.h"
#include "jug.h"
#include "CS.h"
using namespace std;

void main(int argc, char *argv[]) {
	string file;
	jug* j = new jug();
	cout << "Please enter input file: ";
	cin >> file;
	
	readfile(file, j);

	stratA(j);

	
}