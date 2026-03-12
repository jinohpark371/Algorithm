#include <iostream>
#include <string>
using namespace std;

bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) return false;
	return true;
}

bool isPalindrome(int num) {
	string s = to_string(num);

	int len = s.length()/2;
	for (int i = 0; i < len; i++) {
		if (s[i] != s[s.length() - 1 - i]) return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = n; ; i++) {
		if (isPrime(i) && isPalindrome(i)) {
			cout << i;
			break;
		}
	}
}