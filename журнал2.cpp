
#include <iostream>

using namespace std;

int main()
{/*2) тоже самое, но теперь оценка есть по конкретному предмету - то есть у вас есть какие то предметы,
 допустиm математика физра и русский. И вы должны вводить оценку по предмету, например 5 R, то есть по русскому - 5.
 Также и смотреть средний балл можно как по отдельному, так и по всем предметам и новая опция - вывести предмет с худшей и 
 лучшей успеваемостью*/
	int summ = 0;
	float avMark = 0;
	char key = 0;
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
	while (key !='X') {
		cout << "1 - добавить оценку по предмету , 2 - посмотреть текущий средний балл (общий и по предмету), 3 - вывести самую худшую успеваемость. X - выйти\n";

		cin >> key;

		switch (key)
		{
		case '1': {
			cout << "input ur mark and subject: ";
			cin >> mark;
			cin >> subj;
			if (subj == 'R') {
				russCount += 1;
				russSumm += mark;
			}
			if (subj == 'M') {
				countMath += 1;
				mathSumm += mark;
			}
			if (subj == 'P') {
				countPE += 1;
				peSumm += mark;
			}
			summ += mark;
			count += 1;
			break;
		}
		case '2':
		{
			// TODO: (вывести средний балл общий и по предмету)
			if (count > 0) avMark = float(summ)/ count;
			cout << "avarage mark is: " << avMark <<"\n";

			if (russCount > 0) avMark = float(summ) / count;
			cout << "avarage mark is: " << avMark << "\n";

			if (countMath > 0) avMark = float(summ) / count;
			cout << "avarage mark is: " << avMark << "\n";

			if (countPE> 0) avMark = float(summ) / count;
			cout << "avarage mark is: " << avMark << "\n";

			break;
		}	
		case '3':
		{
			if (russCount != 0) avRussian = (float)russSumm / russCount;
			if (russCount != 0) avMath = (float)mathSumm / russCount;
			if (russCount != 0) avPE = (float)peSumm / russCount;

			float min = avRussian, max = 0;
			float a = avRussian, b = avPE, c = avMath;
			// выбор максимина первый способ
			if (a < b) {
				if (a < c) {
					min = a;
					if (b > c) {
						max = b;
					}
					else max = c;
				}
				else { //   c <= a < b
					min = c;
					max = b;
				}
			}
			else { //   __ b < a <=_c_ 
				if (c >= a) {
					max = c;
					min = b;
				}
				else { // b < a
					if (c > b) {// b < c < a
						min = b;
						max = a;
					}
					else { // c < b < a;
						min = c;
						max = a;
					}
				}
			}

			// второй способ
			if (avRussian < min) {
				min = avRussian;
			}
			if (avPE < min) {
				min = avPE;
			}
			if (avMath < min) {
				min = avMath;
			}
			if (avRussian > max) {
				max = avRussian;
			}
			if (avPE > max) {
				max = avPE;
			}
			if (avMath > max) {
				max = avMath;
			}

			if (min == avMath) cout << "Math is lower, " << avMath << "\n";
			if (min == avPE) cout << "PE is lower, " << avPE << "\n";
			if (min == avRussian) cout << "Russian is lower, ты больше не русский, " << avRussian << "\n";
			break;

			// третий способ

			if (a <= b && a <= c) {
				min = a;
				if (b < c) {
					max = c;
				}
				else max = b;
			}
			if (b <= c && b <=a) {
				min = b;
				if (a < c) {
					max = c;
				}
				else max = a;
			}
			// третье сравнение - с меньше всех. Напишите сами ....
			// 
			

		}
			// TODO:
			// сравнить рузкий мотематику и фез-ру


		case 'X':
			cout << "bye bye\n";
			//return 0;
			break;
		default:
			break;
		}

	}

	return 0;
}
