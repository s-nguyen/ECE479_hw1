#include <iostream>
#include <ctime>
#include <cstdlib>
#include "CS.h"


using namespace std;

void stratA(jug* j) {
	int i = 0;
	
	srand(time(0));
	cout << ">Strategy A" << endl;
	cout << ">Starting out with a "<< j->getJugACap() <<"-gal jug and a "
		<<j->getJugBCap() <<"-gal jug" << "\t\t--- state:("
		 << j->getJugA() << ", " << j->getJugB() << ")" << endl;
	
	j->jugop(0);
	j->jugop(1);
	j->jugop(2);
	j->jugop(3);
	j->jugop(4);
	j->jugop(5);

	for (i = 0; i < 251; i++) {
		//j->jugop(rand() % 6);

	}
	if (i > 250) {
		cout << "Unsuccessful search after 250 tries" << endl;
	}
}

void stratB(jug* j) {

}