#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;

int main() {
	int v, e, st;
	cin >> v >> e;
	cin >> st;

	//���� ����Ʈ
	vector< vector<pair<int, int>>> adj(v + 1);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	vector<int> dist(v + 1, INF);

	//�ִܰŸ� �迭 �ʱ�ȭ
	for (int i = 1; i < v + 1; i++) {
		dist[i] = INF;
	}
	dist[st] = 0;

	pq.push({ 0, st });
	while (!pq.empty()) {
		
		//���� ������������ ���� ���� ���� ����ġ�� ������ ������ ����
		//�ش� ���� ���� �˰� �ִ� �Ÿ����� ���� ���� ���� ������ �����̹Ƿ�
		//�ٸ� ��Ȯ�� ����� �պ��� �׻� �����Ƿ� �ִܰŸ��� Ȯ��
		auto [curDist, u] = pq.top(); pq.pop();
		//�ִ� ��θ� ������ ������ ������ ���������� �Ÿ���
		//���� ���������� ���� �˰� �ִ� �Ÿ����� ���϶���  �ִܰŸ� ����
		for (auto& [v, w] : adj[u]) {
			if (dist[v] > curDist + w) {
				dist[v] = curDist + w;
				//���� Ž���� ���� �켱����  ť�� push
				pq.push({ dist[v], v });
			}
		}
	}

	for (int i = 1; i < v + 1; i++) {
		if (dist[i] != INF) {
			cout << dist[i] << '\n';
		}
		else {
			cout << "INF" << '\n';
		}
	}

	return 0;
}