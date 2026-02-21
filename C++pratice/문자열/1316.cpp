#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	cin >> t;

	string s;
	int cnt = 0;
	while (t--) {
		bool visited[26] = { 0 };
		cin >> s;

		bool valid = true;
		visited[s[0]-'a'] =1;
		for (int i = 1; i < s.length(); i++) {
			if (s[i - 1] != s[i]) {
				// 이전 문자와 현재 문자가 다를떄
				// 이전에 방문한 문자인지 확인
				//방문한적 있다면 그룹단어 X
				if (visited[s[i] - 'a']) {
					valid = false;
					break;
				}
			}
			visited[s[i] - 'a'] = true;
		}

		if (valid) cnt++;
	}

	cout << cnt;
	return 0;
}