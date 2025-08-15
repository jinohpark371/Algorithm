#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	// int x[1000000]; 원본
	//main() 함수 안에서 선언된 지역 배열은 스택에 저장됨
	//일반적으로 스택 메모리는 1MB ~8MB 제한이 있음(보통 1MB)
	//int[1, 000, 000] → 4MB 사용 → 스택 초과
	vector<int> x(n); //원본
	vector<int> tmp(n); //정렬용
	vector<int> uni; // 중복 제거

	for (int i = 0; i < n; i++) {
		cin >> x[i];
		tmp[i] = x[i];
	}
	
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < n; i++) {
		if (i == 0 || tmp[i - 1] != tmp[i]) {
			uni.push_back(tmp[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << " ";
	}


	return 0;
}