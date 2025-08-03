#include <iostream>
using namespace std;

/*
재귀를 통해 2차원 좌표를 항상 4등분하며,
현재 배열 크기의 절반(half)과 현재 좌표(r, c)를 비교해
해당 사분면으로 이동할 수 있도록 좌표를 조정한다.

그 후 n을 1 감소시켜, 해당 사분면 내에서 다시 같은 방식으로
분할 탐색이 가능하도록 한다.

만약 n이 0이 되어 더 이상 4등분이 불가능해지면,
그동안 거쳐온 사분면의 시작 인덱스를 모두 누적해 더한 값을 반환하여
전체 배열에서 (r, c)가 몇 번째로 방문되는지를 계산한다.
*/

int solve(int n, int r, int c) {
	if (n == 0) return 0;

	// << 비트 이동 연산자
	// <<는 왼쪽 쉬프트
	// 1 << k는 왼쪽으로 1을 k비트 이동 하여
	//2^k와 같게 됨
	int half = 1 << (n - 1);
	int area = half * half;

	if (r < half && c < half) {
		return solve(n - 1, r, c); //제 1사분면은 좌표 그대로
	}
	else if (r < half && c >= half) {
		return area + solve(n - 1, r, c - half); //제 2사분면으로 c값 지역 좌표 조정
	}
	else if (r >= half && c < half) {
		return 2 * area + solve(n - 1, r - half, c); //제 3사분면으로 r값 지역 좌표 조정
	}
	else return 3 * area + solve(n - 1, r - half, c - half); //제 4사분면으로 r, c값 지역 좌표 조정
}


int main() {
	int n, r, c;
	cin >> n >> r >> c;

	cout << solve(n, r, c);
	return 0;
}