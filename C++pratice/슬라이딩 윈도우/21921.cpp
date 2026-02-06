#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int mmax = 0;
	int count = 0;
	int sum = 0;
	int st = 0; //앞쪽 인덱스
	for (int en = 0; en < n ; en++) {
		sum += vec[en];

		//윈도우 크기가 x가 되었을때
		if(en-st+1 == x){
			//기존에 알고 있는 최대값보다 더 큰 합 발견시
			if (sum > mmax) {
				mmax = sum; //구간의 최대합 갱신
				count = 1; //최대 합의 구간의 수 초기화
			}
			//기존의 최대값과 합이 같다면 카운트 증가
			else if (mmax == sum) {
				count++;
			}

			//앞쪽 구간 빼주기
			sum -= vec[st];
			st++;//다음  앞쪽 범위
		}
	}

	if (mmax == 0) {
		cout << "SAD";
	}
	else {
		cout << mmax << endl;
		cout << count;
	}

	return 0;
}