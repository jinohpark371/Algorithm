#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> alphabet(26, 0);

int main() {
	string s;
	while (getline(cin, s)) {
		for (char c : s) {
			if (c == ' ') continue;
			int num = c - 'a';
			alphabet[num]++;
		}
	}

	int maxVal = INT_MIN;
	for (int i = 0; i < alphabet.size(); i++) {
		maxVal = max(maxVal, alphabet[i]);
	}

	for (int i = 0; i < alphabet.size(); i++) {
		if (maxVal == alphabet[i]) {
			cout << char(i + 'a');
		}
	}
	return 0;
}