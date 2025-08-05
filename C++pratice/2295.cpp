#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> U(n);
	for (int i = 0; i < n; i++)
		cin >> U[i];

	sort(U.begin(), U.end());
	vector<int>two_sum;

	//two_sum 구할 때: O(n^2)
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			two_sum.push_back(U[i] + U[j]);
		}
	}
	//two_sum 정렬 : O(n ^ 2 log n)
	sort(two_sum.begin(), two_sum.end());

	//d는 오름차순이기 때문에 U[d]가 작은 수부터 탐색됨
	//조건을 만족하는 가장 큰 d를 찾으면 그 시점에서 그 이상 클 수 없음
	//그런데 지금은 끝까지 다 돌고 있음 → 비효율적이고, 불필요한 비교가 발생
	/*int max = 0;
	for (int d = 0; d < n; d++) {
		for (int c = d; c < n; c++) {
			int diff = U[d] - U[c];
			if (binary_search(two_sum.begin(), two_sum.end(), diff)) {
				if (max < U[d]) max = U[d];
			}
		}
	}*/

	/*
	* 벡터 U는 정렬되어 있고 d는 가장 큰값에서부터 비교를 시작하며  
	조건에 맞는 값이 처음 나왔을때
	그 이상 큰 값은 더이상 존재할 수 없음
	 a+b+c =d
	 d-c = a+b
	*/
	/*
	binary_search()는 정렬된 배열에서 수행되므로 O(log n²) = O(log n)
	따라서 전체 복잡도는 O(n² log n)*/
	for (int d = n - 1; d >= 0; d--) {
		for (int c = 0; c < n; c++) {
			int diff = U[d] - U[c];
			if (binary_search(two_sum.begin(), two_sum.end(), diff)) {
				cout << U[d];
				return 0;
			}
		}
	}
	return 0;
}