#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int prevnode[1000001];
int dist[1000001];
int main() {
	int n;
	cin >> n;
	
	queue<int> q;
	dist[n] = 0;
	prevnode[n] = -1; // 시작점은 이전 노드 없음

	q.push(n);

	while (!q.empty()) {
		int cursor = q.front(); q.pop();
		if (cursor == 1) break;

		if (cursor % 3 == 0 && dist[cursor/3] ==0) {
			dist[cursor / 3] = dist[cursor] + 1;
			q.push(cursor / 3);
			prevnode[cursor / 3] = cursor;
		}
		if (cursor % 2 == 0 && dist[cursor / 2] == 0) {
			dist[cursor / 2] = dist[cursor] + 1;
			q.push(cursor / 2);
			prevnode[cursor / 2] = cursor;

		}
		if (cursor - 1 > 0 && dist[cursor - 1] == 0) {
			dist[cursor -1] = dist[cursor] + 1;
			q.push(cursor - 1);
			prevnode[cursor -1] = cursor;

		}

	
	}
	vector<int> path;
	for (int cur = 1; cur != -1; cur = prevnode[cur]) {
		path.push_back(cur);
	}

	reverse(path.begin(), path.end());

	cout << dist[1] << "\n";

	
	for (int x : path) {
		cout << x << " ";
	}


	return 0;
}