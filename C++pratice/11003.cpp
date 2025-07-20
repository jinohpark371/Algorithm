#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
	int n, l;
	cin >> n >> l;
	deque<pair<int, int>> dq;

	for (int i = 0; i < n; i++) {
		int now;
		cin >> now;

		while (!dq.empty() && dq.back().first > now) {
			dq.pop_back();
		}

		dq.push_back({ now, i });

		if (dq.front().second <= i - 1) {
			dq.pop_front();
		}

		cout << dq.front().first << " ";
	}
	return 0;
}