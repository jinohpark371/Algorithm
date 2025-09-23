#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> f(41); //각 항의 0의 갯수, 1의 갯수 저장 벡터


//재귀 + 메모이제이션 방식
//이미 0, 1의 갯수를 구한 항은 재귀를 안하는게 핵심
pair<int, int> fibonacci(int n) {
	if (n == 0) {
		return f[n];
	}
	else if (n == 1) {
		return f[n];
	}
	else {
		if (f[n].first || f[n].second) return f[n]; //이미 n번째 항까지의 0, 1의 갯수가 구해졌다면 바로 리턴
		else {
			pair<int, int> prev = fibonacci(n - 1); //n-1번째 항까지의 0, 1의 갯수 구하기
			pair<int, int> next = fibonacci(n - 2);//n-2번째 항까지의 0, 1의 갯수 구하기
			//f(n-1), f(n-2)번째 항까의 0, 1의 갯수 합쳐서 현재 항의 갯수로 추가
			int first = prev.first + next.first; 
			int second = prev.second + next.second;
			f[n] = { first, second };
			//추가된 항도 리턴하여 자신을 호출한 항에서 계산
			return f[n];
		}
	}
}


int main() {
	int n;
	cin >> n;
	f[0] = { 1,0 };
	f[1] = { 0, 1 };

	while (n--) {
		int num;
		cin >> num;
		fibonacci(num);
		cout << f[num].first << " " << f[num].second<< '\n';
	}


	return 0;
}