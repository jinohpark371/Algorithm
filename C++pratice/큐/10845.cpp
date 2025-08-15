#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int n,m;
	queue<int> q;
	string commend;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> commend;
		if (commend == "push") {
			cin >> m;
			q.push(m);
		}
		else if (commend == "pop") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (commend == "size") {
			cout << q.size() << endl;
		}
		else if (commend == "empty") {
			cout << q.empty() << endl;
		}
		else if (commend == "front") {
			if (!q.empty()) {
				cout << q.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (commend == "back") {
			if (!q.empty()) {
				cout << q.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
}

