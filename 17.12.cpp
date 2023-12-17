#include <iostream>

using namespace std;

int main()
{
    int vector[10];

        for (int ix = 0; ix < 10; ix++)
            cin >> vector[ix];

    for (int ix = 0; ix < 10; ix++)
        cout << vector[ix] << endl;

    return 0;
}