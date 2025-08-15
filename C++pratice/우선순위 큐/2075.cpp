#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			int num;
			cin >> num;
			pq.push(num);
			//최소힙은 크기를 n으로 유지하면 숫자가 들어올때마다 항상 최솟값만 삭제
			//결국 남아있는 숫자들 중 루트가 n번째 큰 수가 되는 것
			//n번째까지 큰 숫자들만 살아남음
			//루트는 항상 현재까지 검사한 숫자들 중에서 n번째 큰 수를 의미하고
			//모든 숫자를 검사한다면 살아남은 숫자들 중에 루트가 실제 n번째 큰 수가 됨
			if (pq.size() > n) {
				pq.pop();
			}
		}
	}

	cout << pq.top();
	return 0;
}