#include <iostream>
#include <climits>
using namespace std;

char board[50][50];

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
		}
	}

	int startRow = 0, startCol = 0, mmin=INT_MAX;
	//시작 범위의 최대범위까지만 탐색
	while(startRow <= n - 8 && startCol <= m - 8) {
		//흰 검 패턴에 따른 칠해야 하는 횟수
		int Wcount = 0, Bcount = 0;
		//시작행열에 따른 끝범위
		int endRow = startRow + 8, endCol = startCol + 8;
		
		//시작 흰색일때 칠해야 하는 횟수 카운트
		for (int i = startRow; i < endRow; i++) {
			for (int j = startCol; j < endCol; j++) {
				if ((i - startRow + j - startCol) % 2 == 0) {
					if (board[i][j] != 'W') Wcount++;
				}
				else {
					if (board[i][j] != 'B') Wcount++;
				}
			}
		}
		//검정이 시작 패턴일때 칠해야 하는 횟수
		for (int i = startRow; i < endRow; i++) {
			for (int j = startCol; j < endCol; j++) {
				if ((i - startRow + j - startCol) % 2 == 0) {
					if (board[i][j] != 'B') Bcount++;
				}
				else {
					if (board[i][j] != 'W') Bcount++;
				}
			}
		}
		//두 가정 중 작은 것 선택 후
		//각 범위에서 최소 횟수 갱신
		int BWCount = min(Wcount, Bcount);
		mmin = min(mmin, BWCount);

		//다음 탐색 범위로 이동
		startCol++;
		//열초과시 다음 행으로 이동 후 열 초기화
		if (startCol > m - 8) {
			startCol = 0;
			startRow++;
		}

	}

	cout << mmin;

}