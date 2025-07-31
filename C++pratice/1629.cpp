#include <iostream>
using namespace std;

long long mod_pow(long long a, long long b, long long c) {
	if (b == 0) return 1;
	long long half = mod_pow(a, b / 2, c);
	long long result = (half * half) % c;
	if (b % 2 == 1) result = (result * a) % c;
	return result;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
    cout << mod_pow(a, b, c);
	return 0;
}