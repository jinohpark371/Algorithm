#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int dx[4] = { 0 , 0, -1 ,1 }; //���� ��ǥ: �� ��
int dy[4] = { -1 , 1 , 0 , 0 }; //���� ��ǥ: �� ��
int min_distance[100][100] = { -1 }; //��� 1��ǥ �ּҰŸ�
queue<pair<int, int>> q;
int board[100][100]; //��ǥ�迭
int visited[100][100]; //�湮 ���� Ȯ�� �迭
int n, m;
string row;

void bfs() {
  
	while (!q.empty()) {
		pair<int, int>node = q.front(); q.pop();
		int x = node.first;
		int y = node.second;
		//���� ���� �湮 ó��
		visited[x][y] = true;
		//�¿���� ������ ���� ��ǥ���� 4������
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			//��ǥ�� ���
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			//���� �ִ� ��ǥ�̰� ���� �湮���� ���� ��ǥ���
			if (board[nx][ny] == 1 && !visited[nx][ny]) {
				//���� �ش� ��ǥ�� �ּҰŸ��� �������� �ʾҴٸ�
				if (min_distance[nx][ny] == -1) {
					//�湮ó��
					visited[nx][ny] =true;
					//���� ��ǥ�� �ּҰŸ����� �ڽű��� �Ÿ��� 1�� �����Ͽ� �ش���� ��ǥ �ּҰŸ� ���
					min_distance[nx][ny] = min_distance[x][y]+1;
					//ť�� push
					q.push({ nx, ny });
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> row;
		for (int j = 0; j < m; j++) {
			//string( 1,row[j]):���� row[j]�� ���� 1 ¥�� ���ڿ��� ����
			board[i][j] = stoi(string( 1,row[j]));
		}
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			min_distance[i][j] = -1;

	//������ 1ĭ �̵����� ����
	min_distance[0][0] = 1;
	q.push({ 0,0 });
	bfs();

	//���� ���� ���µ� �ɸ��� �ּ� ĭ
	cout << min_distance[n-1][m-1];
	return 0;
}