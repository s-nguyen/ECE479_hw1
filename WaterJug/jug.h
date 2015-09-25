#pragma once
#include <vector>
#include <fstream>
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
	int op;
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
	void text(int o, int r, ofstream& o_file);

	void expand(ofstream& o_file);


	int jugop(int o);

};

