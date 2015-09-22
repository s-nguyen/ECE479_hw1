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

}

jug::jug(int ac, int bc, int a, int b ) {
	jugACap = ac;
	jugBCap - bc;
	jugA = a;
	jugB = b;

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


int jug::jugop(int o) {
	switch (o) {
	case 0: //Fill the A-gallon jug
		if (jugA != jugACap) {
			setJugA(jugACap);
			cout << ">Fill the " << jugACap << "-gal jug" << "\t\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		else {
			return -1;
		}
		
		break;
	case 1: //Fill the B-gallon jug
		if (jugB != jugBCap) {
			setJugB(jugBCap);
			cout << ">Fill the " << jugBCap << "-gal jug" << "\t\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		else {
			return -1;
		}
		break;
	case 2: //Empty  the A-gallon jug
		if (jugA != 0) {
			setJugA(0);
			cout << ">Empty the " << jugACap << "-gal jug" << "\t\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		else {
			return -1;
		}
		break;
	case 3: //Empty the B-gallon jug
		if (jugB != 0) {
			setJugB(0);
			cout << ">Empty the " << jugBCap << "-gal jug" << "\t\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
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
			cout << ">Pour " << jugBCap << "-gal jug into " << jugACap << "-gal jug" << "\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
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
			cout << ">Pour " << jugACap << "-gal jug into " << jugBCap << "-gal jug" << "\t\t\t\t--- state:("
				<< jugA << ", " << jugB << ")" << endl;
		}
		else {
			return -1;
		}
		break;
	}
	return 0;
}

void jug::expand() {
	for (int i = 0; i < 6; i++) {
		jug* temp = new jug(this->getJugACap(), this->getJugBCap(), this->getJugA(), this->getJugB());
		this->node = temp;
	}
}