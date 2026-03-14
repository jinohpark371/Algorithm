#include <iostream>
using namespace std;


//마지막 타일이 00일땐 마지막 타일에서 n-2
// 위치전까지의 모든 타일을 놓는 경우의 수와
//마지막 타일이 1일땐 n-1 위치전까지의
//타일을 놓는 경우의 수의 합이 마지막 타일까지
//타일을 놓는 모든 경우의 수가 됨

int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}

	int a = 1, b = 2;
	int c = 0;
	for (int i = 3; i <= n; i++) {
		c = (a + b) % 15746;
		a = b;
		b = c;
	}

	cout << b;

}