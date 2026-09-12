#include <iostream>
using namespace std;

bool is_compositeNumber(int x, int y) {
	if (x <= 2 || y <= 2) return false;
	
	bool xIsVaild = false;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			xIsVaild = true;
			break;
		} 
	}

	bool yIsVaild = false;
	for (int i = 2; i < y; i++) {
		if (y % i == 0) {
			yIsVaild = true;
			break;
		}
	}

	return xIsVaild && yIsVaild;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int x = 2 + n;
		int y = 2;

		while (!is_compositeNumber(x, y)) {
			x++; y++;
		}

		cout << '#' << i + 1 << ' ' << x << ' ' << y << '\n';
	}
}