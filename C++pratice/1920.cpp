#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//이진 탐색 함수 예
bool bianrySearch(const vector<int>& vec, int target) {
	int left = 0;
	int right = vec.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (vec[mid] == target)
			return true;
		else if (vec[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	vector<int> vec1(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec1[i] = num;;
	}
	//벡터 오름차순 정렬
	sort(vec1.begin(), vec1.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		//정렬된 배열이나 벡터에서 사용가능
		//값이 있다면 true, 없다면 false 리턴
		if (binary_search(vec1.begin(), vec1.end(), num)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}

	}


	
	return 0;
}