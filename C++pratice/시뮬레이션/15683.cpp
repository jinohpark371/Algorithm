#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { -1 , 0, 1 ,0 }; //�� �� �� �� ������ �˻�
int dy[4] = { 0, 1, 0, -1 };
int board1[8][8]; //����
int board2[8][8]; //���纻
vector<pair<int, int>> cctv; // cctv��ǥ ���� ����
int n, m;

//��� ���� �˻�
bool oob(int a, int b) {
	return a < 0 || b < 0 || a >= n || b >= m;
}

void upd(int x, int y, int dir) {
	//������ 0~3�� �ۿ� ����
	//ex)2���� dir�� 3���϶�(3�� ȸ��)���� (dir+1)%4 =1 ������
	dir %= 4;
	while (1) {
		//dir�� �ѹ� �������ٸ� �ش� �������� �� �� �ִ� ������ ��� �ø�
		x += dx[dir];
		y += dy[dir];
		//���̳� ��迡 �ɸ��ٸ� ���̻� Ž�� x
		if (oob(x, y) || board2[x][y] == 6) return;

		//�ý�Ƽ���̰ų� ���ÿ��� 7�̶� ��� Ž�� ����
		if (board2[x][y] != 0) continue;
		//�ش� ������ ���ÿ������� ĥ�ϱ�
		board2[x][y] = 7;
	}
}


int main() {
	cin >> n >> m;
	int mn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 6 && board1[i][j] != 0) cctv.push_back({ i, j });

			if (board1[i][j] == 0) mn++;
		}
	}
	//������  cctv�� 4���� ȸ���� �� �ֱ⿡ ��� ����� ���� 4�� �ý�Ƽ���� ������ ����
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
		
		//������ �ƴ� ���纻���� �׻� �ý�Ƽ�� �� �� �ִ� ���� Ž����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board2[i][j] = board1[i][j];

		
		
		int bust = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			//4������ �� �ڸ��� CCTV �ϳ��� ����(0,1,2,3)�̶�� �����ϸ�
			//0���� 4^k-1���� ���鼭 4������ �ٲٴ� �� �ᱹ **�� ĭ(�ڸ�)**�� ���ʴ�� ä�������� �Ű�
			//�������� ��� ����� ��(=��� ���� ����)�� �� ���� �� ������ ��
			int dir = bust % 4;
			bust /= 4;
			
			int x = cctv[i].first;
			int y = cctv[i].second;

			//cctv�� dir���� ���� ���� ��
			//�ٸ� �������� �� �� �ִ� cctv��� �ش� �������ε� Ž�� ����
			if (board2[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (board2[x][y] == 2) {
				upd(x, y, dir);
				upd(x, y, dir+2);

			}
			else if (board2[x][y] == 3) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
			}
			else if (board2[x][y] == 4) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);

			}
			else {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);

			}

		}

		//�׵��� Ž���ߴ� ������ �������� �簢���� �����
		//�簢���� �ּڰ� �� �� ����
		int val = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				val += (board2[i][j] == 0);
		mn = min(mn, val);
	}

	cout << mn;
	return 0;
}

