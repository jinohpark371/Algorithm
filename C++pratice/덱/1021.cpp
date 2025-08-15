#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> dq;
	int N, M;
	int i;
	int seq[50];
	int count = 0;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> seq[i];
	}
	for (i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int target = seq[i];
		
		//현재 덱에서 target의 위치 찾기
		int idx = 0;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == target) {
				idx = j;
				break;
			}
		}
		//왼쪽이 빠르면 왼쪽 회전, 아니면 right
		if (idx <= dq.size() / 2) {
			while (target != dq.front()) {
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
		}
		else {
			while (target != dq.front()) {
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
		}
		//target 제거
		dq.pop_front();
	}
	cout << count;
	return 0;
}