#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<char> vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
		}


		map<char, int> mp;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int A = 0; int T = 0; int C = 0; int G = 0;

			for (int j = i; j < n; j++) {
				if (vec[j] == 'A') A++;
				else if (vec[j] == 'T') T++;
				else if (vec[j] == 'C') C++;
				else G++;

				if (A == T && C == G) cnt++;
			}
		}

		cout << cnt << '\n';
	}
}