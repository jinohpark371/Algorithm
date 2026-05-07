#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		string command;
		cin >> command;
		// 각 축에 대해 반대 방향 이동이 모두 존재하면
		// 이동 거리를 조절하여 원점으로 돌아올 수 있음

		//반대방향 존재 여부 검사
		bool N = command.find('N') != string::npos;
		bool S = command.find('S') != string::npos;
		bool E = command.find('E') != string::npos;
		bool W = command.find('W') != string::npos;

		//각 방향의 존재 여부가 같다면 통과
		if (N != S || E != W) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}