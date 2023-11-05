#include <iostream>
 
using namespace std;
 
int main()
{
	long long a, b;
	cin >> a >> b;
	long long c = 0, ans=0;
	if (b <= a / 2 + a%2) {
		ans = 1 + (b - 1) * 2;
		
	}
	else {
		c += a / 2 + a % 2;
		ans = (b - c) * 2;
	}
	cout << ans;
}
