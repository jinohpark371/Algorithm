#include <iostream>
#include <string>
using namespace std;

int main() {
	string original;
	cin >> original;

	if (original.size() == 1) {
		original = '0' + original;
	}

	string s;
	int count = 0;
	s = original;
	do {

		//각 자릿수의 합
		int num = (s[0] - '0') + (s[1] - '0');
		string temp = "";
		//제일 오른쪽 1의 자리 수
		//합한 수의 오른쪽 1의 자리수 합치기
		temp.push_back(s[1]);
		temp.push_back((num % 10) + '0');
		s = temp;
		count++; //싸이클 증가

	} while (original != s);

	cout << count;
	return 0;
}