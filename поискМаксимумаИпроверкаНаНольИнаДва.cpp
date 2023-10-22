// lesson3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
void foo();
int main()
{
    /*
        найти максимум в введенной последовательности из натуральны][ чисел
    */

    // вводим пока не ввели '0'
    /*
    int max = 0; // самое маленькое возможное (на 1 мменьше)

    int tmp = 1;
    // 1 2 5 2 0 5 2 asd jjasndas
    while (cin >> tmp && tmp != 0) {
        if (tmp > max) max = tmp;

    }
    cout << max;
    // второй вариант
    do {
        cin >> tmp;

    } while (tmp != 0);
    */
    
    // ищем максимум пока не ввели 0 0

    bool secondZero = false; // 0

    int max = -1;
    int tmp;
    bool konec = false;
    while (!konec) {
        cin >> tmp;

        if (tmp == 0) {
            if (secondZero == true) {
                konec = true;
                //break; // !!!!!!!!!!!!!!!!!!!!!!!!1
            }
            else if (secondZero == false) secondZero = true;
        }
        else {
            secondZero = false;
            if (tmp > max) max = tmp;
        }
    }
    cout << max;


}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
void foo() {
    this_thread::sleep_for(chrono::milliseconds(500));
    system("start https://youtu.be/dQw4w9WgXcQ");
}
