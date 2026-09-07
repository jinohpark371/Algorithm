#include <iostream>
#include <climits>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long n;
		cin >> n;
		long long ans = LLONG_MAX;
		//약수 짝 중 작거나 같은 쪽 찾기
		for (long long j = 1; j * j <= n; j++) {
			if (n % j == 0) {
				long long r = n / j;
				ans = min(ans, (j - 1) + (r - 1));
			}
		}

		cout << '#' << i+1 << ' ' << ans << '\n';
	}
}