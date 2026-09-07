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
		long long A, B, C;
		cin >> A >> B >> C;

		// 크기가 n인 막대는 최대 n-1번 나눌 수 있다.
		// 따라서 A*B*C 크기의 직육면체는
		// 최종적으로 A*B*C 개 조각이 되므로
		// 총 A*B*C - 1 번 자르게 된다.
		long long chance = A * B * C - 1;
		if (chance % 2 == 1) {
			cout << 1 << '\n';
		}
		else {
			cout << 2 << '\n';
		}


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}