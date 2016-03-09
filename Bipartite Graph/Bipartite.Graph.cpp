#include "stdafx.h"
#include "class.h"

bool Graph::CellReading() //����� ������ ��� ���������� ������ �� ����� � �������� ������� ������ ����� ��������� ������
{
	string s1, s2; //�����-������ ��� ���������� ��� ����� �� �����
	ifstream in("C:\\graph.txt");
	uint i = 0; //��������������� ������������� �������
	uint nodeindex = 0; //����� �������� ������� � ������� allnodes ����� (� ����� ������� ���������� �����)
	uint help; //��������������� ����������
	/*������: �������� ���������� �����/�����*/
	while (!in.eof()) //���� �� ��������� ����� �����
	{
		i++; //���������� ���������� �����
		getline(in, s1); //��������� ��������� ������ �� �����
	}
	in.close(); //��������� ����
	/*�����: �������� ���������� �����=�����*/
	in.open("C:\\graph.txt"); //��������� ������, ����� �������� ��������� � ������ �����
	cout << "���������� ����� � ����������� �����: " << i << "\n";
	this->cc = i; //���������� ���������� �����
	this->cn = 4 * i; //�������� ������������� ������������ ���������� �����
	this->cells = new Cell[i]; //������ ������ ����� � ������� �������
	Node *tempnodes; //��������� ������ �����
	tempnodes = new Node[this->cn]; //������������� ������������ ������
	uint j = 0; // ������� ��� �������� ������
	while (!in.eof())
	{
		getline(in, s1); // ��������� ������� � ���������� s1
		uint k = 0; // ������� ����� ������ ������
		s2 = "";
		for (i = 0; s1[i] != *""; i++) //���� �� ����� ��������� ����� ������
		{
			if (i > sizeof(s1)) //���� ����� �������� ������� ���� ������, ��� ������ unsigned int
			{
				cout << "������: ������� ������� �������� ������.\n��������� ������ ������";
				in.close(); //��������� ����
				return false; //����� �� ������������
			}
			if (s1[i] != *" ") //���� ������� ������ - �� ������
			{
				s2 = s2 + s1[i]; //�� ��������� �� s2
			}
			else
			{
				help = 0; //�� ������ ���� �������� ��������������� ����������, ����� �� ���������
				for (uint l = 0; l < this->cn; l++) //��� ���� �����
					if (tempnodes[l].name == s2) //���� ���� � ����� �� ������
					{
						help = l; //���� �����, �� ���������� ��� ������
						break;
					};
				if (help != 0) this->cells[j].nodes[k] = help; //� ���������� ��� � �������� ������� ��� �������� ����
				else //� ���� �� �����
				{
					tempnodes[nodeindex].name = s2; //�� ������ ����� ���� �� ��������� ������� � ������� ������
					this->cells[j].nodes[k] = nodeindex; //� ���������� ��� ������
					nodeindex++; //���������� ��� ���� ���������� ��������������� ����� �� 1
				}
				k++; //��� ���� ���� � ������ ��������
				s2 = ""; //�������� ������
			}
		}
		/*������: ��� ��� �� ����� �� ����� ������, ������� �� ���������� ������������-��������,
		�� 4-��� ���� ����������� ��� ��� �����*/
		//���� ������ ���������� ����� �� �� ���������� �����
		help = 0;
		for (uint l = 0; l < this->cn; l++)
			if (tempnodes[l].name == s2)
			{
				help = l;
				break;
			};
		if (help != 0) this->cells[j].nodes[k] = help;
		else
		{
			tempnodes[nodeindex].name = s2;
			this->cells[j].nodes[k] = nodeindex;
			nodeindex++;
		}
		j++;
		/*�����: ��� ��� �� ����� �� ����� ������, ������� �� ���������� ������������-��������,
		�� 4-��� ���� ����������� ��� ��� �����*/
	}
	in.close(); //��������� ����
	this->allnodes = new Node[nodeindex]; //������ ����� ������ ����� � ������� �� ��������� ���������� �����
	for (i = 0; i < nodeindex; i++) //��� ���� �����
		this->allnodes[i].name = tempnodes[i].name; //�������� �� ����� � �������� ������ �������
	delete[] tempnodes; //������� ��������� ������
	this->cn = nodeindex; //������������ ���������� �����
	cout << "���������� ����� � ����������� �����: " << nodeindex << "\n"; //�������� ������� �������

	/*������: �������� ������������ ��������� ������ �� ����� � ��������� ��������� (�������� ��� ���������)*/
	char ch;
	cout << "\n������: ������� �� ����� ���������� �����? (Y/N) "; //��������� ������, ���� ������ ������ �� ���������
	do {
		ch = _getch();
		if (islower(ch)) ch = toupper(ch);
	} while ((ch != 'Y') && (ch != 'N'));
	cout << ch << "\n\n";
	if (ch == 'Y')
	{
		for (j = 0; j < this->cc; j++)
		{
			cout << "������ �" << j + 1 << ": ";
			for (int k = 0; k <= 3; k++) cout << this->allnodes[this->cells[j].nodes[k]].name << " ";
			cout << "\n";
		}
		cout << "\n";
	}
	/*�����: �������� ������������ ��������� ������ �� ����� � ��������� ��������� (�������� ��� ���������)*/

	/*���������� ������� � ������� �����*/
	for (i = 0; i < this->cc; i++) //������� ��� ������
	{
		uint index; //��������������� ����������
		Cell c; //��������������� �������-������
		for (uint k = 0; k < 4; k++) //������� ��� 4 ���� ������
			/*������ ������������ ������������ �� ��������� ���� (������ - ������ �����, ����������� - ������ ������� �������)*/
			switch (k)
			{
				case 0: //���� ������ ����
					c = this->cells[i]; //��������� ��������
					index = c.nodes[k]; //����������� ������ ���� ��� ������� allnodes � �����
					this->allnodes[c.nodes[3]].neighbors.insert(index); //��������� ������ ���� � �������� �������
					this->allnodes[c.nodes[1]].neighbors.insert(index); //������� � ���������� ����������� �����
					break;
				case 1: //���� ������ ����
					c = this->cells[i];
					index = c.nodes[k];
					this->allnodes[c.nodes[0]].neighbors.insert(index);
					this->allnodes[c.nodes[2]].neighbors.insert(index); //������� � ��������
					break;
				case 2: //���� ������ ����
					c = this->cells[i];
					index = c.nodes[k];
					this->allnodes[c.nodes[1]].neighbors.insert(index);
					this->allnodes[c.nodes[3]].neighbors.insert(index); //������� � ����������
					break;
				case 3: //���� ��������� ����
					c = this->cells[i];
					index = c.nodes[k];
					this->allnodes[c.nodes[2]].neighbors.insert(index);
					this->allnodes[c.nodes[0]].neighbors.insert(index); //�������� � �������
					break;
			}
	}
	cout << "�����: ���� ������ ���������!\n"; //����� �� �����
	return true; //������� ��������� ���������
}

