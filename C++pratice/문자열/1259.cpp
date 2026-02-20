#include <iostream>
using namespace std;

int main() {
	string s;
	while (true) {
		cin >> s;
		if (s == "0") break;
		bool valid = true;
		for (int i = 0; i < s.length()/2; i++) {
			if (s[i] != s[s.length() - i - 1]) {
				valid = false;
				break;
			}
		}
		if (!valid) {
			cout << "no" << '\n';
		}
		else {
			cout << "yes" << '\n';
		}
	}
}