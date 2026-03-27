#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int n, target;
		cin >> n >> target;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			q.push({ num, i });
			pq.push(num);
		}

		int order = 1;
		while (!q.empty()) {
			auto [cur, idx]= q.front(); q.pop();

			if (cur == pq.top()) {
				pq.pop();
				if (idx == target) {
					cout << order << '\n';
					break;
				}
				order++;

			}
			else {
				q.push({ cur, idx });
			}
		}
	}
}