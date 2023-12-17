// дополни код так, чтобы вводился массив на 10 чисел и выводился (каждый элемент массива с новой строки) = +
#include <iostream>
using namespace std;
int main()
{
    int vector[10];
    for (int ix = 0; ix < 10; ix++){
        cin >> vector[ix];
    }
    for (int ix = 0; ix < 10; ix++){
        cout << vector[ix] << endl;
    }
    return 0;
}
