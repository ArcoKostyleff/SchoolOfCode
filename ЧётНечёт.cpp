#include <iostream>
int main() { long long n, k;std::cin >> n >> k; if (k > (n + n % 2) / 2) std::cout << (k - ((n + n % 2) / 2)) * 2; else std::cout << k * 2 - 1; }
