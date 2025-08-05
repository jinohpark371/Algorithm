#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> U(n);
	for (int i = 0; i < n; i++)
		cin >> U[i];

	sort(U.begin(), U.end());
	vector<int>two_sum;

	//two_sum ���� ��: O(n^2)
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			two_sum.push_back(U[i] + U[j]);
		}
	}
	//two_sum ���� : O(n ^ 2 log n)
	sort(two_sum.begin(), two_sum.end());

	//d�� ���������̱� ������ U[d]�� ���� ������ Ž����
	//������ �����ϴ� ���� ū d�� ã���� �� �������� �� �̻� Ŭ �� ����
	//�׷��� ������ ������ �� ���� ���� �� ��ȿ�����̰�, ���ʿ��� �񱳰� �߻�
	/*int max = 0;
	for (int d = 0; d < n; d++) {
		for (int c = d; c < n; c++) {
			int diff = U[d] - U[c];
			if (binary_search(two_sum.begin(), two_sum.end(), diff)) {
				if (max < U[d]) max = U[d];
			}
		}
	}*/

	/*
	* ���� U�� ���ĵǾ� �ְ� d�� ���� ū���������� �񱳸� �����ϸ�  
	���ǿ� �´� ���� ó�� ��������
	�� �̻� ū ���� ���̻� ������ �� ����
	 a+b+c =d
	 d-c = a+b
	*/
	/*
	binary_search()�� ���ĵ� �迭���� ����ǹǷ� O(log n��) = O(log n)
	���� ��ü ���⵵�� O(n�� log n)*/
	for (int d = n - 1; d >= 0; d--) {
		for (int c = 0; c < n; c++) {
			int diff = U[d] - U[c];
			if (binary_search(two_sum.begin(), two_sum.end(), diff)) {
				cout << U[d];
				return 0;
			}
		}
	}
	return 0;
}