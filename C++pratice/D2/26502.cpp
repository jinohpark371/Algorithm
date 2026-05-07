#include <algorithm>
#include <vector>
#include<iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, x, y;
		cin >> n;

		vector<pair<int, int>> vec;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			vec.push_back({ x, y });
		}
		int maxArea = 0;
		for (int i = 0; i < n; i++) {
			//직각점 기준
			pair<int, int> cur = vec[i];
			int max_x = 0;
			int max_y = 0;
			//현재 직각점 기준으로 두 변의 길이 최댓값 계산
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				if (cur.second == vec[j].second) max_x = max(max_x, abs(vec[j].first - cur.first));
				if (cur.first == vec[j].first) max_y = max(max_y, abs(vec[j].second - cur.second));
			}
			//두변 기준으로 넓이 계산 후 최대 넓이 갱신
			maxArea = max(maxArea, max_x * max_y);
		}

		cout << maxArea << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}