#include "fileio.h"

using namespace std;

int readfile(string file, jug* j) {

	string stuff = "";
	ifstream a_file(file.c_str());
	int temp;


	if (a_file) {
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
		if ((j->getGoal()[0] > j->getJugACap()) || (j->getGoal()[1] > j->getJugBCap())) {
			return -1;
		}
		else
			return 0;
	}
	else {
		return -2;
	}
	
	

	
}
