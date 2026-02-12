#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> answer;
int N, M;

void DFS(vector<int> &seq, vector<int> &visited) {
	string out;
	if (answer.size() == M) {
		//현재까지 중복되지 않는 선택된 수열 출력
		for (int i = 0; i < answer.size(); i++) {
			out+= to_string(answer[i]) +' ';
		}
		out += '\n';
		cout << out;
		return;
	}


	for (int i = 0; i < seq.size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			answer.push_back(seq[i]);
			DFS(seq, visited);
			//백트래킹
			visited[i] = 0;
			answer.pop_back();
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<int> seq(N, 0);
	vector<int> visited(N, 0);
	for (int i = 1; i <= N; i++) {
		seq[i-1]=i;
	}

	DFS(seq, visited);
}