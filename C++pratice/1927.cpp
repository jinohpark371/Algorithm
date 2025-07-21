#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); // cin/cout과 C의 scanf/printf의 내부 버퍼를 분리해서 속도 향상
	cin.tie(0);                  // cin과 cout의 연결을 끊어 cin이 cout을 기다리지 않도록 하여 입출력 속도를 향상시킴

	int n, m;
	//priority_queue<  자료형,   내부컨테이너,     비교함수   > 변수명;
	//기본 우선순위 큐 -->priority_queue<int>
	//최소 힙
	priority_queue<int, vector<int>, greater<int> > minPQ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 0) {
			if (minPQ.empty()) {
				cout << 0<< '\n';//불필요한 flush(출력 버퍼 비우기)를 줄여 반복문 속도 향상
			}
			else {
				cout << minPQ.top() << '\n';
				minPQ.pop();
			}
		}
		else {
			minPQ.push(m);
		}
	}
}