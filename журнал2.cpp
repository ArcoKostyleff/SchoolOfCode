
#include <iostream>

using namespace std;

int main()
{/*2) тоже самое, но теперь оценка есть по конкретному предмету - то есть у вас есть какие то предметы,
 допустиm математика физра и русский. И вы должны вводить оценку по предмету, например 5 R, то есть по русскому - 5.
 Также и смотреть средний балл можно как по отдельному, так и по всем предметам и новая опция - вывести предмет с худшей и 
 лучшей успеваемостью*/
	int summ = 0;
	float avMark = 0;
	int key = 0;
	int mark;
	int count = 0;
	setlocale(LC_ALL, "russian");

	float avRussian = 0;
	float avMath = 0;
	float avPE = 0;
	int russCount=0;
	int countMath=0;
	int countPE=0;	
	int russSumm=0;
	int mathSumm =0;
	int peSumm =0;


	char subj;
	while (key !=9 ) {
		cout << "1 - добавить оценку по предмету , 2 - посмотреть текущий средний балл (общий и по предмету), 3 - вывести самую худшую успеваемость. 9 - выйти\n";

		cin >> key;

		switch (key)
		{
		case 1: {
			cout << "input ur mark and surjik: ";
			cin >> mark;
			cin >> subj;
			if (subj == 'R') {
				russCount += 1;
				russSumm += mark;
			}
			if (subj == 'M') {
				countPE+= 1;
				russSumm += mark;
			}
			if (subj == 'P') {
				countMath += 1;
				russSumm += mark;
			}
			summ += mark;
			count += 1;
			break;
		}
		case 2:
		{
			// TODO: (вывести средний балл общий и по предмету)
			avMark = float(summ)/ count;
			cout << "avarage mark is: " << avMark <<"\n";
			break;
		}	
		case 3:
			// TODO:
			// сравнить рузкий мотематику и фез-ру
		case 9:
			cout << "bye bye\n";
			//return 0;
			break;
		default:
			break;
		}

	}

	return 0;
}
