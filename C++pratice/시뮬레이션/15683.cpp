#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { -1 , 0, 1 ,0 }; //하 좌 상 우 순으로 검사
int dy[4] = { 0, 1, 0, -1 };
int board1[8][8]; //원본
int board2[8][8]; //복사본
vector<pair<int, int>> cctv; // cctv좌표 저장 벡터
int n, m;

//경계 여부 검사
bool oob(int a, int b) {
	return a < 0 || b < 0 || a >= n || b >= m;
}

void upd(int x, int y, int dir) {
	//방향은 0~3번 밖에 없음
	//ex)2번이 dir이 3번일때(3번 회전)왼쪽 (dir+1)%4 =1 오른쪽
	dir %= 4;
	while (1) {
		//dir은 한번 정해진다면 해당 방향으로 볼 수 있는 영역을 계속 늘림
		x += dx[dir];
		y += dy[dir];
		//벽이나 경계에 걸린다면 더이상 탐색 x
		if (oob(x, y) || board2[x][y] == 6) return;

		//시시티비이거나 감시영역 7이라도 계속 탐색 가능
		if (board2[x][y] != 0) continue;
		//해당 영역을 감시영역으로 칠하기
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
	//각각의  cctv는 4번씩 회전할 수 있기에 모든 경우의 수는 4의 시시티비의 갯수의 제곱
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
		
		//원본이 아닌 복사본으로 항상 시시티비가 볼 수 있는 영역 탐색ㄴ
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board2[i][j] = board1[i][j];

		
		
		int bust = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			//4진수의 각 자리가 CCTV 하나의 방향(0,1,2,3)이라고 생각하면
			//0부터 4^k-1까지 세면서 4진수로 바꾸는 건 결국 **각 칸(자리)**을 차례대로 채워나가는 거고
			//빠짐없이 모든 경우의 수(=모든 방향 조합)가 한 번씩 다 나오게 됨
			int dir = bust % 4;
			bust /= 4;
			
			int x = cctv[i].first;
			int y = cctv[i].second;

			//cctv가 dir쪽을 보고 있을 때
			//다른 방향으로 볼 수 있는 cctv라면 해당 방향으로도 탐색 실행
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

		//그동안 탐색했던 영역을 바탕으로 사각지대 계산후
		//사각지대 최솟값 비교 및 갱신
		int val = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				val += (board2[i][j] == 0);
		mn = min(mn, val);
	}

	cout << mn;
	return 0;
}

