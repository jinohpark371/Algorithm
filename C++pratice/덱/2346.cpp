#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n;
	cin >> n;

	deque<pair<int, int>> dq;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		dq.push_back({ num, i + 1 });
	}

	while (!dq.empty()) {
		auto[ cur, idx] = dq.front(); 
		cout << idx << ' ';
		dq.pop_front();
		if (dq.empty())break;

		if (cur > 0) {
			for (int i = 0; i < cur - 1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i <abs(cur); i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}

	}

}