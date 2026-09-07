#include<iostream>
#include <vector>
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
		int seven = 0;
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			int num; cin >> num;
			sum += num;
			seven = max(seven, num);
		}
		//6명의 난쟁이들의 키보다 큰게 최소 범위
		seven++;
		//최소로 작을 때 정수로 나누어 떨어지는(나머지 0) seven 계산
		while (true) {
			if ((seven + sum) % 7 == 0)break;
			seven++;
		}
		cout << seven << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}