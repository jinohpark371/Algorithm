#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_map<string, string> mp;
	while (n--) {
		string site, password;
		cin >> site >> password;

		mp[site] = password;
	}

	while (m--) {
		string site;
		cin >> site;
		cout << mp[site] << '\n';
	}

	return 0;
}