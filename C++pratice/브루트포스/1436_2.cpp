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
		if (to_string(i).find("666") != string::npos) {
			cnt++;//시리즈 수 증가
		}
		//찾고자 하는 시리즈와 같다면 해당 숫자 출력
		if (cnt == n) {
			cout << i;
			return 0;
		}
	}

	return 0;
}