#include <iostream>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long a, b;
		cin >> a >> b;

		// A는 증가만 가능하고 B는 감소만 가능하므로 A > B이면 불가능
		if (a > b) {
			cout << "#" << i + 1 << " " << -1 << '\n';
			continue;
		}

		long long diff = b - a;

		// 차이가 1이면 2 또는 3만큼만 조작할 수 있으므로 불가능
		if (diff == 1) {
			cout << "#" << i + 1 << ' ' << -1 << '\n';
			continue;
		}

		// 차이가 짝수이면 2씩 조작하는 것이 최대 횟수
		if (diff % 2 == 0) {
			cout << "#" << i + 1 << " " << diff / 2 << '\n';
		}
		// 차이가 홀수이면 3을 한 번 사용하고 나머지는 2씩 조작한 횟수
		else {
			cout << "#" << i + 1 << " " << (diff - 1) / 2 << '\n';
		}
	}
}