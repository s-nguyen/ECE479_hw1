#pragma once
class jug
{
private:
	int jugACap;
	int jugBCap;
	int jugA;
	int jugB;
	int goal [2];

public:
	jug();
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



	void jugop(int o);

};

