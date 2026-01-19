#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[2000001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		//음수, 양수 조건없이 기준점 1000000에서 왼쪽, 오른쪽 인덱스 위치에 본인 숫자 누적값이 저장됨
		cnt[num + 1000000]++;

	}

	//배열 인덱스를  맨 첨부터 조회해서  값이 있다면  
	// 해당 인덱스에서 OFFSET(1000000)을 뺀다면 입력된 숫자(음수, 양수)를 중복된 입력된 횟수만큼, 정렬된 순서대로 출력
	for (int i = 0; i < 2000001; i++) {
		while (cnt[i]--) {
			cout << i - 1000000 << '\n';
		}

	}
	return 0;
}