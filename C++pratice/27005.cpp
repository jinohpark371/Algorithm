#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;

	
	for (int j = 0; j < t; j++) {
		int n;
		cin >> n;

		vector<int> A(1000, 0);
		A[0] = 1;
		A[1] = 1;

		for (int i = 2; i <= n; i++) {
			//i번째 항에 들어간 후보 값
			int num = 1;
			while (true) {
				bool ok = true;
				for (int k = 1; k <= i / 2; k++) {

					//i번째 항에 num값이라고 가정 후 조건 계산
					if (num - A[i - k] == A[i - k] - A[i - 2 * k]) {
						ok = false;
						break;
					}
				}
				//모든 k에 대해서 등차수열 조건 성립x 일시
				//i번째항 현재 후보값으로 결정
				if (ok) {
					A[i] = num;
					break;
				}
				//조건 미성립시 후보값 증가
				num++;
			}

			
		}

		cout << A[n] << '\n';
	}
	return 0;
}