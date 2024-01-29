#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <string>
using namespace std;

void delay(int seconds) {

    clock_t start_time = clock();

    while ((clock() - start_time) / CLOCKS_PER_SEC < seconds)
        ;
}
int main() {
    char a;
    int seconds = 1;
    
    setlocale(LC_ALL, "Russian");
    ifstream file("ask.txt");
    
    int b = 0, n = 1, m = 5, lvl = 1, z = 0, sum = 0;
    string line;
    char ans[] = { 98, 98, 99, 98, 99, 97, 97, 98, 97, 98,
                   98, 98, 98, 98, 99, 99, 97, 99, 97, 97,
                   98, 97, 98, 97, 98, 98, 97, 98, 97, 99,
                   97, 97, 97, 97, 98, 97, 98, 98, 98, 97,
                   99, 97, 97, 97, 97, 98, 99, 97, 97, 97,
                   98, 97, 97, 97, 97, 98, 99, 98, 97, 98,
                   98, 97, 97, 98, 98, 98, 98, 98, 97, 98,
                   98, 99, 99, 97, 97, 97, 98, 99, 97, 99 };

    for (int j = 0; j < 8; j++) {
        cout << "Уровень " << lvl << endl;
        cout << "Чтобы перейти на следующий уровень, необходимо ответить как минимум на 8 из 10 вопросов правильно" << endl;
        for (int g = 0; g < 10; g++) {
            system("color 07");
            for (int i = n; i < m; i++) {
                getline(file, line);
                cout << line << endl;
            }
            cout << endl << "Введите ответ: ";
            cin >> a;
            if (ans[z] == a) {
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
                cout << endl << "Правильно!" << endl;
                b++;
                z++;
            }
            else {
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handle, FOREGROUND_RED);
                cout << endl << "Неправильно(" << endl;
                z++;

            }
            n += 4;
            m += 4;
            delay(seconds);
            system("cls");
        }
        lvl++;
        
        if (b < 8 and j != 7) {
            system("color 07");
            cout << "Игра окончена, вы не набрали необходимое количество баллов(" << endl;
            cout << "Вы набрали " << b << " баллов из 8 необходимых для прохождения в следующий уровень" << endl;
            break;
        }
        if(b >= 8 and j != 7) {
            cout << "Поздравляем! Вы набрали " << b << " баллов из 10 и переходите на следующий уровень!" << endl;
            b = 0;
            sum++;
        }
        

    }
    system("color 07");
    cout << "Поздравляем! Вы прошли все 8 уровней и набрали " << sum << " баллов из 80 возможных!";
    cout << endl;
}