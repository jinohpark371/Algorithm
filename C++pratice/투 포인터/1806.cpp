#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int sum = 0;
	int end = 0;
	int md = MAX;
	// 윈도우: [start, end)   (end는 항상 한 칸 뒤를 가리킴)
// sum == vec[start .. end-1] 의 합을 유지한다.
	for (int start = 0; start < n; start++) {
		// 확장 단계: 합이 s 미만이면 end를 늘려 조건(sum >= s)을 만족시킨다.
		while (end < n && sum < s) {
			sum += vec[end];
			end++;
		}
		// 조건 만족 시 현재 윈도우 길이로 최소 길이를 갱신한다.
		if (sum >= s) {
			md = min(md, end - start);// 길이는 end-start (end는 한 칸 뒤)
		}
		//앞쪽구간을 줄이며 목표 합보다 크거나 같을땐 길이를 갱신 할 수 있도록 한다.
		sum -= vec[start];
	}
	
	//만약 전체 원소의 합이 목표합보다 계속 작다면 md는 한번도 갱신되지 않는다
	cout << (md == MAX ? 0 : md);

	return 0;
}