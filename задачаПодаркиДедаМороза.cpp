//https://acmp.ru/index.asp?main=task&id_task=317
#include <vector>
#include <iostream>
using namespace std;

int x, y, z, w;

void pod(int a, int b, int c,  vector<vector<int>> &vec) {
    if (a * x + b * y + c * z == w) {
      //  cout << a << " " << b << " " << c << "\n";

        // проверяем, есть ли такой элемент в нашем двумернорм массиве. vector<int>{ a,b,c } создает вектор, который и сравнимаем 
        if(count(vec.begin(), vec.end(), vector<int>{ a,b,c })==0)
            vec.push_back({a,b,c});
        return;
    }
    if (a * x + b * y + c * z > w) return;

    pod(a + 1, b, c,  vec);
    pod(a, b + 1, c,  vec);
    pod(a, b, c + 1,  vec);
}

int main()
{
    cin >> x >> y >> z >> w;
    vector<vector<int>> vec(0, vector<int>(3));
    pod(0, 0, 0, vec);
    cout << vec.size();
}
