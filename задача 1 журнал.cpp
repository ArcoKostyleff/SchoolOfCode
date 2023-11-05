
#include <iostream>

using namespace std;

int main()
{/*
 1) Делаем попытку в интерфейс: Делаем свой электронный дневник - есть 3 опции, 
 1 - добавить оценку , 2 - посмотреть текущий средний балл, 3 - выйти
 */
	int summ = 0;
	float avMark = 0;
	int key = 0;
	int mark;
	int count = 0;
	setlocale(LC_ALL, "russian");
	while (key !=3 ) {
		cout << "1 - добавить оценку , 2 - посмотреть текущий средний балл, 3 - выйти\n";

		cin >> key;

		switch (key)
		{
		case 1: {
			cout << "input ur mark: ";
			cin >> mark;
			summ += mark;
			count += 1;
			break;
		}
		case 2:
		{
			avMark = float(summ)/ count;
			cout << "avarage mark is: " << avMark <<"\n";
			break;
		}
		case 3:
			cout << "bye bye\n";
			//return 0;
			break;
		default:
			break;
		}

	}

	return 0;
}
