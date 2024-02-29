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

void shifrate(const string& file_name, int d);

int main()
{
    cout << "-input file name: ";
    string file_name;
    cin >> file_name;

   //1. побитово считать файл
   
    int r;
    cout << "\n-input type of operation: \n\tshifrate(1) or deshifrate(2)?\n-";
    cin >> r;

    cout << "\n-input key: ";
    int d;
    cin >> d;
    if (r == 2) d *= -1;

    shifrate(file_name, d);

}

void shifrate(const string& file_name, int d)
{

    fstream file(file_name, fstream::in | fstream::binary);
    if (!file.is_open()) {
        cout << "Achtung!";
        return;
    }

    streampos size;
    file.seekg(0, ios::end); // прыгаем в конец файла
    size = file.tellg(); // узнаем номер позиции (конца в нашем случае)
    file.seekg(0, ios::beg);// возвращаемся в начало

    vector<char> file_bin(size);
    //
    char* bin = new char[size]; // создаем динамический массив чаров
    // file.read(bin, size);

    file.read(file_bin.data(), size); // читаем size байт в массив


    /*
        char tmp;
        while (file >> tmp) {
            file_bin.push_back(tmp);
        }
        */
        //  cout << "size of file: " << file_bin.size();

          // 2. измучать каждый байт файла (зашифровать)

    file.close();

    SHA(file_bin, d);

    //file.read(file_bin.data(), _размерФайла_);

    // 3. записать шифрованные данные в файл

    file.open(file_name, fstream::out | fstream::binary);
    if (!file.is_open()) {
        cout << "Error!";
        return;
    }


    for (int i = 0; i < file_bin.size(); i++)
    {
        file << file_bin[i];
    }
    file.close();

}
