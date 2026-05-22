#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// 등차수열 조건: b-a = c-b  ->  2b = a+c

		// a 또는 c를 조절하는 경우는 대칭이라 필요한 x값이 동일
		double x1 = abs(2 * b - a - c);
		// b를 조절하는 경우
		// 실수 나눗셈을 위해 2.0 사용
		double x2 = abs((a + c - 2 * b) / 2.0);

		double mmin = min(x1, x2);

		cout << fixed << setprecision(1);
		cout << "#" << test_case << ' ' << mmin << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}