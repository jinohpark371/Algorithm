#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2000000000

int main() {
	int n;
	long m;
	cin >> n >> m;
	vector<long long> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	//왼쪽 구간 끝 인덱스
	int left = 0;

	sort(vec.begin(), vec.end());
	long long mindiff = MAX;

	//왼쪽 구간 끝인덱스에서 오른쪽 구간 끝 인덱스 구간에서
	//m이상되는 두 인덱스를 찾음
	for (int right = 0; right < n; right++) {
		long diff =  vec[right] - vec[left];
		//m이 0일때 left는 벡터인덱스 초과
		while (diff >= m && left<right) {
			//현재 알고 있는 최솟값과 현재 구해진 최솟값을 비교하여 최솟값을 갱신
			mindiff = min(mindiff, vec[right] - vec[left]);
			//오른쪽 포인터 확장 → 조건 만족 시 왼쪽 포인터 축소
			//다음 차이값으로 최솟값 갱신을 위한 비교
			left++;
			diff= vec[right] - vec[left];
		}
	}

	cout << mindiff;
	return 0;
}