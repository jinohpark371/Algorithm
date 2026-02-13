#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


bool cmp(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	set<string> st;
	vector<string> vec;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (!st.count(s)) {
			st.insert(s);
			vec.push_back(s);
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
	return 0;
}