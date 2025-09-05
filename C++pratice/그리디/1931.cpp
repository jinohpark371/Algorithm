#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
회의시간이 겹치지 않는 조건에 맞으면 
가장 빨리 끝나는 회의를 선택해서 
뒤에 올 수 있는 회의들의 수를 최대로 유지한다
*/
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> meet(n);

	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;
		meet[i] = { en, st }; //끝시간 기준
	}

	//끝시간 정렬
	sort(meet.begin(), meet.end());

	int last_end = meet[0].first;
	int count = 1;
	for (int i = 1; i < n; i++) {
		int st = meet[i].second;
		//다음 회의는 현재 회의의 끝시간보다 큼
		if (st >= last_end) {
			//전체 회의 갯수 증가
			count++;
			//다음 회의의 끝시간을 기준으로 선정
			last_end = meet[i].first;
		}
	}

	cout << count;

	return 0;
}