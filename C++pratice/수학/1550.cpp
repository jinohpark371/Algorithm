#include <iostream>
using namespace std;

int main() {
	int answer = 0;
	int digit = 1;
	string s;
	cin >> s;

	//각 자리는 16의 거듭제곱 가중치를 가짐,  
	//현재 자리 가중치에 맞게 16의 거듭제곱 가중치를 곱하고
	//누적해서 더함
	for (int i =s.length()-1; i >= 0; i--) {
		if (s[i] >= '0' && s[i] <= '9') {
			answer+= (s[i] -'0') *digit;
		}
		else {
			answer += (s[i] - 'A' + 10) * digit;
		}
		//가중치 증가
		digit *= 16;
	}

	cout << answer;
}