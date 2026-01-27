#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}

	int L = 1, R = 1;
	int answer = 0;
	int oddCount = 0, evenCount = 0; //삭제 횟수와 연속된 짝수 수열 길이와 같음
	while (R  <= n) {
		//짝수 갯수(수열 크기) 증가
		if (arr[R] % 2 == 1) oddCount++;
		else evenCount++; //홀수 (삭제 횟수) 증가

		//삭제 횟수 초과시
		while (oddCount > k) {
			//왼쪽 범위 감소하면서 현재 구간의 짝수나 홀수 갯수 감소
			if (arr[L] % 2 == 1)oddCount--;
			else evenCount--;
			L++;
		}
		
		//최댓 수열의 길이(짝수 횟수) 파악
		answer = max(answer, evenCount);
		R++;//범위 증가
	}
	
	cout << answer;
	return 0;
}