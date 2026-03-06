#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;
vector<int> d;

int dist(pair<int, int> p1, pair<int, int> p2) {
	int dx = p1.first - p2.first;
	int dy = p1.second - p2.second;

	return dx * dx + dy * dy;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 4; i++) {
			int x, y;
			cin >> x >> y;
			vec.push_back({ x, y });
		}
		
		//각 점으로 만들 수 있는 모든 직선 6개 거리 측정
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				d.push_back(dist(vec[i], vec[j]));
			}
		}

		//정렬시 네변은 [0] ~[3]에 존재, 두 대각선은 끝에 존재
		sort(d.begin(), d.end());

		//네변끼리 같고 두 개각선(네 변 보다 더큼)이 서로 같다면 정사각형
		if (d[0] > 0 &&
			d[0] == d[1] &&
			d[1] == d[2] &&
			d[2] == d[3] &&
			d[4] == d[5]) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}

		vec.clear();
		d.clear();
	}
}