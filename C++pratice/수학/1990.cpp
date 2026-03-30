#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
using namespace std;

bool isPrime(int num) {
	if (num <= 2) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)return false;
	}

	return true;
}

int main() {
	int a, b;
	cin >> a >> b;

	//한자리 소수 검사
	for (int i = 1; i < 10; i++) {
		if ( i >=a && i<=b && isPrime(i)) cout << i << '\n';
	}

	//11은 무조건 소수 + 팰린드롬
	if(11>=a && 11 <=b)
		cout << 11 << '\n';

	//3의 자리수부터 홀수 자리수를 만들면서 9의 자리 수
	for (int digit = 3; digit <= 9; digit += 2) {

		//앞부분 숫자 범위(중간 위치 포함)
		int half = digit / 2 + 1;
		int start = pow(10, half - 1);
		int end = pow(10, half) - 1;

		//앞부분 숫자 범위에 맞춰 팬린드롬 숫자 생성
		for (int i = start; i <= end; i++) {
			string s = to_string(i);
			
			//가운데가 될 숫자 제외한 나머지 숫자
			string rev = s.substr(0, s.size() - 1);
			//뒤집기
			reverse(rev.begin(), rev.end());

			//팰린드롬
			string full = s + rev;
			int num = stoi(full);
			//범위 체크
			if (num > b) break;

			if ( num >=a && isPrime(num)) cout << num << '\n';
		}
	}

	cout << -1;
}