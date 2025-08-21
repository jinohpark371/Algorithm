#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrims[4000000];

int main() {
	int n;
	cin >> n;

	vector<int> prims;
	for (int i = 2; i <= n; i++) isPrims[i] = true;


	/*
	제곱근까지만 검사하는 이유는  m = a × b 일때 한쪽 인수(a 또는 b)는 √m 이하
	따라서 n 이하의 합성수를 전부 지우려면
	√n까지만 소수 i를 돌려도 충분
	*/

	for (int i = 2; i <= sqrt(n); i++) {

		if (!isPrims[i]) continue;
		//항상 자기 자신 숫자 다음 배수부터 소수후보에서 제외
		//항상 소수의 배수는 소수가 아니기 때문에 n이전값까지 제외
		//작은 소수의 배수부터 처리한다면 그 다음으로 큰 소수 i 는 
		// i*2, i*3, i*(i-1) 이전 값은 이미 지워졌으므로  i*i부터 지우면 됨
		// ex)예: 3×2 = 6 → 이미 2단계에서 지워짐, 5×2 = 10 → 이미 2단계에서 지워짐

		for (int j = i * i; j <= n; j += i) {

			isPrims[j] = false;
		}
	}

	/*비효율적인 방법
	* 이미 지웠던 부분까지 모든 검사를 계속 진행하고 있음
	for (int i = 2; i <= sqrt(n); i++) {
	for (int j = 2; i*j <= n; j++) {
		if (i * j == i) continue;
		isPrims[i * j] = false;
	}
	}*/

	for (int i = 2; i <= n; i++) {
		if (isPrims[i]) prims.push_back(i);
	}

	int L = 0, R = 0;
	int cnt = 0;
	int sum = 0;
	while (true) {
		if (sum >= n) {
			if (sum == n) cnt++;
			sum -= prims[L++];
		}
		else {
			if (R == prims.size()) break;
			sum += prims[R++];
		}
	}

	cout << cnt;

	return 0;

}