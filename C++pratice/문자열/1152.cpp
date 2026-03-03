#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		//단어 조건:첫번째 단어에서 현재문자가 공백이 아니고 i가 0일때
		//현재문자가 공백이 아니고 이전 문가 공백일때
		if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) cnt++;
	}

	cout << cnt;
	return 0;
	


}