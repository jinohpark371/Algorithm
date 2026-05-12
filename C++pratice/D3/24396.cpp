#include<iostream>
#include <climits>
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
		int B, W, X, Y, Z;
		cin >> B >> W >> X >> Y >> Z;

		int result = INT_MIN;

		// k: 흰 상자가 감당 가능한 수준까지
		// 검은 공을 검은 상자에 미리 넣어줘야 하는 최소 개수
		for (int k = max(0, B - W); k <= B; k++) {
			//k를 기준으로 검정 공 -> 검정 상자 매칭
			//나머지 (W-(B-k))개의 흰공 -> 흰 상자 매칭
			// 검정 공 -> 흰 상자 + 흰 공 -> 검정 상자 : 2*(B-k)개
			//k를 기준으로 모든 점수 계산 후 최댓값 갱신	
			result = max(result, k * X + (W - (B - k)) * Y + 2 * (B - k) * Z);
		}

		cout << result << '\n';


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}