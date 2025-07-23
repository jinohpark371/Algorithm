#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	int count = 0;
	while (n--) {
		string num;
		cin >> num;
		stack<char> s;
		for (char c : num) {
			if (!s.empty() && s.top() == c) {
				s.pop();
			}
			else {
				s.push(c);
			}
		}

		if (s.empty()) count++;
	}

	cout << count;

}

