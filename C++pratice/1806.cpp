#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int sum = 0;
	int end = 0;
	int md = MAX;
	// ������: [start, end)   (end�� �׻� �� ĭ �ڸ� ����Ŵ)
// sum == vec[start .. end-1] �� ���� �����Ѵ�.
	for (int start = 0; start < n; start++) {
		// Ȯ�� �ܰ�: ���� s �̸��̸� end�� �÷� ����(sum >= s)�� ������Ų��.
		while (end < n && sum < s) {
			sum += vec[end];
			end++;
		}
		// ���� ���� �� ���� ������ ���̷� �ּ� ���̸� �����Ѵ�.
		if (sum >= s) {
			md = min(md, end - start);// ���̴� end-start (end�� �� ĭ ��)
		}
		//���ʱ����� ���̸� ��ǥ �պ��� ũ�ų� ������ ���̸� ���� �� �� �ֵ��� �Ѵ�.
		sum -= vec[start];
	}
	
	//���� ��ü ������ ���� ��ǥ�պ��� ��� �۴ٸ� md�� �ѹ��� ���ŵ��� �ʴ´�
	cout << (md == MAX ? 0 : md);

	return 0;
}