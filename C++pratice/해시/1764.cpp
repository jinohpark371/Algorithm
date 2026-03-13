#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >>n >> m;
	
	set<string> notListen;
	set<string> notSee;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		notListen.insert(s);
	}

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		notSee.insert(s);
	}

	vector<string> vec;
	for (auto nl : notListen) {
		if (notSee.count(nl)) vec.push_back(nl);
	}

	cout << vec.size() << '\n';
	for (string s : vec) cout << s << '\n';

}