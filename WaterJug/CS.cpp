#include <iostream>
#include <ctime>
#include <cstdlib>
#include "CS.h"
#include <vector>
#include <fstream>

using namespace std;

void stratA(jug* j, ofstream& o_file) {
	int i = 0;
	int goalA = j->getGoal()[0];
	int goalB = j->getGoal()[1];
	srand(time(0));

	

	cout << ">Strategy A" << endl;
	cout << ">Starting out with a "<< j->getJugACap() <<"-gal jug and a "
		<<j->getJugBCap() <<"-gal jug" << "\t\t--- state:("
		 << j->getJugA() << ", " << j->getJugB() << ")" << endl;

	o_file << ">Strategy A" << endl;
	o_file << ">Starting out with a " << j->getJugACap() << "-gal jug and a "
		<< j->getJugBCap() << "-gal jug" << "\t\t--- state:("
		<< j->getJugA() << ", " << j->getJugB() << ")" << endl;
	

	for (i = 0; i < 250; i++) {
		int m = -5;
		while (m != -1) {//Search for a valid operator
			m = j->jugop(rand() % 6);
			if (m != -1) {
				j->text(m, 1, o_file);
			}
		}
		
		if ((j->getJugA() == goalA)&&goalB == -1) {
			break;
		}
		else if ((j->getJugB() == goalB) && goalA == -1) {
			break;
		}
		else if ((j->getJugA() == goalA) && (j->getJugB() == goalB)) {
			break;
		}
		else if ((j->getGoal()[0] == -1) && (j->getGoal()[1]) == -1) {
			break;
		}

	}
	if (i > 249) {
		cout << "Unsuccessful search after 250 tries" << endl;
		o_file << "Unsuccessful search after 250 tries" << endl;
	}
	
}

void stratB(jug* j, ofstream& o_file) {
	int i = 0;
	int goalA = j->getGoal()[0];
	int goalB = j->getGoal()[1];

	cout << ">Strategy B" << endl;
	cout << ">Starting out with a " << j->getJugACap() << "-gal jug and a "
		<< j->getJugBCap() << "-gal jug" << "\t\t--- state:("
		<< j->getJugA() << ", " << j->getJugB() << ")" << endl;

	o_file << ">Strategy B" << endl;
	o_file << ">Starting out with a " << j->getJugACap() << "-gal jug and a "
		<< j->getJugBCap() << "-gal jug" << "\t\t--- state:("
		<< j->getJugA() << ", " << j->getJugB() << ")" << endl;


	
	while (1) {

		j->expand(o_file); //create all possible nodes for states
		//if juga and jug b = 0
		//fill a
		//transfer a to b
		//need to expand possible nodes
		// Error checking	
		vector<jug> a = j->getNode();
		

		if ((j->getJugA() == 0) && j->getJugB() == 0) { //jugA and jugB are empty
			*j = (j->getNode()[0]); //Fill A
			j->text(0, 1, o_file);
		}
		else if (((j->getJugB())<(j->getJugBCap()))&&(j->getJugA() != 0)) { //JugB < JugB capacity && jugA != 0
			*j = j->getNode()[5]; //Move from jugA to jugB
			j->text(5, 1, o_file);
		}
		else if ((j->getJugA() > 0)&&(j->getJugB() == j->getJugBCap())) { //JugA > 0 && jugB = JugBCap
			*j = j->getNode()[3]; //Empty JUgB
			j->text(3, 1, o_file);
		}
		else if ((j->getJugA() == 0) && (j->getJugB() != j->getJugBCap())) { //jugA = 0 && jugB!= jugBCap
			*j = (j->getNode()[0]); //Fill A
			j->text(0, 1, o_file);
		}
		else {
			*j = (j->getNode()[3]); //Empty JugB
			j->text(3, 1, o_file);
		}


		

		if ((j->getJugA() == goalA) && goalB == -1) {
			break;
		}
		else if ((j->getJugB() == goalB) && goalA == -1) {
			break;
		}
		else if ((j->getJugA() == goalA) && (j->getJugB() == goalB)) {
			break;
		}
		else if ((j->getGoal()[0] == -1) && (j->getGoal()[1]) == -1) {
			break;
		}
	}
	
}