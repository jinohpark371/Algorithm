#include <iostream>
using namespace std;

int arr[100001];
int freq[100001] = { 0 };

int main() {

	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}

	long long answer = 0;
	int L = 1;
	int R = 1;

	while (R < n + 1) {
		//아직 중복되지 않고 처음 나온 숫자
		if (!freq[arr[R]]) {
			freq[arr[R]]++; //누적 횟수 1증가
			answer += (R - L) + 1; //R이 고정일떄 현재 R까지의 연속된 수열의 경우의 수
			R++; //오른쪽 범위 증가
		}
		//이미 나온 숫자
		else if (freq[arr[R]] >= 1) {
			//중복을 없앨떄까지 왼쪽 범위를 계속 줄여감
			freq[arr[L]]--;// 해당 숫자 중복확인 배열에서 제거
			L++;//  왼쪽에서부터 범위 감소
		}
	}
	cout << answer;

	return 0;
}