#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2000000000

int main() {
	int n;
	long m;
	cin >> n >> m;
	vector<long long> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	//���� ���� �� �ε���
	int left = 0;

	sort(vec.begin(), vec.end());
	long long mindiff = MAX;

	//���� ���� ���ε������� ������ ���� �� �ε��� ��������
	//m�̻�Ǵ� �� �ε����� ã��
	for (int right = 0; right < n; right++) {
		long diff =  vec[right] - vec[left];
		//m�� 0�϶� left�� �����ε��� �ʰ�
		while (diff >= m && left<right) {
			//���� �˰� �ִ� �ּڰ��� ���� ������ �ּڰ��� ���Ͽ� �ּڰ��� ����
			mindiff = min(mindiff, vec[right] - vec[left]);
			//������ ������ Ȯ�� �� ���� ���� �� ���� ������ ���
			//���� ���̰����� �ּڰ� ������ ���� ��
			left++;
			diff= vec[right] - vec[left];
		}
	}

	cout << mindiff;
	return 0;
}