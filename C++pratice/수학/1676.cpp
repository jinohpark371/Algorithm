#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	
	int fiveCnt = 0;
	int five = 5;
	//팩토리얼에서 10 = 2 × 5 이므로
	//2와 5가 한 쌍 만들어질 때마다 끝에 0이 하나 생김
	//팩토리얼에서 2는 무수히 많지만 5는 그거에 비해 확실히 적음
	//팩토리얼 끝의 0 개수 = 10의 개수
	//10 = 2 × 5 이고 2는 충분히 많기 때문에
	//결국 5의 개수를 세면 된다
	//n/5   → 5를 최소 1개 포함한 수
	//n / 25  → 5를 2개 포함한 수(25 = 5×5)
	//n / 125 → 5를 3개 포함한 수
	while (n / five > 0) {
		fiveCnt += n / five;
		five = five*5;
	}

	cout << fiveCnt;
}