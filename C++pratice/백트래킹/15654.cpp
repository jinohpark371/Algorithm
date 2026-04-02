#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> seq;
vector<int> visited;
int n, m;

void DFS(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			seq[depth] = vec[i];
			visited[i] = 1;
			DFS(depth + 1);
			visited[i] = 0;
		}
		
	}
}


int main() {
	cin >> n >> m;
	vec.assign(n, 0);
	seq.assign(m, 0);
	visited.assign(n, 0);

	for (int i = 0; i < n; i++) cin >> vec[i];

	sort(vec.begin(), vec.end());

	DFS(0);
}