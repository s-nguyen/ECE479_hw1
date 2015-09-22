#include "jug.h"
#include <iostream>

using namespace std;


jug::jug()
{
	jugACap = 0;
	jugBCap = 0;
	jugA = 0;
	jugB = 0;
	goal[0] = 0;
	goal[1] = 0;
	op = 0;

}

jug::jug(int ac, int bc, int a, int b, int g[2] ) {
	jugACap = ac;
	jugBCap = bc;
	jugA = a;
	jugB = b;
	goal[0] = g[0];
	goal[1] = g[1];
}


jug::~jug()
{
}

void jug::setJugA(int i) {
	jugA = i;
}

void jug::setJugB(int i) {
	jugB = i;
}



void jug::setGoal(int i, int index) {
	goal[index] = i;
	goal[index] = i;
}

void jug::setJugACap(int i) {
	jugACap = i;
}

void jug::setJugBCap(int i) {
	jugBCap = i;
}

int jug::getJugA() {
	return jugA;
}

int jug::getJugB() {
	return jugB;
}


int* jug::getGoal() {
	return goal;
}

int jug::getJugACap() {
	return jugACap;
}

int jug::getJugBCap() {
	return jugBCap;
}

void jug::text(int o, int r) {
	switch (o) {
	case 0:
		if (r == 0) {
			setJugA(jugACap);
		}
		else if (r == 1) {
			cout << ">Fill the " << jugACap << "-gal jug" << "\t\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		break;
	case 1:
		if (r == 0) {
			setJugB(jugBCap);
		}
		else if (r == 1) {
			cout << ">Fill the " << jugBCap << "-gal jug" << "\t\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		break;
	case 2:
		if (r == 0) {
			setJugA(0);
		}
		else if (r == 1) {
			cout << ">Empty the " << jugACap << "-gal jug" << "\t\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		break;
	case 3:
		if (r == 0) {
			setJugB(0);
		}
		else if (r == 1) {
			cout << ">Empty the " << jugBCap << "-gal jug" << "\t\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		break;
	case 4:
		if (r == 0) {
			while (jugA < jugACap && jugB > 0) {
				jugA++;
				jugB--;
			}
		}
		else if (r == 1) {
			cout << ">Pour " << jugBCap << "-gal jug into " << jugACap << "-gal jug" << "\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		break;
	case 5:
		if (r == 0) {
			while (jugA > 0 && jugB < jugBCap) {
				jugA--;
				jugB++;
			}
		}
		else if (r == 1) {
			cout << ">Pour " << jugACap << "-gal jug into " << jugBCap << "-gal jug" << "\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		break;
	}
}

int jug::jugop(int o) {
	switch (o) {
	case 0: //Fill the A-gallon jug
		if (jugA != jugACap) {
			setJugA(jugACap);
			return 0;
		}
		else {
			return -1;
		}
		break;
	case 1: //Fill the B-gallon jug
		if (jugB != jugBCap) {
			setJugB(jugBCap);
			return 1;
		}
		else {
			return -1;
		}
		break;
	case 2: //Empty  the A-gallon jug
		if (jugA != 0) {
			setJugA(0);
			return 2;
		}
		else {
			return -1;
		}
		break;
	case 3: //Empty the B-gallon jug
		if (jugB != 0) {
			setJugB(0);
			return 3;
		}
		else {
			return -1;
		}
		break;
	case 4: //Pour B-gallon jug into A-gallon jug keep overflow
		if ((jugA != jugACap)&&(jugB != 0)) {
			while (jugA < jugACap && jugB > 0) {
				jugA++;
				jugB--;
			}
			return 4;
		}
		else {
			return -1;
		}
		break;
	case 5: //Pour jugACap-gallon jug into B-gallon jug keep overflow
		if ((jugB != jugBCap)&&(jugA != 0)) {
			while (jugA > 0 && jugB < jugBCap) {
				jugA--;
				jugB++;
			}
			return 5;
		}
		else {
			return -1;
		}
		break;
	}

}

void jug::expand() { //expand all possibile posibilities
	for (int i = 0; i < 6; i++) {
		jug temp(this->getJugACap(), this->getJugBCap(), this->getJugA(), this->getJugB(), this->getGoal());
		temp.text(i, 0);
		this->node.push_back(temp);
	}
}

vector<jug> jug::getNode() {
	return node;
}