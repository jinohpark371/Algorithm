#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	stack<pair<int, int>> s;
	cin >> n;

	long long ans = 0; //오버플로우 방지
	while (n--) {
		int h;
		cin >> h;
		int cnt = 1; //현재 연속된 같은 키의 갯수
		while (!s.empty() && s.top().first <= h) { //현재 키가 top보다 크거나 같을때까지 pop
			ans += s.top().second; //pop전 현재 키가 볼 수 있는 top의 같은 키의 갯수를 결과에 누적
			if (s.top().first == h) cnt += s.top().second; //키가 같다면 키의 갯수를 누적
			s.pop();
		}
		if (!s.empty()) ans++;//스택에 키가 남아있다면 현재 키보다 큼, 그 키와 현재 키의 관계어서 1증가
		s.push({ h, cnt });//현재 키는 다음 비교를 위해 삽입
	}

	cout << ans;
	return 0;
}