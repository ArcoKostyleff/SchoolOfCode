
#include <iostream> 

typedef int тип;
#define размер_константа 5

#define SIZE 5  // это препроцессорная директива, которая просто заменяет слово size на 5
const int N = 5; // можно объявить в глобально пространтсве

typedef int тип;
int main() {
	// задание 1
	// дано 5 учеников, у каждого по 5 оценок. Реализовать журнал успеваемости
	// и ввести с клавиатуры оценки каждого из них. Все сохранить в двумерном
	// массиве

	const int n = 5;
	int uch[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			std::cin >> uch[i][k];
		}
	}
	double sr[5] = {};
	int summ = 0;
	for (int i = 0; i < n; i++)
	{
		summ = 0;
		for (int k = 0; k < n; k++)
		{
			summ += uch[i][k];
		}
		sr[i] = summ / 5.0;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << sr[i] << " ";
	}
	/*
	0: 2 3 5 4 3
	1: 5 2 5 2 4
	2: 4 3 3 4 4
	3: 2 3 5 4 3
	4: 2 3 5 4 3
	*/
}