bool Graph::CheckAndMark(uint index, int c) //����������� ������� ������ � �������
{
	this->allnodes[index].flag = c; //����������� ���������� ���� ���� � ���������� ��������
	for (uint i = 0; i < this->cn; i++) //���������� ��� ������� �����
		if (this->allnodes[index].neighbors.count(i)) //���� ��������� ��� � ��������� "�������" ���� ����������� �������
			switch (this->allnodes[i].flag) //�� ������� �� ���� "������"
			{
				case 0: //���� �� ����������
					if (c == 1) //�� � ����������� �� ����������� �����
					{
						if (!this->CheckAndMark(i, 2)) //���������� �������� ���� �� �����, ���
						{							  //��� ��� ����� �������� ������������ ���� (�������� �� ���������)
							return false;			 //� ����� ����������� ��� ��� "������"
						}
					}
					else
					{
						if (!this->CheckAndMark(i, 1))
						{
							return false;
						}
					}
					break;
				case 1: //���� � ���� ��� ���������� ����, �� ���������
					if (c == 1) return false; //��� �� ��������� ��������� - ���� �����, �� ���� ������������
					break;
				case 2:
					if (c == 2) return false;
					break;
			}
	return true; //���� ����� �� ����, �� ������ � ���� ����� �� ��
}

