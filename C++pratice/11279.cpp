#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	priority_queue<long long> pq;
	cin >> n;
	while (n--) {
		long long num;
		cin >> num;
		if (num != 0) {
			pq.push(num);
		}
		else {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
	}
	return 0;
}