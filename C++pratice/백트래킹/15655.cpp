#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<int> vec;
vector<int> seq;

void DFS(int st, int depth) {
	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = st; i < n; i++) {
		seq[depth] = vec[i];
		DFS(i + 1, depth + 1);
	}
}

int main() {
	cin >> n >> m;
	vec.assign(n, 0);
	seq.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	DFS(0, 0);
}