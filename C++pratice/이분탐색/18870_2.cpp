#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	// int x[1000000]; ����
	//main() �Լ� �ȿ��� ����� ���� �迭�� ���ÿ� �����
	//�Ϲ������� ���� �޸𸮴� 1MB ~8MB ������ ����(���� 1MB)
	//int[1, 000, 000] �� 4MB ��� �� ���� �ʰ�
	vector<int> x(n); //����
	vector<int> tmp(n); //���Ŀ�
	vector<int> uni; // �ߺ� ����

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