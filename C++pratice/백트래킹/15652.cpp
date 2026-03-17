#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> seq;


void DFS(int st, int depth) {
	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = st; i <= n; i++) {
		seq[depth] = i;
		DFS(i , depth + 1);
	}
}

int main() {
	cin >> n >> m;
	seq.assign(m, 0);
	DFS(1, 0);
}