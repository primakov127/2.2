// Lab_02
#include <iostream>
#include <Windows.h>
#define str_len 30
#define size 30
#define spec_size 10
int choice;
using namespace std;

void display_menu(); // ������� ������ ����
void enter_new(); // ������� ����� ����� ������
void del(); // ������� ��� �������� ������
void change(); // ������� ��� ��������� ������
void out(); // ������� ��� ������ ������
void search(); // ������� ��� ������ ������ �� ������� ����

struct spec
{
	char name[str_len];
};

struct University
{
	char name[str_len];
	char address[str_len];
	int number;
	spec specialty[spec_size];
	int lastCompetition;
	int cost;
};

struct University list_of_university[size];
struct University bad;
int current_size = 0; // ������� ������
char poisk[str_len]; // ���������� ��� ������
char check[str_len]; // ��������� ��� �������� �������� ��������

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do
	{
		display_menu();
		switch (choice)
		{
		case 1: del(); break;
		case 2: enter_new(); break;
		case 3: change(); break;
		case 4: out(); break;
		case 5: search(); break;
		}
	} while (choice != 6);
}

void display_menu()
{
	system("cls");
	if (current_size == 0) // �������� �� ������� ������ � ���������
		cout << "*\t������ ���" << endl;
	cout << "*\t�������:" << endl;
	cout << "*\t1-��� �������� ������" << endl;
	cout << "*\t2-��� ����� ����� ������" << endl;
	cout << "*\t3-��� ��������� ������" << endl;
	cout << "*\t4-��� ������ ������(��)" << endl;
	cout << "*\t5-��� ������ ���� �� ��������" << endl;
	cout << "*\t6-��� ������" << endl;
	cin >> choice;
}

void enter_new()
{
	if (current_size < size) // �������� ���������� ����� � ���������
	{
		cout << "*\t���� ����� ����������" << endl;
		cout << "\n\n\t������ ����� - " << current_size + 1 << endl;
		cout << "������������ ����: ";
		cin >> list_of_university[current_size].name;
		cout << endl << "�����: ";
		cin >> list_of_university[current_size].address;
		cout << endl << "������� ���-�� ��������������( 10 - ������������ ���-�� �������������� ): ";
		cin >> list_of_university[current_size].number;
		for (int i = 0; i < list_of_university[current_size].number; i++)
		{
			cout << endl << "������������� " << i + 1 << ": ";
			cin >> list_of_university[current_size].specialty[i].name;
		}
		cout << endl << "������� 2018: ";
		do
		{
			cin >> check;
			if (isdigit(check[0]))													//	�������� ��������
				list_of_university[current_size].lastCompetition = atoi(check);		//		������
			else
				cout << "�������� ������ �� ���������! ����������� ��� ���: ";
		} while (!isdigit(check[0]));
		cout << endl << "��������� ��������: ";
		do
		{
			cin >> check;
			if (isdigit(check[0]))													//	�������� ��������
				list_of_university[current_size].cost = atoi(check);				//		������
			else
				cout << "�������� ������ �� ���������! ����������� ��� ���: ";
		} while (!isdigit(check[0]));
		current_size++;
	}
	else
		cout << "������� ������������ ���-�� �����";
}

void del()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		if (d <= current_size)
		{
			for (int de1 = (d - 1); de1 < current_size; de1++)
				list_of_university[de1] = list_of_university[de1 + 1];
			current_size--;
		}
		else
			cout << "����� ������ ���!" << endl;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list_of_university[i] = bad;
	current_size = 0;
}

void change()
{
	if (current_size != 0)
	{
		int n, per;
		cout << "\n������� ����� ������" << endl;
		cin >> n;
		do
		{
			cout << "�������: " << endl;
			cout << "1-��� ��������� ������������ ����" << endl;
			cout << "2-��� ��������� ������" << endl;
			cout << "3-��� ��������� ��������������" << endl;
			cout << "4-��� ��������� �������� 2018" << endl;
			cout << "5-��� ��������� ��������� ��������" << endl;
			cout << "6-�����\n";
			cin >> per;
			switch (per)
			{
			case 1: cout << "����� ������������ ����: ";
				cin >> list_of_university[n - 1].name;   break;
			case 2: cout << "����� �����: ";
				cin >> list_of_university[n - 1].address; break;
			case 3:
				for (int i = 0; i < list_of_university[n - 1].number; i++)
				{
					cout << "����� ������������� " << i + 1 << ": ";
					cin >> list_of_university[n - 1].specialty[i].name;
				}
				break;
			case 4: cout << "����� �������: ";
				do
				{
					cin >> check;
					if (isdigit(check[0]))													//	�������� ��������
						list_of_university[n - 1].lastCompetition = atoi(check);			//		������
					else
						cout << "�������� ������ �� ���������! ����������� ��� ���: ";
				} while (!isdigit(check[0]));
				break;
			case 5: cout << "����� ��������� ��������: ";
				do
				{
					cin >> check;
					if (isdigit(check[0]))													//	�������� ��������
						list_of_university[n - 1].cost = atoi(check);						//		������
					else
						cout << "�������� ������ �� ���������! ����������� ��� ���: ";
				} while (!isdigit(check[0]));
				break;
			}
		} while (per != 6);
	}
	else
		cout << "������ ���!" << endl;
	system("pause");
}

void out()
{
	int sw, n;
	cout << "1-����� 1 ������" << endl;
	cout << "2-����� ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������ - ";
		cin >> n;
		cout << endl << "������������ ����: ";
		cout << list_of_university[n - 1].name << endl;
		cout << "�����: ";
		cout << list_of_university[n - 1].address << endl;
		cout << "�������������: " << endl;
		for (int i = 0; i < list_of_university[n - 1].number; i++)
		{
			cout << "������������� " << i + 1 << ": " << list_of_university[n - 1].specialty[i].name << endl;
		}
		cout << "������� 2018: ";
		cout << list_of_university[n - 1].lastCompetition << endl;
		cout << "��������� ��������: ";
		cout << list_of_university[n - 1].cost << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "������������ ����: ";
			cout << list_of_university[i].name << endl;
			cout << "�����: ";
			cout << list_of_university[i].address << endl;
			cout << "�������������: " << endl;
			for (int j = 0; j < list_of_university[i].number; j++)
			{
				cout << "������������� " << j + 1 << ": " << list_of_university[i].specialty[j].name << endl;
			}
			cout << "������� 2018: ";
			cout << list_of_university[i].lastCompetition << endl;
			cout << "��������� ��������: ";
			cout << list_of_university[i].cost << endl;
		}
	}
	system("pause");
}

void search()
{
	if (current_size)
	{
		int g = 0; // ����������, ������������ ����� ������ ����������
		cout << "������� �������� ����: ";
		cin >> poisk;
		for (int i = 0; i < current_size; i++)
		{
			if (_stricmp(poisk, list_of_university[i].name) == 0)
			{
				cout << endl << "������������ ����: ";
				cout << list_of_university[i].name << endl;
				cout << "�����: ";
				cout << list_of_university[i].address << endl;
				cout << "�������������: ";
				cout << list_of_university[i].specialty << endl;
				cout << "������� 2018: ";
				cout << list_of_university[i].lastCompetition << endl;
				cout << "��������� ��������: ";
				cout << list_of_university[i].cost << endl;
				g++;
			}
		}
		if (g == 0)
			cout << "��� � ����� ��������� �� ��� ������." << endl;
	}
	else cout << "������ ������, ��������� �����!" << endl;
	system("pause");
}