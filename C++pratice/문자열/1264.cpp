#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	string vowel = "aeiou";
	string sentence;
	while (true) {
		getline(cin, sentence);
		if (sentence == "#") break;
		int cnt = 0;
		for (char c : sentence) {
			if (vowel.find(tolower(c)) != string::npos) {
				cnt++;
			}
		}

		cout << cnt << '\n';
	}
	

}