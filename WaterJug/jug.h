#pragma once
#include <vector>

using namespace std;

class jug
{
private:
	int jugACap;
	int jugBCap;
	int jugA;
	int jugB;
	int goal [2];
	//jug* node[6];
	vector<jug> node;
	int op = 0;
public:
	jug();
	jug(int ac, int bc, int a, int b, int g[2]);
	~jug();
	void setJugA(int i);
	void setJugB(int i);
	void setGoal(int i, int index);
	void setJugACap(int i);
	void setJugBCap(int i);
	int getJugA();
	int getJugB();
	int* getGoal();
	int getJugACap();
	int getJugBCap();
	vector<jug> getNode();
	void text(int o, int r);

	void expand();


	int jugop(int o);

};

