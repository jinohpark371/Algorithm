#include<iostream>

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
		int A, B, N;
		cin >> A >> B >> N;

		int cnt = 0;
		//항상 작은 수에 큰 수를 더하면
		//각 단계에서 최솟값이 최대한 빠르게 커지고,
		//그 결과 다음 연산의 증가량도 계속 커진다.
		while (A <= N && B <= N) {
			if (A == min(A, B)) {
				A += B;
			}
			else {
				B += A;
			}
			cnt++;
		}
		cout << cnt << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}