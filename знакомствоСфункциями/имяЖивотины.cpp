
#include <iostream>
using namespace std;
#define sizem 100

int ch = 4;

void hello() {
    cout << "privet Slavik!\n";
    //return;
}

int countOfDigits(int a) {
    a = ch;
    int count = 0;
    while (a) {
        a /= 10;
        count++;
    }
    return count;
}
 
// вывести животинку от количества ног
// nameOfAnimal ( countOfLegs ) -> print name 
void nameOfAnimal(int countOfLegs) {
    // ...
    /*
     если 0 - то змея
     если ноги 2 - то это школьник
     если 4 - то это собакен
     если 6 - то брандаршмыг
     если 8 - то павук
     иначе - чупакабра 
    */
    switch (countOfLegs) {
    case 0:
        cout << "snake tssss\n";
        break;
    case 2:
        cout << "schooler veiippppp\n";
        break;
    case 4:
        cout << "doggy bark bark\n";
        break;
    case 6:
        cout << "ebaka \n";
        break;
    case 8:
        cout << "pavuk where my Mary Jane\n";
        break;
    default:
        cout << "nu pipetz u tebya chubaka ....teryasya, brat\n";
    }
}
int main()
{
    int n;
    cin >> n;
    /*
    есть N животинок. Вводится количество ног
    для каждой 
    если 0 - то змея
    если ноги 2 - то это школьник
    если 4 - то это собакен
    если 6 - то брандаршмыг
    если 8 - то павук
    иначе - чупакабра 
    */
    int legs;
    for (int i = 0; i < n; i++) {
        cin >> legs;
        nameOfAnimal(legs);
    }
        
    return 0;

}
