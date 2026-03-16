#include <iostream>
using namespace std;

int arr[100000] = { 0 };

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int mmax = -1000;
	for (int i = 0; i < n; i++) {
		//현재까지의 부분합과 현재값 비교하고 
		//현재값이 더 크다면 부분수열을 현재값부터 시작
		sum = max(arr[i], sum + arr[i]);
		//이전 최대부분합과 비교
		mmax = max(mmax, sum);
	}

	cout << mmax;
}