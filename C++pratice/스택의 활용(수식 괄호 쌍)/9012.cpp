#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	string str;
	stack<int> s;
	cin >> n;
	while (n--) {
		cin >> str;
		
		while (!s.empty()) s.pop();

		bool isVaild = true;
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			if (str[i] == '(') {
				s.push(c);
			}
			else {
				if (s.empty() || s.top() != '(') {
					isVaild = false;
					break;
				}
				s.pop();
			}
		}

		if (!s.empty()) isVaild = false;
		cout << (isVaild ? "YES" : "NO") << '\n';
	}
	return 0;
}