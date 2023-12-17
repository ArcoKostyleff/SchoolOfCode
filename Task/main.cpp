// дополни код так, чтобы вводился массив на 10 чисел и выводился (каждый элемент массива с новой строки)
#include <iostream>

using namespace std;
int main()
{
    int vector[10]{};

    for (int ix = 0; ix < 10; ix +=1) cin >> vector[ix];

    for (int ix = 0; ix<10; ix+=1)
        cout << vector[ix] << "\n";

    return 0;
}
