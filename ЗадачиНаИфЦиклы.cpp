#include <iostream>
using namespace std;
 /*
 0) На вашей киберферме живут робокоты и робопсы.
 С консоли вводится два целых числа - N и M, где N - количество киберкотов, а M - киберпсов.
Выведите в консоль, сколько у вас на ферме кого и суммарное количество обитателей. 
Например, ввели 2 и 5, тогда вывод - "i have _2_ robocats and _5_ robodogs! Summary - _7_ animals"
1) На if - Вы программируете робокотика и робопса. Напишите для них программу голоса: если ввести 1, то надо вывести "meow!", если 2 - то вывести "bark!"
2) На цикл - Вы опять программируете робокотика. Напишите программу, чтобы он мявкал столько раз, сколько вы введете. Например, вы ввели 3 и программа должна выдать "Meow Meow Meow"
 */
int main()
{
	// 0
	int n, m;
	cin >> n >> m;
	cout << "i have " << n << " robocats and " << m << " robodogs! Summary - " <<n+m << " animals";

	// 1
	
	int choose;
	while (true) {
		cin >> choose;

		if (choose == 1) {
			cout << "meow!\n";
		}
		else {
			if (choose == 2) {
				cout << "bark!\n";
			}
			else {
				cout << "ti durak&\n";
			}
		}
		
	}

	// 2

	int n;
	cin >> n; // 5
	// 0 1 2 3 4 5
	for (int i = 0; i < n; i++) {
		cout << "meow ";
	}
	
}
