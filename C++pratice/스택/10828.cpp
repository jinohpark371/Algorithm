#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int n, m;
	stack<int> s;
	string commend;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> commend;
		if (commend == "push") {
			cin >> m;
			s.push(m);
		}
		else if (commend == "pop") {
			if (!s.empty()) {
				cout << s.top() << endl;
				s.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (commend == "size") {
			cout << s.size() << endl;
		}
		else if (commend == "empty") {
			cout << s.empty() << endl;
		}
		else if (commend == "top") {
			if (!s.empty()) {
				cout << s.top()<< endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
}