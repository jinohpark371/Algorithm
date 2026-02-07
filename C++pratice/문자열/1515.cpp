#include <iostream>
#include <string>
using namespace std;

int main() {
	string seq;
	cin >> seq;
	int j = 0;
	int i = 1;

	//i는 부분수열이 끊겨 있어도 그거만큼 띄어넘어서 셈
	while (j < seq.length()) {
		string s = to_string(i);

		//수열의 숫자가 현재 i에 포함여부를 확인
		for (char c : s) {
			if (c == seq[j]) {
				j++; //다음 숫자 비교를 위해 한칸 이동
			}
		}
		//비교 종료
		if (j == seq.length()) {
			//비교가 종료될떄의 i값
			cout << i;
			break;
		}
		i++;
	}

	return 0;
}