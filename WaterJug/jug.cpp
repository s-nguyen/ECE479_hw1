#include "jug.h"
#include <iostream>

using namespace std;


jug::jug()
{
	jugA = 0;
	jugB = 0;
	goal[0] = 0;
	goal[1] = 0;

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


void jug::jugop(int o) {
	switch (o) {
	case 0: //Fill the A-gallon jug
		setJugA(jugACap);
		cout << ">Fill the "<<jugACap<<"-gallon jug" << "\t\t--- state:("
			<< jugA << ", " << jugB << ")" << endl;
		break;
	case 1: //Fill the B-gallon jug
		setJugB(jugBCap);
		cout << ">Fill the "<<jugBCap<<"-gal jug" << "\t\t--- state:("
			<< jugA << ", " << jugB << ")" << endl;
		break;
	case 2: //Empty  the A-gallon jug
		setJugA(0);
		cout << ">Empty the "<<jugACap<<"-gal jug" << "\t\t--- state:("
			<< jugA << ", " << jugB << ")" << endl;
		break;
	case 3: //Empty the B-gallon jug
		setJugB(0);
		cout << ">Empty the "<<jugBCap<<"-gal jug" << "\t\t--- state:("
			<< jugA << ", " << jugB << ")" << endl;
		break;
	case 4: //Pour B-gallon jug into A-gallon jug keep overflow
		while (jugA < jugACap && jugB > 0) {
			jugA++;
			jugB--;
		}
		cout << ">Pour "<<jugBCap<<"-gal jug into "<<jugACap<<"-gal jug" << "\t\t--- state:("
			<< jugA << ", " << jugB << ")" << endl;
		break;
	case 5: //Pour jugACap-gallon jug into B-gallon jug keep overflow
		while (jugA > 0 && jugB < jugBCap) {
			jugA--;
			jugB++;
		}
		cout << ">Pour "<<jugACap<<"-gal jug into "<<jugBCap<<"-gal jug" << "\t\t--- state:("
			<< jugA << ", " << jugB << ")" << endl;
		break;
	}
}
