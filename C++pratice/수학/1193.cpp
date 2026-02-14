#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	int k = 0;
	while (k * (k + 1) / 2 < x) k++; //x가 속한 k번째 대각선 찾기

	int prev = k * (k - 1) / 2; //이전 대각선까의 갯수
	int idx = x - prev - 1; // x가 속한 대각선에서의 idx 

	int num, den;
	if (k % 2 == 1) { //홀수번째 대각선 k/1 -> 1/k
		num = k - idx;
		den = idx + 1;
	}
	else { //짝수번째 대각선 1/k -> k/1
		num = idx + 1;
		den = k - idx;
	}

	cout << num << "/" << den;
	return 0;
}