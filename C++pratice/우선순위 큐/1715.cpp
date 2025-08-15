#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n;
	int result = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		pq.push(num);
	}
	//size가 1일시 카드를 하나로 다 합쳐짐
	while (pq.size() > 1) {
		/*작은 수끼리 먼저 합치면 다음 번 합칠 때 비용이 상대적으로 작아
	지므로 최소힙을 통해 먼저 가장 작은 수를 가진 카드 묶음 두개를 합침(그리디 전략)*/
		int first = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();
		int localsum = first+second;
		//비교횟수 누적계산
		result += localsum;
		//큐에 넣는 건 합쳐진 카드의 수
		//합쳐진 카드 또한 다른 묶음과 비교하기 위해 큐에 삽입됨
		pq.push(localsum);
	}

	/*
	int sum = 0;
	while (pq.size() != 1) {
		for (int i = 0; i < 2; i++) {
			sum += pq.top();
			pq.pop();
		}
		result += sum;
		pq.push(sum);
		sum = 0;
	}*/

	cout << result;
	return 0;
}