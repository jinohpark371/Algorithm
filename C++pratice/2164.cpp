#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	int i;
	queue<int> q;

	cin >> N;

	for (i = 1; i <= N; i++) {
		q.push(i);
	}
	int temp;
	while (q.size() != 1) {
		q.pop();
		temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << q.front();
	return 0;
}