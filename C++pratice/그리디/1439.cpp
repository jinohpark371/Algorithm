#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int zeroCnt = 0, oneCnt = 0;
	
	//각 숫자에 대한 연속된 덩어리 세기
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
				if (i != 0 && s[i - 1] == '0') continue;
				zeroCnt++;
		}
		if (s[i] == '1') {
				if (i != 0 && s[i - 1] == '1') continue;
				oneCnt++;
		}
	}
	

	//더 적은 덩어리가 최소 뒤집기 횟수
	cout << min(zeroCnt, oneCnt);
	return 0;
}

/*
다른 방식
int zeroCnt = 0, oneCnt = 0;

// 첫 문자 처리
if (s[0] == '0') zeroCnt++;
else oneCnt++;

for (int i = 1; i < s.length(); i++) {
	if (s[i] != s[i - 1]) {
		if (s[i] == '0') zeroCnt++;
		else oneCnt++;
	}
}
*/