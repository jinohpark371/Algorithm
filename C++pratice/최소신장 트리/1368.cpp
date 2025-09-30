#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> parent(304, -1);
vector<tuple<int, int, int>> edge;

int find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = find(parent[a]);
	}
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int w;
		cin >> w;
		edge.push_back({ w, i, n + 1 });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			if (i < j) {
				edge.push_back({ w, i, j });
			}
		}
	}

	sort(edge.begin(), edge.end());

	for (int i = 1; i <= n + 1; i++) parent[i] = i;


	int ans = 0;
	for (auto [w, u, v] : edge) {
		if (find(u) != find(v)) {
			Union(u, v);
			ans += w;
		}
	}

	cout << ans;
	return 0;
}