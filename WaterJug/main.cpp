//Author: Stephen Nguyen
//Description: Homework #1 Water Jug
#include <iostream>
#include <fstream>
#include "fileio.h"
#include "jug.h"
#include "CS.h"
using namespace std;

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cout << "Usage: \"input_file.txt\"" << endl;
		return -1;
	}
	else {
		jug* j = new jug();
		jug* k = new jug();

		ofstream o_file;
		o_file.open("waterjug_output.txt");

		int err = readfile(argv[1], j);


		if (err == 1) {
			cout << "Goal is higher than capacity" << endl;
		}
		else if (err == -2) {
			cout << "File does not exist" << endl;
		}
		else {
			stratA(j, o_file);
			readfile(argv[1], k);
			stratB(k, o_file);
		}

		o_file.close();
	}
	
	
	cout << "output file is also created" << endl;
	

	return 0;
}