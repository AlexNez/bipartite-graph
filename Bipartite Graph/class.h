#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <conio.h>
using namespace std;

typedef unsigned int uint; //��������� ����� �������� ������� ��� ����� ������������� ���� unsigned int

class Node {
public:
	string name; //������������ ����
	int flag = 0;
	set<uint> neighbors = {};
	Node() {}//����������� �����������
	~Node() {}//����������� ����������
};

class Cell {
public:
	uint nodes[4]; //������ � ������ � ������
	Cell() {} // ����������� �� ���������
	~Cell() {} // ����������
};


class Graph
{
public:
	Cell *cells; // ������ �����
	Node *allnodes; //������ ���� ����� � �����
	uint cc;// ���������� �����
	uint cn;// ���������� �����
	Graph() {} //����������� ����������� �����
	~Graph() {} // ����������
	/*Node& SearchNodeByName(string s)
	{
		for (int i = 0; i < cc; i++)
			for (int j = 0; j < 3; j++)
				if (this->cells[i].nodes[j].name == s) return this->cells[i].nodes[j];
		cout << "������: �� ������� ���� � ������ " << s << "\n";
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