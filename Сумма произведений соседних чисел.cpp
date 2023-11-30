#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	int i = 1;
	int ans = 0;
	while (i  < n-1) {
		ans += i * (i + 1);
		cout << i << "*" << i + 1<<"+";
		i++;
	}
	cout << i << "*" << i + 1 << "=";
	ans += i * (i + 1);
	cout << ans;

}
