#include <iostream>
#include <vector>
using namespace std;

int adj[100][100];
int answer[100][100] = { 0 };
int visited[100] = { 0 };
int n;

//현재 시작 위치와 DFS 탐색을 진행한 위치
void DFS(int start, int cur) {
	
	for (int i = 0; i < n; i++) {
		//이동한 정점에서 연결된 다른 정점을 찾고 아직 미방문이라면
		if (adj[cur][i] == 1 && !visited[i]) {
			visited[i] = 1;
			//시작 정점에서 해당 i번째 정점까지는 연결됨
			answer[start][i] = 1;
			//해당 i번쨰로 이동해서 탐색 다시 진행
			DFS(start, i);
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
		
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) visited[j] = 0; //DFS 탐색후 방문 배열 초기화
		DFS(i, i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

