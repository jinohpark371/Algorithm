#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		//a, b 둘중 하나 1이거나 같을때 처리
		if (a == 1 || b == 1) {
			cout << max(a, b) << '\n';
			continue;
		}
		if (a == b) {
			cout << a << '\n';
			continue;
		}

		int num1 = 0;
		int num2 = 0;
		if (a > b) {
			num1 = a;
			num2 = b;
			while (num1 != num2) {
				num2 += b;
				if (num1 < num2) num1 += a;
			}
			cout << num2 << '\n';
		}
		//a < b
		else {
			num1 = b;
			num2 = a;
			while (num1 != num2) {
				num2 += a;
				if (num1 < num2) num1 += b;
			}
			cout << num2 << '\n';
		}


	}
}