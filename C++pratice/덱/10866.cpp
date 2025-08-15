#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int n, num;
	string commend;
	deque<int> dq;
	cin >> n;
	while (n--) {
		cin >> commend;
		if (commend == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (commend == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (commend == "pop_front")
		{
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (commend == "pop_back")
		{
			if (!dq.empty()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (commend == "size") {
			cout << dq.size() << endl;
		}
		else if (commend == "empty") {
			cout << dq.empty() << endl;
		}
		else if (commend == "front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (commend == "back") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
			}
			else {
				cout << -1 <<endl;
			}
		}
	}
}