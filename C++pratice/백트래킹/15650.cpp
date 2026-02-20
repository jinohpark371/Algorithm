#include <iostream>
using namespace std;

int n, m;
int seq[9];

void DFS(int st, int depth) {

	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = st; i <= n; i++) {
		seq[depth] = i; //수열 현재위치 채우기
		//현재값 다음 값부터 다음 수열 위치에 들어올 수 있는 값 탐색
		DFS(i + 1, depth + 1);


	}

}


int main() {
	cin >> n >> m;
	DFS(1, 0);
	return 0;
}