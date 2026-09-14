#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> T(n, vector<int>(m, 0));
		vector<int>a(n, 0);
		vector<int>b(m, 0);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				T[i][j] = s[j] - '0';
			}
		}
		//a[0]은 0으로 고정
		a[0] = 0;
		//b배열 계산
		for (int j = 0; j < m; j++) {
			b[j] = T[0][j] ^ a[0];
		}
		//a배열 계산
		for (int i = 0; i < n; i++) {
			a[i] = T[i][0] ^ b[0];
		}
		//검증
		bool isValid = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(  T[i][j] != (a[i] ^ b[j])){
					isValid = false;
					break;
				}
			}
		}

		if (isValid) {
			cout << '#' << i + 1 << ' ' << "yes" << '\n';
		}
		else {
			cout << '#' << i + 1 << ' ' << "no" << '\n';
		}
	}
}