bool Graph::IsItBipartite() //�����, ������������ ����� �� ������
{
	bool b = this->CheckAndMark(this->cells[0].nodes[0], 1); //���������� ����� �� ������ (������� � ����� ����� ������ ����� �������, ��� ����� ������ ��� � ������ ����)
	if (b) cout << "�����: ���� �������� ����������\n\n";
	else cout << "�����: ���� �� �������� ����������\n\n";
	return b; //���������� ���������� �����
}

void Graph::SaveOutputFile() //����� ���������� ��������� �����
{
	string savepath = "C:\\output.txt"; //��������� ���� ��� ����������
	ofstream out(savepath); // ��������� ���� ��� ������
	string part1,part2; // ������������ ������ ������ � ������ �����
	uint index; //��������������� ����������
	for (int i = 0; i < this->cc; i++) //��� ��� �����
	{
		part1 = part2 = ""; //�������� ������
		for (int j = 0; j < 4; j++) //� ���� ����� � ������ �� ������
		{
			index = this->cells[i].nodes[j]; //��������� ������ ���� � ����� �������
			switch (this->allnodes[index].flag) //������� �� ��� ����
			{
				case 1: //���� "��������" � ������ ����
					if (part1 == "") part1 = this->allnodes[index].name; //�� ������� ��� ���� � ������ ��� �������
					else part1 = part1 + " " + this->allnodes[index].name; //� ��������
					break;
				case 2:
					part2 = part2 + " " + this->allnodes[index].name; //� ����� � ����� ������ � ��������, ������ ��� ��� ����� �� ������ �������, ������� ������������� ��� �������
					break;
			}
		}
		out << part1 << part2 << "\n"; //������� ����� ������ � ����
	}
	out.close(); //��������� ����
	cout << "�����: ���� ������� �������� �� ������ \"" << savepath << "\"\n\n"; //��������
	return; //�������
}

int main()
{
	setlocale(LC_ALL, "Rus"); //���������� ����������� ���������
	Graph graph; //������ ������ ������ ����
	if (!graph.CellReading()) //���� �� ������ ������� ��������� �� �� ����� � �������� ������� ����
	{
		cout << "����������� ���������� ���������\n"; //�� �������� �� ����
		system("PAUSE");							 //������ �������� ����� � �������� �������
		return 0;									//� ��������� ������ ���������
	}
	/*������: ����������� �������� ������� ����� (�������� ��� ���������)*/
	char ch; //����������, � ������� ����� ��������� �������, ������� ������������� � ����������
	cout << "\n������: �������� �������� ������� �����? (Y/N) "; //��������� ������, ���� ������ ������ �� ���������!
	do {
		ch = _getch(); //��������� � ���������� (��� ������ �� ����� �������)
		if (islower(ch)) ch = toupper(ch); //���� ���������, �� ������ ��������
	} while ((ch != 'Y') && (ch != 'N')); //���� �� ����� ������ Y ��� N
	cout << ch << "\n\n"; //������� ������� �����-����� �� ����� � ���� ����������
	if (ch == 'Y') //���� ����� ��������
	{
		string s = ""; //��������������� ����������
		for (int i = 0; i < graph.cn; i++) //��� ���� �����
		{
			cout << "���������� ������� � ���� � ������ \"" << graph.allnodes[i].name << "\": " << graph.allnodes[i].neighbors.size() << "; "; //.size() - ���������� ������ ���������
			cout << "������: ";
			for (uint const& j : graph.allnodes[i].neighbors) //������� ���������� ��������� �� �����
			{
				cout << graph.allnodes[j].name << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n";
	/*�����: ����������� �������� ������� ����� (�������� ��� ���������)*/
	if (graph.IsItBipartite()) graph.SaveOutputFile(); //���� ���� ����������, �� ��������� ���������� ��������� �����
	system("PAUSE");
	return 0;
}