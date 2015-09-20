#include "fileio.h"

void readfile(string file, jug* j) {

	string stuff = "";
	ifstream a_file;
	int temp;
	a_file.open(file);

	
	
	getline(a_file, stuff, ':');
	getline(a_file, stuff);
	istringstream(stuff) >> temp;
	j->setJugACap(temp);

	getline(a_file, stuff, ':');
	getline(a_file, stuff);
	istringstream(stuff) >> temp;
	j->setJugBCap(temp);

	getline(a_file, stuff, ':');
	getline(a_file, stuff);
	stringstream stream1(stuff);


	stream1 >> temp;
	j->setJugA(temp);
	stream1 >> temp;
	j->setJugB(temp);
	

	getline(a_file, stuff, ':');
	getline(a_file, stuff);
	
	stringstream stream2(stuff);

	for (int k = 0; k < 2; k++) {
		stream2 >> temp;
		j->setGoal(temp, k);
	}

	

	a_file.close();

}
