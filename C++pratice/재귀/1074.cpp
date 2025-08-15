#include <iostream>
using namespace std;

/*
��͸� ���� 2���� ��ǥ�� �׻� 4����ϸ�,
���� �迭 ũ���� ����(half)�� ���� ��ǥ(r, c)�� ����
�ش� ��и����� �̵��� �� �ֵ��� ��ǥ�� �����Ѵ�.

�� �� n�� 1 ���ҽ���, �ش� ��и� ������ �ٽ� ���� �������
���� Ž���� �����ϵ��� �Ѵ�.

���� n�� 0�� �Ǿ� �� �̻� 4����� �Ұ���������,
�׵��� ���Ŀ� ��и��� ���� �ε����� ��� ������ ���� ���� ��ȯ�Ͽ�
��ü �迭���� (r, c)�� �� ��°�� �湮�Ǵ����� ����Ѵ�.
*/

int solve(int n, int r, int c) {
	if (n == 0) return 0;

	// << ��Ʈ �̵� ������
	// <<�� ���� ����Ʈ
	// 1 << k�� �������� 1�� k��Ʈ �̵� �Ͽ�
	//2^k�� ���� ��
	int half = 1 << (n - 1);
	int area = half * half;

	if (r < half && c < half) {
		return solve(n - 1, r, c); //�� 1��и��� ��ǥ �״��
	}
	else if (r < half && c >= half) {
		return area + solve(n - 1, r, c - half); //�� 2��и����� c�� ���� ��ǥ ����
	}
	else if (r >= half && c < half) {
		return 2 * area + solve(n - 1, r - half, c); //�� 3��и����� r�� ���� ��ǥ ����
	}
	else return 3 * area + solve(n - 1, r - half, c - half); //�� 4��и����� r, c�� ���� ��ǥ ����
}


int main() {
	int n, r, c;
	cin >> n >> r >> c;

	cout << solve(n, r, c);
	return 0;
}