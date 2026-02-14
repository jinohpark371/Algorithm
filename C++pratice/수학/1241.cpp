#include <iostream>
#include <vector>
using namespace std;

int main() {
	const int MAX = 1000000;
	int N;
	cin >> N;
	vector<int> freq(MAX + 1, 0);
	vector<int> cnt(MAX + 1, 0);
	vector<int> seq;
	for (int i =0; i < N; i++) {
		int num;
		cin >> num;
		//해당 숫자가 나온 빈도 저장
		freq[num]++;
		//출력 순서 보장을 위해 입력 저장
		seq.push_back(num);
	}

	for (int d = 1; d <= MAX; d++) {
		if (freq[d] == 0) continue;
		//m은 d의 배수이므로  d가 출현한 횟수를
		// 각 m에 누적해서 더해줌
		//m이 d를 치는 관계임
		for (int m = d; m <= MAX; m += d) {
			cnt[m] += freq[d];
		}

	}
	//입력 순서대로 출력
	//본인 제외 ( -1)
	for (int i = 0; i < seq.size(); i++) {
		cout << cnt[seq[i]] - 1 << '\n';
	}

}