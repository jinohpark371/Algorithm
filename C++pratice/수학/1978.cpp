#include <iostream>
using namespace std;

bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	while (n--) {
		int num;
		cin >> num;
		if (isPrime(num)) cnt++;
	}

	cout << cnt;
	return 0;
}