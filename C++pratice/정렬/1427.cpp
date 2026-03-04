#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

bool cmp(int a, int b) {
	return a > b;
	
}

int main() {
	string s;
	cin >> s;
	for (char c : s) {
		vec.push_back(c - '0');
	}
	sort(vec.begin(), vec.end(), cmp);

	for (int v : vec) {
		cout << v;
	}

	return 0;
}