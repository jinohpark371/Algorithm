#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> seq;
void DFS(int depth) {
	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//매 탐색마다 첫번쨰 수부터 탐색
	for (int i = 1; i <= n; i++) {
		seq[depth] = i;
		DFS(depth + 1);
	}
}

int main() {
	cin >> n >> m;
	seq.assign(n + 1, 0);
	DFS(0);
}