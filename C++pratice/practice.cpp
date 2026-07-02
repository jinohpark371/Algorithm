#include <iostream>
#include <vector>

using namespace std;

int main() {
	int test_case;
	cin >> test_case;
	
	for (int i = 0; i < test_case; i++) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<bool> problems(n, true);

		//뒤에서 부터 k칸마다 틀림처리
		int miss = n-m;
		for (int i = n-k; i >=0; i-=k) {
			if (miss > 0) {
				problems[i] = false;
				miss--;
			}

			if (miss == 0) break;
		}

		//남은 틀린문제 앞에서부터 채우기
		for (int i = 0; i< n && miss>0; i++) {
			if (problems[i]) {
				problems[i] = false;
				miss--;
			}
		}

		//초기 카운터
		int counter = 0;
		//초기 점수
		int total = 0;

		//점수 계산
		for (int i = 0; i < n; i++) {
			if (problems[i]) {
				total++;
				counter++;
				if (counter == k) {
					total = total * 2;
					counter = 0;
				}
			}
			else {
				counter = 0;
			}
		}

		cout << "#" << i +1 << ' ' << total << '\n';
	}

}