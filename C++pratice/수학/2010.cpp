#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	int sum = 0;
	/*for (int i = 0; i < n; i++) {
		마지막 멀미탭을 제외한 나머지는 
		 콘센트 하나는 다음 멀티탭을 위해 사용됨
		if (i != n - 1) {
			sum = sum + (vec[i] - 1);
		}
		마지막 멀티탭은 모든 콘센트 사용가능
		else {
			sum += vec[i];
		}
	}*/

	//그냥 모든 멀티탭의 콘센트 갯수 합을 구하고
	for (int i = 0; i < n; i++) {
		sum += vec[i];
	}
	//멀미탭 당 하나의 콘센트가 사용되니까 멀티탭 수를 제외하는데
	//마지막 멀티탭은 제외
	cout << sum-(n-1);
	return 0;
}