// Lab_02
#include <iostream>
#include <Windows.h>
#define str_len 30
#define size 30
#define spec_size 10
int choice;
using namespace std;

void display_menu(); // Функция показа меню
void enter_new(); // Функция ввода новых данных
void del(); // Функция для удаления данных
void change(); // Функция для изменения данных
void out(); // Функция для вывода данных
void search(); // Функция для поиска данных по названи ВУЗа

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
int current_size = 0; // Текущий размер
char poisk[str_len]; // Переменная для поиска
char check[str_len]; // Пременная для проверки вводимых значений

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
	if (current_size == 0) // Проверка на наличие данных в структуре
		cout << "*\tДанных нет" << endl;
	cout << "*\tВведите:" << endl;
	cout << "*\t1-для удаления записи" << endl;
	cout << "*\t2-для ввода новой записи" << endl;
	cout << "*\t3-для изменения записи" << endl;
	cout << "*\t4-для вывода записи(ей)" << endl;
	cout << "*\t5-для поиска вуза по названию" << endl;
	cout << "*\t6-для выхода" << endl;
	cin >> choice;
}

void enter_new()
{
	if (current_size < size) // Проверка свободного места в структуре
	{
		cout << "*\tВвод новой информации" << endl;
		cout << "\n\n\tСтрока номер - " << current_size + 1 << endl;
		cout << "Наименование ВУЗа: ";
		cin >> list_of_university[current_size].name;
		cout << endl << "Адрес: ";
		cin >> list_of_university[current_size].address;
		cout << endl << "Введите кол-во специальностей( 10 - максимальное кол-во специальностей ): ";
		cin >> list_of_university[current_size].number;
		for (int i = 0; i < list_of_university[current_size].number; i++)
		{
			cout << endl << "Специальность " << i + 1 << ": ";
			cin >> list_of_university[current_size].specialty[i].name;
		}
		cout << endl << "Конкурс 2018: ";
		do
		{
			cin >> check;
			if (isdigit(check[0]))													//	Проверка вводимых
				list_of_university[current_size].lastCompetition = atoi(check);		//		данных
			else
				cout << "Введённые данные не корректны! Пропробуйте ещё раз: ";
		} while (!isdigit(check[0]));
		cout << endl << "Стоимость обучения: ";
		do
		{
			cin >> check;
			if (isdigit(check[0]))													//	Проверка вводимых
				list_of_university[current_size].cost = atoi(check);				//		данных
			else
				cout << "Введённые данные не корректны! Пропробуйте ещё раз: ";
		} while (!isdigit(check[0]));
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
}

void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
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
			cout << "Такой строки нет!" << endl;
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
		cout << "\nВведите номер строки" << endl;
		cin >> n;
		do
		{
			cout << "Введите: " << endl;
			cout << "1-для изменения Наименования ВУЗа" << endl;
			cout << "2-для изменения Адреса" << endl;
			cout << "3-для изменения Специальностей" << endl;
			cout << "4-для изменения Конкурса 2018" << endl;
			cout << "5-для изменения Стоимсоти обучения" << endl;
			cout << "6-конец\n";
			cin >> per;
			switch (per)
			{
			case 1: cout << "Новое наименование ВУЗа: ";
				cin >> list_of_university[n - 1].name;   break;
			case 2: cout << "Новый Адрес: ";
				cin >> list_of_university[n - 1].address; break;
			case 3:
				for (int i = 0; i < list_of_university[n - 1].number; i++)
				{
					cout << "Новая Специальность " << i + 1 << ": ";
					cin >> list_of_university[n - 1].specialty[i].name;
				}
				break;
			case 4: cout << "Новый Конкурс: ";
				do
				{
					cin >> check;
					if (isdigit(check[0]))													//	Проверка вводимых
						list_of_university[n - 1].lastCompetition = atoi(check);			//		данных
					else
						cout << "Введённые данные не корректны! Пропробуйте ещё раз: ";
				} while (!isdigit(check[0]));
				break;
			case 5: cout << "Новую Стоимость обучения: ";
				do
				{
					cin >> check;
					if (isdigit(check[0]))													//	Проверка вводимых
						list_of_university[n - 1].cost = atoi(check);						//		данных
					else
						cout << "Введённые данные не корректны! Пропробуйте ещё раз: ";
				} while (!isdigit(check[0]));
				break;
			}
		} while (per != 6);
	}
	else
		cout << "Данных нет!" << endl;
	system("pause");
}

void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки - ";
		cin >> n;
		cout << endl << "Наименование ВУЗа: ";
		cout << list_of_university[n - 1].name << endl;
		cout << "Адрес: ";
		cout << list_of_university[n - 1].address << endl;
		cout << "Специальности: " << endl;
		for (int i = 0; i < list_of_university[n - 1].number; i++)
		{
			cout << "Специальность " << i + 1 << ": " << list_of_university[n - 1].specialty[i].name << endl;
		}
		cout << "Конкурс 2018: ";
		cout << list_of_university[n - 1].lastCompetition << endl;
		cout << "Стоимость обучения: ";
		cout << list_of_university[n - 1].cost << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Наименование ВУЗа: ";
			cout << list_of_university[i].name << endl;
			cout << "Адрес: ";
			cout << list_of_university[i].address << endl;
			cout << "Специальности: " << endl;
			for (int j = 0; j < list_of_university[i].number; j++)
			{
				cout << "Специальность " << j + 1 << ": " << list_of_university[i].specialty[j].name << endl;
			}
			cout << "Конкурс 2018: ";
			cout << list_of_university[i].lastCompetition << endl;
			cout << "Стоимость обучения: ";
			cout << list_of_university[i].cost << endl;
		}
	}
	system("pause");
}

void search()
{
	if (current_size)
	{
		int g = 0; // Переменная, отоброжающая успех поиска результата
		cout << "Введите название ВУЗа: ";
		cin >> poisk;
		for (int i = 0; i < current_size; i++)
		{
			if (_stricmp(poisk, list_of_university[i].name) == 0)
			{
				cout << endl << "Наименование ВУЗа: ";
				cout << list_of_university[i].name << endl;
				cout << "Адрес: ";
				cout << list_of_university[i].address << endl;
				cout << "Специальности: ";
				cout << list_of_university[i].specialty << endl;
				cout << "Конкурс 2018: ";
				cout << list_of_university[i].lastCompetition << endl;
				cout << "Стоимость обучения: ";
				cout << list_of_university[i].cost << endl;
				g++;
			}
		}
		if (g == 0)
			cout << "ВУЗ с таким названием не был найден." << endl;
	}
	else cout << "Искать нечего, структура пуста!" << endl;
	system("pause");
}