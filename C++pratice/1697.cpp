#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int st, en;
	cin  >> st >> en;

	vector<int> dist(100001, -1);
	dist[st] = 0;

	queue<int> q;
	q.push(st);

	while (!q.empty()) {
		int cursor = q.front(); q.pop();

		//���ϴ� ������ �������� �� ���������� �ּҽð�
		if (cursor == en) {
			cout << dist[cursor];
			return 0;
		}

		//�׻� �������� �� �� �ִ� ������ -1, +1, 2�� ����
		//�� ���������� �ּҽð��� �ڱ���� �� �ð� +1
		//BFS�� ���� ������ �����Ƿ� �� ª�� ��ΰ� �� �ʰ� ���� �� ����
		for (int next : {cursor - 1, cursor + 1, cursor * 2}) {
			if (next < 0 || next >100000) continue;
			if (dist[next] != -1) continue;

			dist[next] = dist[cursor] + 1;
			q.push(next);
		}
	}

	return 0;
}