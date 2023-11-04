// алгоритм Брезенхема 
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// W A S D 
	// W
	// (0;1)
	// D
	// (1;1)
	// X <- вызод exit
	char dir;
	int x, y;

	x = 0;
	y = 0;
	// w W
	do {
		cin >> dir;
		switch (dir)
		{
		case 'w':
		case 'W':
			y += 1;
			break;
		case 'S':
			y -= 1;
			break;
		case 'A':
			x -= 1;
			break;
		case 'D':
			x += 1;
			break;
		case 'X':
			cout << "exit";
			break;
		default:
			cout << "durak chtole\n";
			break;
		}
		cout << "(" << x << ";" << y << ")\n";
		
	} while (dir != 'X');
}
