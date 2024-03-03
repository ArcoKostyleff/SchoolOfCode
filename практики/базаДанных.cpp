// deti.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void shifrate(const string& file_name, int d);

void shr(int mas[], int n, int d) {
    for (int i = 0; i < n; i++)
    {
        mas[i] += d;
    }
}

void spravka() {
    cout << "1. вывести список абобусов\n" <<
        "2. найти абобуса с фамилией(выведет его номер в таблице)\n" <<
        "3. добавить абобуса\n" <<
        "4. удаление абобуса\n" <<
        "5. обновить базу\n" <<
        "x. выход\n";
}

void printAllAbobus(vector<string> &mas) {
    for (int i = 0; i < mas.size(); i++)
    {
        cout << "\t" << i + 1 << ") " << mas[i] << "\n";
    }
}

// заполняем массив всем, что есть в файле - то есть считываем из файла всех абобусов
void fillVector(fstream &file, vector<string> &mas) {
    mas.clear();
    string s;
    while (file >> s) {
        mas.push_back(s);
    }

}

void fillFile(fstream& file, const string name, vector<string>& mas) {
    file.close();
    file.open(name, fstream::in | fstream::out | fstream::trunc); /// trunc очищает файл

    for (int i = 0; i < mas.size(); i++)
    {
        file << mas[i] << "\n";
    }

}

void deleteAbobus(fstream& file, const string name, vector<string>& mas, int n) {
    if (n <= mas.size()) {
        mas.erase(mas.begin() + n - 1);
        fillFile(file, name, mas);
    }
}
void update(fstream& file, const string name, vector<string>& mas) {
    file.close();
    file.open(name, fstream::in | fstream::out | fstream::app);

    fillVector(file, mas);
}
int main()
{
    setlocale(LC_ALL, "russian");
    const string filename = "abobuss.txt";
    // открываем файловый поток на чтение + запись в конец
    fstream file(filename, fstream::in | fstream::out | fstream::app);
    if (!file.is_open())cout << "error - no such file!";
    //int mas[4];
    vector<string> mas; // список абобусов

    /*
    1. вывести список абобусов +
    2. найти абобуса с фамилией (выведет его номер в таблице)
    3. добавить абобуса
    4. удаление абобуса
    5. обновить базу
    x. выход
    */
    fillVector(file, mas);
    char c;
    bool exit = false;
    string s;
    int tmp;
    while (!exit) {
        spravka();
        cin >> c;
        switch (c)
        {
        case('1'): {
            printAllAbobus(mas);
            break;
        }
        case('2'): {
            
            cout << "кого ищем? ";
            cin >> s;
            // find(mas.begin(), mas.end(), s);
            for (int i = 0; i < mas.size(); i++)
            {
                if (mas[i] == s) {
                    cout <<s << " имеет номер: " << i + 1 << endl;
                }
            }
            break;
        }
        case('3'): {
      
            cout << "введите фамилию нового абобуса: ";
            cin >> s;
            mas.push_back(s);
            file.clear(); // нужно чтобы писать после чтения
            file << s << "\n";
            break;
        }
        case('4'): {
            cout << "введите номер, кого удалять: ";
            cin >> tmp;
            deleteAbobus(file, filename, mas, tmp);
            cout << "deleted!\n";
            //TODO:

            break;
        }
        case('5'): {
            update(file, filename, mas);
            cout << "база обновлена!\n";
            break;
        }
        case('x'): {
            exit = true;
            cout << "досвидания!\n";
            break;
        }
        default:

            break;
        }
    }
    
    file.close();
}

//-----------
const string fileName = "input.txt";

void SHA(vector<char>& file_bin, int delta) {
    /*for (auto& ch : file_bin) {
        ch += delta;
    }*/
    for (int i = 0; i < file_bin.size(); i++)
    {
        file_bin[i] += delta;
    }
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
    for (int i = 0; i < n && i < size; i++)
    {
        in >> mas[i];
    }

    in.close();
    return n;
}

void read_int(int& a) {
    ifstream in(fileName);
    if (!in.is_open()) {
        cout << "error"; return;
    }

    in >> a;
    in.close();
}
