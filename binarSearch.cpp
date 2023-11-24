#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// бинарный поиск(поиск в отсортированном массиве)
	setlocale(LC_ALL, "russian");
	int n;
	cin >> n;
	vector<int> mas(n); // создали вектор (массив на N элементов типа int)
	for (int i = 0; i < n; i++) cin >> mas[i]; // ввод массива

	sort(mas.begin(), mas.end()); // сортируем массив mas от начала до конца (std::sort())
	int t;   // число, которое ищем
	cin >> t;
	int num=0; // номер этого элемента 
	int l = 0;// начало массива
	int r = mas.size() - 1; // = n-1 конец массива
	while (l < r) {		
		num = (l + r) / 2;
		cout <<"l= " << l <<", r="<< r << ", num = "<<num<< endl;
		if (mas[num] > t) r = num;
		else if (mas[num] < t) l = num;
		else break;
	}
	cout << "индекс элемента "<<t<<" в ОТСОРТИРОВАННОМ массиве: " << num;

}
