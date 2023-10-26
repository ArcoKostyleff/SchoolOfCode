// алгоритм Брезенхема 
//

#include <iostream>
#include <SFML/Graphics.hpp>


#include <string>
using namespace std;

int main()
{
	/*
	  const char str1[13] = "aboba amogus'\0'";
	*/

	


	// юзвер вводит свое имя 
	// надо вывести "привет $юзвер$"
	/*cout << "hello usver, input yr name: ";
	cin >> s;
	
	cout <<"hi, " << s <<", have a nice day\n";
	*/			//  0123
	setlocale(LC_ALL, "russian");

	// 
	
	// ______жора____ 
	// жора -> жопа

	// пройтись от 0 до 3 (до конца строки)
	// найти букву р и заменить на П
	// 
	/*/string s;
	cin >> s;
	// 'r' - > 'p'

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'r') {
			s[i] = 'p';
		}
	}
	cout << s;
	*/
	// 1 - вводится строка из букв, подсчитать
	// количество букв 'a' в строке
	// 2- вводится последовательность из . - +, 
	// подсчитать количество всех символов и 
	// заменить все '.' на 'а', а все '-' на '+'
	// 3 - задача журнал вводятся подряд ваши 
	// оценки, например 52334525
	// - заменить все 2 и 3 на 5
/*
	string str; // 01234567
	cin >> str; // 52334525

	for (int i = 0; i < str.length(); i++) {
		//cout << str[i] <<" ";
		if (str[i] == '2' || str[i] == '3') {
			str[i] = '4';
		}
	}
	int sum = 0;
//	cout << str; // 5 4 4 3 5 4 5 2
	for (int i = 0; i < str.length(); i++)
	{	//53  - 48  = 5
		//'5' - '0' = 5
		sum += str[i] - '0' ; // 
		cout << str[i] << " ";
	}// summ  = 4 4 2 = 10
	//  count = 3
	//	
	float avarageMark = float(sum) / str.length();
	// вывести средний балл
	cout <<"\n" << avarageMark;
	*/
	// вводится N чисел 
	// надо найти среднее значение 

	int n;
	cin >> n; //5
	int t;
	int sum = 0;

	int count = n;
	//for(int i =0; i< n; i++)
	while(n >0) // 5 4 3 2 1 
	{
		cin >> t;
		sum += t;
	
		n -= 1;
	}
	
	float srednee = float(sum) / count;
	cout << srednee;



	//index -> указывать 
	//указательный палец - индекс фингер 

}
