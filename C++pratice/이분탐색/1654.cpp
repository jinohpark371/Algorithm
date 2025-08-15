#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;

	vector<long long> len(n);

	for (int i = 0; i < k; i++) cin >> len[i];

	//자를 수 있는 길이의 최소 길이
	long long low = 1;
	//자를 수 있는 길이의 최대 길이
	// max_element는 iterator 반환하므로 *로 참조값 반환
	long long high = *max_element(len.begin(), len.end());

	//정답이 될 수 있는 길이
	long long answer = 0;
	while (low <= high) {
		//중간 길이
		long long mid = (low + high) / 2;
		//각 랜선마다 조각낸 선들의 갯수
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += len[i] / mid;
		}
		//자른 선들의 갯수가 원하는 갯수n보다 크다면
		//지금 현재 자를려는 길이 mid보다  더 큰 범위에서
		//길이를 선택할 수 있음 현재 mid는 정답 후보로 선택
		// 또 다시 이 조건에 만족되는 길이 mid가 나온다면 항상 answer은 최대로 갱신
		if (cnt >= n) {
			answer = mid;
			low = mid + 1;
		}
		//자른 선들의 갯수가 원하는 갯수 n개보다 작다면
		//선의 길이를 줄여야 함으로 현재 중간 길이 보다 더 작은 범위에서
		//탐색 진행
		else {
			high = mid - 1;
		}

	}

	//탐색을 끝마치고 나온 answer은 항상 최대 길이
	cout << answer;
	//탐색범위를 절반씩 줄이는 이분탐색의 핵심
	return 0;
}

