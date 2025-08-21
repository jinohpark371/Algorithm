#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrims[4000000];

int main() {
	int n;
	cin >> n;

	vector<int> prims;
	for (int i = 2; i <= n; i++) isPrims[i] = true;


	/*
	�����ٱ����� �˻��ϴ� ������  m = a �� b �϶� ���� �μ�(a �Ǵ� b)�� ��m ����
	���� n ������ �ռ����� ���� �������
	��n������ �Ҽ� i�� ������ ���
	*/

	for (int i = 2; i <= sqrt(n); i++) {

		if (!isPrims[i]) continue;
		//�׻� �ڱ� �ڽ� ���� ���� ������� �Ҽ��ĺ����� ����
		//�׻� �Ҽ��� ����� �Ҽ��� �ƴϱ� ������ n���������� ����
		//���� �Ҽ��� ������� ó���Ѵٸ� �� �������� ū �Ҽ� i �� 
		// i*2, i*3, i*(i-1) ���� ���� �̹� ���������Ƿ�  i*i���� ����� ��
		// ex)��: 3��2 = 6 �� �̹� 2�ܰ迡�� ������, 5��2 = 10 �� �̹� 2�ܰ迡�� ������

		for (int j = i * i; j <= n; j += i) {

			isPrims[j] = false;
		}
	}

	/*��ȿ������ ���
	* �̹� ������ �κб��� ��� �˻縦 ��� �����ϰ� ����
	for (int i = 2; i <= sqrt(n); i++) {
	for (int j = 2; i*j <= n; j++) {
		if (i * j == i) continue;
		isPrims[i * j] = false;
	}
	}*/

	for (int i = 2; i <= n; i++) {
		if (isPrims[i]) prims.push_back(i);
	}

	int L = 0, R = 0;
	int cnt = 0;
	int sum = 0;
	while (true) {
		if (sum >= n) {
			if (sum == n) cnt++;
			sum -= prims[L++];
		}
		else {
			if (R == prims.size()) break;
			sum += prims[R++];
		}
	}

	cout << cnt;

	return 0;

}