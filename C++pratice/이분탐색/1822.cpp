#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int na, nb;
	cin >> na >> nb; //각 집합의 크기
	
	vector<int> a(na); //집합 A
	vector<int> b(nb); //집합 B
	//각 집합 입력
	for (int i = 0; i < na; i++) cin >> a[i];
	for (int i = 0; i < nb; i++) cin >> b[i];

	//각 집합 정렬
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> answer; // 차집합
	//A집합의 각 원소를 기준으로 차집합 구분
	for (int val : a) {
		//해당 원소가 집합 B에 존재 하지 않을시 차집합
		if (!binary_search(b.begin(), b.end(), val)) {
			answer.push_back(val); //차집합에 추가
		}
	}

	if (!answer.empty()) {
		cout << answer.size() << '\n';
		for (int x : answer) cout << x << ' ';
	}
	else {
		cout << '0';
	}
	

	return 0;
}