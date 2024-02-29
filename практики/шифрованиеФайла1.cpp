// deti.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string fileName = "input.txt";

/*



*/
void taskOne(int n) {
    ifstream in(fileName);
    if (!in.is_open()) {
        cout << "error"; return;
    }
    int tmp;
    for (int i = 0; i < n; i++)
    {
        in >> tmp;
        cout << tmp << " ";
    }
    in.close();
}
int readMas(int mas[], int size) {
    ifstream in(fileName);
    if (!in.is_open()) {
        cout << "error"; return -1;
    }
    int n;
    in >> n;
    for (int i = 0; i < n &&i < size ; i++)
    {
        in >> mas[i];
    }

    in.close();
    return n;
}

void read_int(int &a) {
    ifstream in(fileName);
    if (!in.is_open()) {
        cout << "error"; return;
    }

    in >> a;
    in.close();
}

void SHA(vector<char>& file_bin, int delta) {
    /*for (auto& ch : file_bin) {
        ch += delta;
    }*/
    for (int i = 0; i < file_bin.size(); i++)
    {
        file_bin[i] += delta;
    }
}

int main()
{
   //1. побитово считать файл
    fstream file("aboba.txt", fstream::in | fstream::binary );
    if (!file.is_open()) {
        cout << "Achtung!";
        return 0;
    }
    vector<char> file_bin;
    char tmp;
    while (file >> tmp) {
        file_bin.push_back(tmp);
    }

    cout << "size of file: " << file_bin.size();

    // 2. измучать каждый байт файла (зашифровать)
   
    file.close();

    SHA(file_bin, 5);


    // 3. записать шифрованные данные в файл

    file.open("aboba.txt", fstream::out | fstream::binary);
    if (!file.is_open()) {
        cout << "Error!";
        return 0;
    }


    for (int i = 0; i < file_bin.size(); i++)
    {
        file << file_bin[i];
    }
    file.close();

}
