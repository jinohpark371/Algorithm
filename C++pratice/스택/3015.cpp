#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	stack<pair<int, int>> s;
	cin >> n;

	long long ans = 0; //�����÷ο� ����
	while (n--) {
		int h;
		cin >> h;
		int cnt = 1; //���� ���ӵ� ���� Ű�� ����
		while (!s.empty() && s.top().first <= h) { //���� Ű�� top���� ũ�ų� ���������� pop
			ans += s.top().second; //pop�� ���� Ű�� �� �� �ִ� top�� ���� Ű�� ������ ����� ����
			if (s.top().first == h) cnt += s.top().second; //Ű�� ���ٸ� Ű�� ������ ����
			s.pop();
		}
		if (!s.empty()) ans++;//���ÿ� Ű�� �����ִٸ� ���� Ű���� ŭ, �� Ű�� ���� Ű�� ���� 1����
		s.push({ h, cnt });//���� Ű�� ���� �񱳸� ���� ����
	}

	cout << ans;
	return 0;
}