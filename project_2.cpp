#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;
using namespace sf;
struct rectang {
    int n = 0;
    RectangleShape rectanglee;
};
int o = 0;
int mytime;
const int sizemas = 50;
int random;
rectang doubler;
sf::RenderWindow window(sf::VideoMode(1000, 600), "");
rectang mas[sizemas];

void correct() {
    window.clear();
    for (int i = 0; i <= sizemas; i++) {
        for (int k = 0; k < sizemas; k++) {
            if (k < i) {
                mas[k].rectanglee.setFillColor(sf::Color::Green);
            }
            else {
                mas[k].rectanglee.setFillColor(sf::Color::White);
            }
            window.draw(mas[k].rectanglee);
        }
        window.display();
        Sleep(5);
        window.clear();
    }
}

void render(int n, int k, int quicksort) {
    window.clear();
    for (int i = 0; i < sizemas; i++) {
        if (i == n) {
            mas[i].rectanglee.setFillColor(sf::Color::Red);
        }
        if (i == k) {
            mas[i].rectanglee.setFillColor(sf::Color::Blue);
        }
        if (i == quicksort) {
            mas[i].rectanglee.setFillColor(sf::Color::Blue);
        }
        mas[i].rectanglee.setPosition(Vector2f(i * 20, 600 - (12 * mas[i].n)));
        window.draw(mas[i].rectanglee);
        if (i == n) {
            mas[i].rectanglee.setFillColor(sf::Color::White);
        }
        if (i == k) {
            mas[i].rectanglee.setFillColor(sf::Color::White);
        }
        if (i == quicksort) {
            mas[i].rectanglee.setFillColor(sf::Color::White);
        }
    }
    window.display();
    if (quicksort != -1) {
        Sleep(50);
    }
    else {
        Sleep(30);
    }
}
void selectionsort()
{
    auto begin = chrono::steady_clock::now();
    int i, j, min_idx;
    for (i = 0; i < sizemas - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < sizemas; j++)
            if (mas[j].n < mas[min_idx].n) {
                min_idx = j;
                render(j, min_idx, -1);
            }
            else {
                render(-1, -1, -1);
            }
        swap(mas[min_idx], mas[i]);
    }
    auto end = chrono::steady_clock::now();
    mytime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}
void gnomesort() {
    auto begin = chrono::steady_clock::now();
    for (int i = 0; i < sizemas; i++) {
        int k;
        for (k = 0; k < i + 1; k++) {
            if (mas[i].n < mas[k].n) {
                doubler = mas[k];
                mas[k] = mas[i];
                mas[i] = doubler;
                render(k, i, -1);
            }
            else {
                render(-1, -1, -1);
            }
            ++o;
        }
    }
    auto end = chrono::steady_clock::now();
    mytime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}

void bubblesort() {
    auto begin = chrono::steady_clock::now();
    for (int i = 0; i < sizemas - 1; i++) {
        int k;
        for (k = 0; k < sizemas - 1 - i; k++) {
            if (mas[k].n > mas[k + 1].n) {
                doubler = mas[k + 1];
                mas[k + 1] = mas[k];
                mas[k] = doubler;
                render(k, k + 1, -1);
            }
            else {
                render(-1, -1, -1);
            }
            ++o;
        }
    }
    auto end = chrono::steady_clock::now();
    mytime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}

void randomizer() {
    for (int i = 0; i < sizemas; i++) {
        mas[i].rectanglee.setSize(Vector2f(20, ((i + 1) * 12)));
        mas[i].rectanglee.setFillColor(sf::Color::White);
        mas[i].n = i + 1;
    }
    for (int i = 0; i < sizemas; i++) {
        random = rand() % sizemas + 0;
        doubler = mas[(int)random];
        mas[(int)random] = mas[i];
        mas[i] = doubler;
    }
    render(-1, -1, -1);
}
void quicksort(int low, int high) {
    auto begin = chrono::steady_clock::now();
    if (low < high) {
        int pivot = mas[high].n;
        int i = low;
        int j = low;
        while (i <= high) {
            if (mas[i].n > pivot) {
                i++;
            }
            else {
                doubler = mas[i];
                mas[i] = mas[j];
                mas[j] = doubler;
                i++;
                j++;
            }
            render(i, pivot, j);
            ++o;
        }
        j -= 1;
        int pos = j;
        quicksort(low, pos - 1);
        quicksort(pos + 1, high);
    }
    auto end = chrono::steady_clock::now();
    mytime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}

int main() {
    setlocale(LC_ALL, "Russian");
    char ch, chr;
    HWND window_header = GetConsoleWindow();
    SetWindowPos(window_header, HWND_TOP, 890, 600, 500, 200, NULL);
    randomizer();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        system("color 70");
        cout << "\n   'g'- gnome sort;\n   'b'- bubble sort;\n   'q' - quick sort.\n\n   ---------\n       ";
        cin >> ch;
        window.clear();
        if (ch == '0') {
            system("cls");
            cout << "\n    Bye!";
            return 0;
        }
        system("cls");
        cout << "\n   'f' - data from file;\n   'r' - random data.\n    ";
        cin >> chr;
        if (chr == 'r') {
            randomizer();
        }
        if (chr == 'f') {
            render(-1, -1, -1);
            ifstream fin("File.txt");
            int tmp = 0;
            for (int i = 0; i < sizemas; ++i) {
                fin >> tmp;
                mas[i].n = tmp;
                mas[i].rectanglee.setSize(Vector2f(20, ((tmp + 1) * 12)));
                mas[i].rectanglee.setPosition(Vector2f(i * 20, 600 - (12 * mas[i].n)));
                mas[i].rectanglee.setFillColor(Color::White);
                window.draw(mas[i].rectanglee);
                cout << mas[i].n << endl;
            }
        }
        if (ch == 'b') {
            bubblesort();
        }
        if (ch == 'q') {
            quicksort(0, sizemas - 1);
        }
        if (ch == 'g') {
            gnomesort();
        }
        if (ch == 's') {
            selectionsort();
        }
        correct();
        system("cls");
        std::cout << "\n   " << mytime;
        cout << "\n\n\n   O = " << o;
        Sleep(1500);
        system("cls");
        o = 0;
    }
}