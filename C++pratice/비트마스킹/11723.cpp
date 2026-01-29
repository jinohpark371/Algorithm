#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;
	bool s[21] = { false };
	while (m--) {
		int num;
		string command;
		cin >> command;
		if (command == "add") {
			s[num] = true;
		}
		else if (command == "remove") {
			cin >> num;

			if (s[num]) {
				s[num] = false;
			}
		}
		else if (command == "check") {
			cin >> num;

			if (s[num]) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (command == "toggle") {
			cin >> num;

			if (s[num]) {
				s[num] = false;
			}
			else {
				s[num] = true;
			}
		}
		else if (command == "all") {
			for (int i = 1; i <= 20; i++){
				s[i] = true;
			}
		}
		else if (command == "empty") {
			for (int i = 1; i <= 20; i++) {
				s[i] = false;
			}
		}

	}
}