#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n;
	int reulst = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		pq.push(num);
	}
	
	while (pq.size() != 1) {
		int sum;
		for (int i = 0; i < 2; i++) {
			sum += pq.top();
			pq.pop();
		}
		reulst += sum;
	}

	cout << reulst;
	return 0;
}