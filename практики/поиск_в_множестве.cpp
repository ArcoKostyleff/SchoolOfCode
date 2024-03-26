// пример решения задачи работы со множеством чисел. То есть поиск, добавление и удаление 
// элементов множества.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// множество произвольных чисел.  операции: проверки, добавления, удаления
// хэш-функция -h(x) = x%S. По умолчанию - S = 10
// идея - массив списков. индексы массива - числа о 0 до S. к каждому индексу соотносится массив(список), 
// в котором лежат числа множества, значение хэш-функции (в нашем случае остаток от деления на S)
// которого равно индексу массива.  
class m {
    int m_size{ 10 };
    vector<vector<int>> m_list;
    int hash(int a) {
        return a % m_size;
    }
public:
    m(int size = 10): m_size(size) {
        m_list.resize(m_size, vector<int>());
    }
    void add(int a) {
        int h = hash(a);
        if(!is_in(a)) m_list[h].push_back(a);
    }
    bool is_in(int a) {
        int h = hash(a);
        if(count(m_list[h].begin(), m_list[h].end(), a) ==0) return false;
        else return true;
    }
    void del(int a) {
        int ind = hash(a);
        if (count(m_list[ind].begin(), m_list[ind].end(), a) == 0) return;
        m_list[ind].erase(find(m_list[ind].begin(), m_list[ind].end(), a));
    }
    void print() {
        cout << "\n--------\n";
        for (int i = 0; i < m_list.size(); i++)
        {
            cout << i << ": ";
            for (int j = 0; j < m_list[i].size(); j++)
            {
                cout << m_list[i][j] << " ";
            }cout << "\n";
        }
    }
};

int main()
{
    m ch(2);
    cout << "add 17 to m\n";
    ch.add(17);
    cout << "add 87 to m\n";
    ch.add(87);
    cout << "add 20 to m\n";
    ch.add(20);
    cout << "add 10 to m\n";
    ch.add(10);
    cout << "27 in m: " << ch.is_in(27) << "\n";
    cout << "add 27 to m\n";
    ch.add(27);
    cout << "27 in m: "<<ch.is_in(27);
    ch.print();
    ch.del(87);
    cout << "del 87 from m\n";
    ch.print();

}
