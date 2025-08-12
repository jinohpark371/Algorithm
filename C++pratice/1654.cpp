#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;

	vector<long long> len(n);

	for (int i = 0; i < k; i++) cin >> len[i];

	//�ڸ� �� �ִ� ������ �ּ� ����
	long long low = 1;
	//�ڸ� �� �ִ� ������ �ִ� ����
	// max_element�� iterator ��ȯ�ϹǷ� *�� ������ ��ȯ
	long long high = *max_element(len.begin(), len.end());

	//������ �� �� �ִ� ����
	long long answer = 0;
	while (low <= high) {
		//�߰� ����
		long long mid = (low + high) / 2;
		//�� �������� ������ ������ ����
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += len[i] / mid;
		}
		//�ڸ� ������ ������ ���ϴ� ����n���� ũ�ٸ�
		//���� ���� �ڸ����� ���� mid����  �� ū ��������
		//���̸� ������ �� ���� ���� mid�� ���� �ĺ��� ����
		// �� �ٽ� �� ���ǿ� �����Ǵ� ���� mid�� ���´ٸ� �׻� answer�� �ִ�� ����
		if (cnt >= n) {
			answer = mid;
			low = mid + 1;
		}
		//�ڸ� ������ ������ ���ϴ� ���� n������ �۴ٸ�
		//���� ���̸� �ٿ��� ������ ���� �߰� ���� ���� �� ���� ��������
		//Ž�� ����
		else {
			high = mid - 1;
		}

	}

	//Ž���� ����ġ�� ���� answer�� �׻� �ִ� ����
	cout << answer;
	//Ž�������� ���ݾ� ���̴� �̺�Ž���� �ٽ�
	return 0;
}

