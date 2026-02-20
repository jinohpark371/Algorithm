#include <iostream>
using namespace std;

int col[15] = { 0 };
int inc[30] = { 0 };
int decc[30] = { 0 };
int n;
int cnt = 0;

//양의 기울기(같은 대각선)에 포함되어 있는 좌표는 행+열 번호가 일정
//음의 기울기(같은 대각선)에 포함되어 있는 좌표는
//행-열 번호가 일정 양수로 만들기 위해 (n-1) 더하기

void DFS(int row) {
	//모든 행에 퀸을 놓았을때 경우의 수 증가
	if (n == row) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		//열검사 및 대각선 검사(양의 기울기 방향과 음의 기울기 방향)
		if (!col[i] && !inc[row + i] && !decc[(n - 1) + (row - i)]) {
			col[i] = 1; //해당 열 사용 중 기록
			inc[row + i] = 1; //양의 방향 대각선 사용 중 기록
			decc[(n - 1) + (row - i)] = 1;//음의 방향 대각선으로 해당 대각선 사용 중 기록

			//다음 행 탐색
			DFS(row + 1);

			col[i] = 0;//해당열 사용 중 취소
			inc[row + i] = 0; //양의 방향 대각선 사용 중 취소
			decc[(n - 1) + (row - i)] = 0;//음의 방향 대각선으로 해당 대각선 사용 중 취소

		}

	}
}

int main() {
	cin >> n;
	DFS(0);

	cout << cnt;
	return 0;
}