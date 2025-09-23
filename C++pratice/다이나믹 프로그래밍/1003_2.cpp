#include <iostream>
#include <vector>
using namespace std;

int fibo[41][2];
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> f(41); //각 요소는 해당 항까지의 0과 1의 호출 횟수
	
	// f[0] = {1, 0}, f[1] = {0, 1} 
	// 기저 조건을 미리 넣음 (fib(0), fib(1) 호출 횟수)
	f[0] = { 1, 0 };
	f[1] = { 0, 1 };


	//아래 항부터 0, 1의 갯수를 계산하고 2이상 n번째 항들은 
	// 이떄까지 구해진 f(n-1), f(n-2)번쨰 
	// 항까지 0, 1의 갯수의 각각의 합을 자신의 값으로 가지면 됨
	
	// f[i] = f[i-1] + f[i-2] 
	for (int i = 2; i <= 40; i++) {
		f[i].first = f[i - 1].first + f[i - 2].first;
		f[i].second = f[i - 1].second + f[i - 2].second;
	}

	while (n--) {
		int num;
		cin >> num;
		cout << f[num].first<< " " <<f[num].second << '\n';
	}

	return 0;
}