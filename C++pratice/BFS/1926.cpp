#include <iostream>
#include <algorithm>
using namespace std;

/*
DFS Ž�� ����
� �� ������ �����Ѵ� (dfs(x, y) ȣ��)

�� ������ **�� �� �ִ� ����(�����¿�)**�� �ϳ��� ���ɴ�

�� �� �ִٸ�, �� �������� ��� ���� ���� (dfs(nx, ny) ȣ��)

�� �̻� �� �� ���� ������ �����ϸ� �� ��Ͱ� ����ǰ� ���� �ڸ��� ���ƿ´�

���ƿ� ������ ���� ������� �ٽ� ���ɴ�

��� ������ �� Ž�������� �� ������ ����ǰ� ó�� ȣ���� dfs()�� ��ȯ
*/
int dx[4] = { 0 , 0, -1, 1 }; //���Ϲ���
int dy[4] = { -1, 1, 0 , 0 }; //�¿����
int board[500][500] = { 0 }; //��ȭ�� 
int visited[500][500] = { 0 };//�湮����ǥ�ù迭
int n, m;

int dfs(int x, int y) {
	visited[x][y] = true;
	int area = 1;
	//���� ��ǥ����  �¿��ϻ� �̵�
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		//��ǥ�� ���� ��ȭ�� ũ�⸦ �Ѿ�ٸ� �ٽ� ��ǥ���
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		//��� ������ �����ߴµ� ���̻� ��ȿ���� ��ǥ�� ���ų� �湮���� ���� ��ǥ�� ���ٸ�
		//�׵��� ���� ��͸� ������ area���� ��͸� ó�� ȣ���� dfs�Լ�����
		//area���� ������ ���� �޾� ��ȯ
		if (board[nx][ny] == 1 && !visited[nx][ny]) {
			//��͸� ���� ���� ��ǥ�� �̵� 
			area += dfs(nx, ny);
		}
	}
	return area;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

		}
	}

	int picturecount = 0;
	int maxarea = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				//���� ��ǥ���� ���� ����ũ����
				int area = dfs(i, j);
				//������ ���� ����
				picturecount++;
				//������ �ִ� ���� ���
				maxarea = max(maxarea, area);
			}
		}
	}

	cout << picturecount << "\n" << maxarea;

	return 0;
}

