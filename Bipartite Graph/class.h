#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <conio.h>
using namespace std;

typedef unsigned int uint; //объ€вл€ем более короткий синоним дл€ часто используемого типа unsigned int

class Node {
public:
	string name; //наименование узла
	int flag = 0;
	set<uint> neighbors = {};
	Node() {}//стандартный конструктор
	~Node() {}//стандартный деструктор
};

class Cell {
public:
	uint nodes[4]; //массив с узлами в €чейке
	Cell() {} // конструктор по умолчанию
	~Cell() {} // деструктор
};


class Graph
{
public:
	Cell *cells; // массив €чеек
	Node *allnodes; //массив всех узлов в графе
	uint cc;// количество €чеек
	uint cn;// количество узлов
	Graph() {} //стандартный конструктор графа
	~Graph() {} // деструктор
	/*Node& SearchNodeByName(string s)
	{
		for (int i = 0; i < cc; i++)
			for (int j = 0; j < 3; j++)
				if (this->cells[i].nodes[j].name == s) return this->cells[i].nodes[j];
		cout << "ќЎ»Ѕ ј: Ќе найдено узла с именем " << s << "\n";
		this->cells[0].nodes[0].name = "ERROR";
		return this->cells[0].nodes[0];
	}*/
	bool CheckNode(string s)
	{
		for (uint i = 0; i < cn; i++)
			if (this->allnodes[i].name == s) return true;
		return false;
	}
	uint FindNodeIndexByName(string s)
	{
		for (uint i = 0; i < cn; i++)
			if (this->allnodes[i].name == s) return i;
		return 0;
	}
	bool CellReading();
	bool CheckAndMark(uint index, int c);
	bool IsItBipartite();
	void SaveOutputFile();
};