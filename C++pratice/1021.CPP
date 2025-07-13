#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> dq;
	int N, M;
	int i;
	int seq[3];
	int count = 0;
	cin >> N >> M;
	for (i = 0; i < 3; i++) {
		cin >> seq[i];
	}
	for (i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	i = 0;
	int temp;
	while (i != 3) {
		if (seq[i] == deque.front()) {
			deque.pop_front();
			i++;
		}
		else {
			if (dq.front() < seq[i] && dq.size()/2 > seq[i]) {
				temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				count++;
			}
			else {
				temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
				count++;
			}
		}
	}
	cout << count;
	return 0;
}
