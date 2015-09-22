#pragma once
class jug
{
private:
	int jugACap;
	int jugBCap;
	int jugA;
	int jugB;
	int goal [2];
	jug* node = 0;

public:
	jug();
	jug(int ac, int bc, int a, int b);
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

	void expand();


	int jugop(int o);

};

