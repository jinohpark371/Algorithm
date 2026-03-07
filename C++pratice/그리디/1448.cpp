#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec;

	while (n--) {
		int num; cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	//오름차순 정렬 후 끝에서부터 3개씩 삼각형 조건 검사 진행
	//c가 가장 긴 변이고 a, b가 나머지 두 변이라면
	//C<a+b가 처음 성립될때 최대값
	//왜냐하면  c>= a+b일때 c가 가장 긴변인 삼각형은 존재X
	//C를 제외하고 그 다음으로 가장 좋은 조건인 앞쪽 3개로 다시 비교

	for (int i = vec.size() - 1; i >= 2; i--) {
		if (vec[i - 2] + vec[i - 1] > vec[i]) {
			cout << vec[i - 2] + vec[i - 1] + vec[i];
			return 0;
		} 
	}
	
	cout << -1;
	return 0;
}