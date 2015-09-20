#include <iostream>
#include <ctime>
#include <cstdlib>
#include "CS.h"


using namespace std;

void stratA(jug* j) {
	int i = 0;
	int goalA = j->getGoal()[0];
	int goalB = j->getGoal()[1];
	srand(time(0));
	cout << ">Strategy A" << endl;
	cout << ">Starting out with a "<< j->getJugACap() <<"-gal jug and a "
		<<j->getJugBCap() <<"-gal jug" << "\t\t--- state:("
		 << j->getJugA() << ", " << j->getJugB() << ")" << endl;
	

	for (i = 0; i < 251; i++) {
		j->jugop(rand() % 6);
		if ((j->getJugA() == goalA)&&goalB == -1) {
			break;
		}
		else if ((j->getJugB() == goalB) && goalA == -1) {
			break;
		}
		else if ((j->getJugA() == goalA) && (j->getJugB() == goalB)) {
			break;
		}

	}
	if (i > 250) {
		cout << "Unsuccessful search after 250 tries" << endl;
	}
}

void stratB(jug* j) {

}