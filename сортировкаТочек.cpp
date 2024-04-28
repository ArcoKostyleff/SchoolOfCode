// ConsoleApplication18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//int summ(int a, int b) {
//	return a + b;
//}
//
//float summ(float a, float b) {
//	return a + b;
//}
//
//
//char summ(char a, char b) {
//	return a + b;
//}



template <typename T>
T summ(T a, T b) {
	return a + b;
}
template <typename T>
class aboba {
public:
	vector<T> mas;
	T aaa;
};

struct Point {
	double x;
	double y;
};
// компаратор для сравнения точек (для сортировки)
bool comp(Point& a, Point& b) {
	double a_r = sqrt(a.x * a.x + a.y * a.y);
	double b_r = sqrt(b.x * b.x + b.y * b.y);
	return a_r < b_r;
}

int main(){
	vector<Point> dots;
	double a, b;
	ifstream in("points.txt");
	if (!in.is_open()) cout << "ERROR\n";
	while (in) {
		Point p;
		in >> p.x >> p.y;
		//dots.push_back(Point{a,b})
		dots.push_back(p);
	}
	sort(dots.begin(), dots.end(), comp);

	for (auto P : dots) {
		cout << P.x << " " << P.y << "\n";
	}
}
/*
{	int mas[1];
	int* m_ptr = new int[1];
	delete[] m_ptr;
	m_ptr = new int[2];
	delete[] m_ptr;
	m_ptr = new int[4];
	delete[] m_ptr;
	}

	//// ХВАТИТ!
	//setlocale(LC_ALL, "russia");
	//vector<int> massiv;  // (5, -1);
	//massiv.reserve(5);
	//cout << massiv.size() <<'\n';
	//massiv.push_back(5);
	//cout << massiv.size() << '\n';
	//massiv.push_back(1);
	//massiv.push_back(2);
	//massiv.push_back(-7);
	//for (auto a : massiv)
	//{
	//	cout << a << " ";
	//}
	//cout <<"\nvmestimost do: " << massiv.capacity();
	//massiv.push_back(0);
	//massiv.push_back(0);
	//massiv.push_back(0);
	//massiv.push_back(0);
	//cout << "\nsize: " << massiv.size();

	//cout << "\nvmestimost posle: " << massiv.capacity();
	//// задание: с клавиатуры вводятся числа до тех пор,
	//// пока не будет прерван ввод (CTRL + X)
	//// эти числа сохраняем в массив
	//// потом выводим в обратном порядке (можно pop_back)

	//std::sort(massiv.begin(), massiv.begin() + massiv.size()/2);
	//std::sort(massiv.begin(), massiv.end());
*/
