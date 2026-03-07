#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	double maxScore = 0;
	double sum = 0;

	for (int i = 0; i < n; i++) {
		double num; cin >> num;
		sum += num;
		maxScore = max(maxScore, num);
	}

	cout << (sum  * 100) /  (maxScore* n);
}