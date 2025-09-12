#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
tuple<int, int, int> edge[100001];
int parent[100001];

/*
항상 호출할때마다 대표루트 노드를 찾아가는 경로에
있는 모든 정점의 대표루트노드를 갱신
해당 정점이 속한 집합의 대표루트 노드를 찾음
*/
int find(int x) {
	if (parent[x] == x) return x; //루트 노드일시 자신의 정점번호 반환
	return parent[x] = find(parent[x]);//대표 루트노드 찾아서 자신의 루트로 갱신
}


void Union(int a, int b) {
	a = find(a); //정점 a가 속한 집합의 대표 루트 노드
	b = find(b);//정점 b가 속한 지합의  대표 루트 노드
	parent[b] = a; //두 집합을 합침: b의 대표 루트를 a의 대표 루트에 연결
}


int main() {

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[i] = { w, u, v }; //가중치와 정점 u, v
	}

	sort(edge, edge + E); //가중치 오름차순 정렬

	for (int i = 1; i < V; i++) parent[i] = i; //초기 정점들의 대표루트노드는 자기 자신

	int mst_weight = 0;
	for (int i = 0; i < E; i++) {
		auto [w, u, v] = edge[i];
		//두 정점의 대표 루트 노드가 다를때 사이클없이 최소 스패닝 트리 구성 가능
		if (find(u) != find(v)) {
			//두 정점이 속한 집합들을 연결
			Union(u, v);
			//최소 가중치의 합 갱신
			mst_weight += w;
		}
	}

	cout << mst_weight;
	return 0;
}