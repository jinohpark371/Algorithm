#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int binary_search(int st, int en, int total) {
	int answer =0;
	while (st <= en) {
		//기준 상한액
		int mid = (st + en) / 2;

		//배정금액계산
		int sum = 0;
		for (int v : vec) {
			sum += min(mid, v);

		}

		if (sum <= total) {
			st = mid + 1;
			//정답 후보 갱신
			answer = mid;
		}
		else {
			en = mid - 1;
		}
 	}

	return answer;
}

int main() {
	int n, sum, mmax, total;
	cin >> n;

	vec.assign(n, 0);
	sum = 0; mmax = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		//지방예산의 합
		sum += vec[i];
		//최대 지방 예산 갱신
		mmax = max(mmax, vec[i]);
	}

	cin >> total;

	//예산 계산
	if (sum <= total) {
		cout << mmax;
	}
	else {
		//최대 상한액
		cout << binary_search(0, mmax, total);
	}

	return 0;


}