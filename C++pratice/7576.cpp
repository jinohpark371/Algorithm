#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0 , 0, - 1, 1 };
int dy[4] = { -1, 1, 0 , 0 };
int board[1000][1000];
int n, m;
queue<pair<int, int>> q;


int bfs() {
    
    //������ ���ÿ� �ޱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                q.push({ i, j });
            }
           
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (board[nx][ny] == 0) {
                board[nx][ny] =board[x][y]+ 1; //���� ��ǥ���� ���� ��ǥ�� �̵������� 1�����Ͽ� �� ������ �����ϴ� �� �ɸ� �ܰ�(�ϼ�) ǥ��
                q.push({ nx, ny });
            }
        }
    }

    //��¥ ����� bfsŽ���� �����Ҷ����� �ڽ��� �¿� �ϻ� ��ǥ�� �ڽ��� �ܰ迡 1�� �����Ͽ� �����ܰ踦 ǥ���Ѵ�
    // ���� Ž�������� �ڽ��� ��ȿŽ�� ������ �ִ� ��ǥ���� �ڽ��� �ܰ迡 1�� �����Ͽ� ���� �ܰ� ǥ��.
    //ť�� �� ��� �Ǿ� Ž���� �����ϸ� ���⼭ ���� ū �ܰ�Ƚ���� ���� ��ǥ�� ���������� ���� �丶���̴�.
    int days = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //���� ���� �丶�� ����
            if (board[i][j] == 0) return -1;
            days = max(days, board[i][j]);
        }
    }
   

    // ���� ���� �丶���� ���� ��� �ϼ��δ� 0�� �� �̹Ƿ� 
    return days-1;

}

int main() { 
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int days=bfs();
    cout << days;
    return 0; 
}