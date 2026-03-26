#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		vector<pair<int, int>> vec;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int grade1, grade2;
			cin >> grade1 >> grade2;
			vec.push_back({ grade1, grade2 });
		}

		sort(vec.begin(), vec.end());

		int cnt = 1;
		int minScore = vec[0].second;

		//현재 인원은 면접시험 성적만 본인 이전 인원들한테서만 이기면 됨
		//앞사람 중에서 가장 잘한사람(최소 순위)만 이기면 전체를 이긴 것과 같음
		for (int i = 1; i < n; i++) {
			if (vec[i].second < minScore) {
				cnt++;
				minScore = vec[i].second;
			}
		}

		cout << cnt << '\n';
	}
}