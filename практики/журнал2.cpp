// Задания: сделать вывод по имени и всех из класса с номером Н 
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
/*
Журнал школьников! Используем всю силу векторов.
Постановка задачи:
Школьник описывается следующим образом:
имя, номер класса, список оценок
В файле хранятся данные о школьниках. При запуске школьники считываются из файла
Журнал имеет следующие функции:
1. Вывод всех школьников в алфавитном порядке
2. Вывод школьников из класса N
3. Вывод N школьников с лучшими/худшими оценками
4. Добавление школьника
5. Удаление школьника
*/

// структура, описывающая школьника
struct zumer {
	string name; // имя - уникальное!
	int form; // номер класса
	vector<int> marks; // его оценки
	double avarMark{};
};

bool comp_by_name(zumer& l, zumer& r) {
	return l.name < r.name;
}
bool comp_by_mark(zumer& l, zumer& r) {
	int summL{};
	int summR{};
	for (int  i = 0; i < r.marks.size(); i++)
	{
		summR +=r.marks[i];
	}
	for (int  i = 0; i < l.marks.size(); i++)
	{
		summL += l.marks[i];
	}

	l.avarMark = double(summL) / l.marks.size();
	r.avarMark = double(summR) / r.marks.size();
	return l.avarMark > r.avarMark;
}

class Zhurnal {
private:
	vector<zumer> m_zumers; // массив школьников в журнале
	string fileName = "zumers.txt";
public:
	// конструктор, принимающий имя файла
	Zhurnal(string fn = "zumers.txt") {
		fileName = fn;
	}

	void PrintInfo() {
		cout << "Zhurnal zumerov. Funcions:\n" <<
			"1. Print all zumers from zhurnal\n" <<
			"2. Add zumer in zhurnal\n" <<
			"3. Print Best\n" <<
			"X. Exit\n";
	}

	// функция добавления школьника
	void AddZumer(string name, int form, vector<int>&marks) {
		zumer z = { name, form, marks };
		m_zumers.push_back(z);
	}
	void AddZumer(zumer &zumer) {
		m_zumers.push_back(zumer);
	}
	void PrintAll() {
		cout << "----------\nALL ZUMERS IN JOURNAL: \n";
		cout << "COUNT: " << m_zumers.size() << "\n";
		for (int i = 0; i < m_zumers.size(); i++)
		{
			cout << "NAME: " << m_zumers[i].name << ", FORM: " << m_zumers[i].form << ", MARKS:\n";
			// ТУТ БАГ!
			/*for (auto m : m_zumers[i].marks)
			{
				cout << m << " ";
			}*/
			cout << "\n";
		}
	}
	void loadData() {
		ifstream in(fileName);
		if (!in.is_open()) cout << "ERROR!";
		string s;
		zumer z;
		int n;
		while (in>>z.name >> z.form >> n) {
			int a;
			for (int i = 0; i < n; i++)
			{
				in >> a;
				z.marks.push_back(a);
			}
			m_zumers.push_back(z);
		}

		in.close();
	}
	// TODO
	void PrintAmogus(string name) {
		// по имени найти школьника и вывести его на экран
	}
	void PrintForm(int form) {
		// вывести всеъ кто в классе form
	}
	// вывести первых N лучших
	void PrintBest(int N) {
		sort(m_zumers.begin(), m_zumers.end(), comp_by_mark);
		for (int i = 0; i < N && i < m_zumers.size(); i++)
		{
			cout << m_zumers[i].name << "\n";
		}

	}
	void saveData() {
		//ofstream out(fileName, ios::app);
		ofstream out(fileName);
		// очищаем журнал
		out.clear();

		sort(m_zumers.begin(), m_zumers.end(), comp_by_name);
		// записываем всех дурней из нашего массива в файл
		for (zumer zum: m_zumers)
		{
			out << zum.name << " " << zum.form << " " << zum.marks.size() <<" ";
			for (auto m : zum.marks) {
				out << m << " ";
			}
			out << "\n";
		}
		out.close();
	}
};

int main(){

	Zhurnal Z;
	Z.loadData();
	Z.PrintInfo();
	char X;
	while (1) {
		cout << "\n--------\n";
		cin >> X;
		switch (X)
		{
		case('1'): {
			Z.PrintAll();
			break;
		}
		case('2'): {
			cout << "input zumer: name, form, marks:\n";
			zumer z;
			cin >> z.name >> z.form;
			int n, a;
			cout << "input count of marks:\n";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> a;
				z.marks.push_back(a);
			}
			Z.AddZumer(z);
			break;
		}case('3'): {
			Z.PrintBest(2);
			break;
		}
		case('X'): {
			Z.saveData();
			cout << "\n----------\nBye, User!\n";
			return 0;
		}
		default:
			Z.PrintInfo();
			break;
		}
	}
}
