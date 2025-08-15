#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
string board[1000];
int dist1[1000][1000];
int dist2[1000][1000];
int r, c;

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }


    for (int i = 0; i < r; i++) {
        //�� �� -1�� ä���
        fill(dist1[i], dist1[i] + c, -1);
        fill(dist2[i], dist2[i] + c, -1);
    }

    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            //���� �ʱ� ���� �� �߰�, �������� �ʱ�Ÿ� 0
            if (board[i][j] == 'F') {
                dist1[i][j] = 0;
                q1.push({ i, j });
            }
            //�������� �ʱ� ������ �߰�, �������� �ʱ�Ÿ� 0
            if (board[i][j] == 'J') {
                dist2[i][j] = 0;
                q2.push({ i, j });
            }
        }
    }

    //�ҿ� ���� bfs�� �� �̵������� �� ��ǥ�� ���ؼ� �ִ� �ð����
    while (!q1.empty()) {
        auto cursor = q1.front(); q1.pop();

        //���� ���� ��ǥ�� ���� ���
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cursor.X;
            int ny = dy[dir] + cursor.Y;

            //���� ���� �˻�
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            //�� ���� �˻�
            if (board[nx][ny] == '#') continue;
            //���� �湮���� �ʾҴٸ� 
            if (dist1[nx][ny] == -1) {
                dist1[nx][ny] = dist1[cursor.X][cursor.Y] + 1;
                //�ش� ��ǥ �湮�� ���� ť�� �߰�
                q1.push({ nx, ny });
            }
        }
    }


    //�����̿� ���� bfs�� �� ��ǥ�� ���� ���ް����� �ִ� �ð����
    while (!q2.empty()) {
        auto cursor = q2.front(); q2.pop();

        //���� ���� ��ǥ�� ���� ���
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cursor.X;
            int ny = dy[dir] + cursor.Y;

            //���� ���� �˻�
            //������  �����ٸ� �����ſ� ���� +1�ð��߰��Ͽ� Ż��ð� ���
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                cout << dist2[cursor.X][cursor.Y] + 1;
                return 0;
            }


            //�� ���� �˻�
            if (board[nx][ny] == '#') continue;
            //�̹� �湮 
            if (dist2[nx][ny] != -1) continue;

            //�� ������ �̵��� ��ǥ�� ���� ���� �ð�
            int nt = dist2[cursor.X][cursor.Y] + 1;

            //�ش� ��ǥ�� ���� ���� �ϰ�
            // ���� �ش� ��ǥ���� �Ұ� ���ų� �� ���� �ð��� ��ٸ� �ش� ��ǥ �湮 �Ұ�
            if (dist1[nx][ny] != -1 && nt >= dist1[nx][ny]) continue;
            //�ش���ǥ�� �Һ��� ���� �ð��� �����Ƿ� ��ǥ���� �ɸ��� �ð� �߰�
            dist2[nx][ny] = nt;
            //ť�� push�Ͽ� ���� �湮 �غ�
            q2.push({ nx, ny });

        }
    }
    //�ð��� ������� ���ϰ� ������� �Դٸ� �����̴� Ż�� �Ұ���
    cout << "IMPOSSIBLE";
    return 0;
}
