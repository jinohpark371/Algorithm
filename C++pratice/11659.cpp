#include <iostream>
#include <vector>
using namespace std;

/*
기존 방식:
total[i]를 만들 때 vec1[1] ~ vec1[i]를 매번 합산 → O(N²)
*/


/*
누적합(Prefix Sum) 방식:
미리 한 번만 누적합을 구함 → O(N)
구간 [st, en] 합을 구할 때 → total[en] - total[st-1]로 O(1)
따라서 전체 시간복잡도: O(N + M)
*/


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<int> vec1(n+1);
	vector<int> total(n+1);

	for (int i = 1;i < n+1; i++) cin >> vec1[i];

	total[1] = vec1[1];
	//이전까지 구해진 누적합에 자기 자신을 더해서
	//본인 위치까지의 누적합을 구성
	for (int i = 2;i < n + 1; i++) {
		total[i] = total[i - 1] + vec1[i];
	}


	while (m--) {
		int st, en;
		cin >> st >> en;
		//누적합을 구간별로 짤라 구간의 합을 구성
		cout << total[en] - total[st - 1] << '\n';
	}

	return 0;
}