#include <iostream>
#include <vector>
using namespace std;

/*
���� ���:
total[i]�� ���� �� vec1[1] ~ vec1[i]�� �Ź� �ջ� �� O(N��)
*/


/*
������(Prefix Sum) ���:
�̸� �� ���� �������� ���� �� O(N)
���� [st, en] ���� ���� �� �� total[en] - total[st-1]�� O(1)
���� ��ü �ð����⵵: O(N + M)
*/


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<int> vec1(n+1);
	vector<int> total(n+1);

	for (int i = 1;i < n+1; i++) cin >> vec1[i];

	total[1] = vec1[1];
	//�������� ������ �����տ� �ڱ� �ڽ��� ���ؼ�
	//���� ��ġ������ �������� ����
	for (int i = 2;i < n + 1; i++) {
		total[i] = total[i - 1] + vec1[i];
	}


	while (m--) {
		int st, en;
		cin >> st >> en;
		//�������� �������� ©�� ������ ���� ����
		cout << total[en] - total[st - 1] << '\n';
	}

	return 0;
}