#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);

	for (int i = 0; i < n; i++) cin >> coins[i];

	//동전의 종류에서 목표 금액보다 처음으로 작은 동전 확인
	int i = n-1;
	while (coins[i] > k) {
		i--;
	}

	//처음으로 작은 동전 부터 목표 금액 채우기
	int count = 0;
	for (int j = i; j >= 0; j--) {
		//현재 동전 갯수 누적
		count += k / coins[j];
		//현재 채운 금액 빼기
		k -= (k / coins[j])*coins[j];
		//목표금액을 다 채울시 break
		if (k == 0) break;

	}

	cout << count;
	
}