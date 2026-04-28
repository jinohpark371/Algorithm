#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	vector<int> ans;
	int cnt = 0;
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		ans.push_back(q.front());
		q.pop();
	}

	cout << '<';
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) cout << ", ";
		cout << ans[i];
	}
	cout << '>';

	return 0;
}