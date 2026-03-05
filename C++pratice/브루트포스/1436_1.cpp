#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	//찾은 종말의 수 
	int cnt = 0;
	for (int i = 666; i < INT_MAX; i++) {
		string s = to_string(i);
		//연속으로 6이 나온 횟수
		int six = 0;
		for (int j = s.length()-1; j-1 >=0; j--) {
			if (s[j] == '6' && s[j - 1] == '6') {
				six++;
				//six가 2라면 666
				if (six >= 2) {
					//종말의 수 시리즈 횟수 증가
					cnt++;
					break;
				}
			}
			//6연속이 끊기면 다시 6 연속 횟수는 0으로
			else six = 0;
		}
		//찾고자 하는 시리즈와 같다면 해당 숫자 출력
		if (cnt == n) {
			cout << i;
			return 0;
		}
	}

	return 0;
}