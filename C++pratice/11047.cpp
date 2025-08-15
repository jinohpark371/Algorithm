#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);

	for (int i = 0; i < n; i++) cin >> coins[i];

	//������ �������� ��ǥ �ݾ׺��� ó������ ���� ���� Ȯ��
	int i = n-1;
	while (coins[i] > k) {
		i--;
	}

	//ó������ ���� ���� ���� ��ǥ �ݾ� ä���
	int count = 0;
	for (int j = i; j >= 0; j--) {
		//���� ���� ���� ����
		count += k / coins[j];
		//���� ä�� �ݾ� ����
		k -= (k / coins[j])*coins[j];
		//��ǥ�ݾ��� �� ä��� break
		if (k == 0) break;

	}

	cout << count;
	
}