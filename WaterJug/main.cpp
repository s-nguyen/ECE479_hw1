//Author: Stephen Nguyen
//Description: Homework #1 Water Jug
#include <iostream>
#include "fileio.h"
#include "jug.h"
#include "CS.h"
using namespace std;

int main(int argc, char *argv[]) {
	string file;
	jug* j = new jug();
	cout << "Please enter input file: ";
	cin >> file;
	
	int err = readfile(file, j);


	if (err == 1) {
		cout << "Goal is higher than capacity" << endl;
	}
	else if (err == -2) {
		cout << "File does not exist" << endl;
	}
	else {
		stratA(j);
		stratB(j);
	}
	

	return 0;
}