#include <iostream>
#include <climits>
using namespace std;

int main() {
	string  L, R;
	cin >> L >> R;
	long long count = 0;

	//L과 R의 자릿수가 다를땐  R이 더 크므로
	//8이 없는 다른 수로 맞출 수 있음
	if (L.length() != R.length()) {
		cout << 0;
		return 0;
	}
	//자릿수가 같을땐 각 자릿수가 각각 8일때 다른 수를 선택할 수 없지만
	//각 자릿수가 다른땐 8이 아닌 다른 수를 선택할 수 있으므로
	//각 자릿수가 8일때만 카운트
	else {
		for (int i = 0; i < L.length(); i++) {
			if (L[i] == '8' && R[i] == '8') {
				count++;
			}
			//그냥 자릿수가 같은땐 다음 자릿수 탐색
			else if (L[i] == R[i]) continue;
			else break; //다른 순간부터는 8이 아닌 다른수로 선택 가능
		}
	}
	cout << count;

	return 0;

}