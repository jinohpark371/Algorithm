#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); // cin/cout�� C�� scanf/printf�� ���� ���۸� �и��ؼ� �ӵ� ���
	cin.tie(0);                  // cin�� cout�� ������ ���� cin�� cout�� ��ٸ��� �ʵ��� �Ͽ� ����� �ӵ��� ����Ŵ

	int n, m;
	//priority_queue<  �ڷ���,   ���������̳�,     ���Լ�   > ������;
	//�⺻ �켱���� ť -->priority_queue<int>
	//�ּ� ��
	priority_queue<int, vector<int>, greater<int> > minPQ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 0) {
			if (minPQ.empty()) {
				cout << 0<< '\n';//���ʿ��� flush(��� ���� ����)�� �ٿ� �ݺ��� �ӵ� ���
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