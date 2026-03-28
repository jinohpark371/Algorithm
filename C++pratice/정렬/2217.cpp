#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;


	vector<int> vec(n);
	int mmin = 10001;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	//정렬을 해야 현재 로프를 최소 로프로 확정할 수 있음
	sort(vec.begin(), vec.end());
	
	int ans = 0;
	//현재 최소 하중을 가진 로프를 기준으로 최대 무게를 계산
	//최대 무게 비교 후 갱신
	//로프 조합을 따지는게 중요한게 아닌 현재 로프 조합에서 최소 로프,
	//즉 모든 로프 조합에서 각 로프가 최소가 될때를 계산
	for (int i = 0; i < n; i++) {
		int weight = vec[i] * (n - i);
		ans = max(ans, weight);
	}

	cout << ans;
	return 0;
}
