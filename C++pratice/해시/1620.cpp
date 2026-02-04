#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unordered_map<int, string> mmap1;
	unordered_map<string, int> mmap2;
	cin.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 1; i < n + 1; i++) {
		string pocketmon;
		cin >> pocketmon;
		mmap1[i] = pocketmon;
		mmap2[pocketmon] = i;
	}

	while (m--) {
		string s;
		cin >> s;
		
		bool isNum = true;
		for (auto c : s) {
			if (!isdigit(c)) {
				isNum = false;
				break;
			};
		}

		if (isNum) {
			cout << mmap1[stoi(s)] << '\n';
		}
		else {
			cout << mmap2[s] << '\n';
		}


	}

}