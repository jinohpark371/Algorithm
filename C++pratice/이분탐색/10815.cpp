#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int> vec1(n);
	for (int i = 0; i < n; i++) {
		cin >> vec1[i];
	}

	cin >> m;
	vector<int> vec2(m);

	for (int i = 0; i < m; i++) {
		cin >> vec2[i];
	}

	sort(vec1.begin(), vec1.end());

	for (int item : vec2) {
		cout << binary_search(vec1.begin(), vec1.end(), item) << " ";
	}

	return 0;
}