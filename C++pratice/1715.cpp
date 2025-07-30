#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n;
	int result = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		pq.push(num);
	}
	//size�� 1�Ͻ� ī�带 �ϳ��� �� ������
	while (pq.size() > 1) {
		/*���� ������ ���� ��ġ�� ���� �� ��ĥ �� ����� ��������� �۾�
	���Ƿ� �ּ����� ���� ���� ���� ���� ���� ���� ī�� ���� �ΰ��� ��ħ(�׸��� ����)*/
		int first = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();
		int localsum = first+second;
		//��Ƚ�� �������
		result += localsum;
		//ť�� �ִ� �� ������ ī���� ��
		//������ ī�� ���� �ٸ� ������ ���ϱ� ���� ť�� ���Ե�
		pq.push(localsum);
	}

	/*
	int sum = 0;
	while (pq.size() != 1) {
		for (int i = 0; i < 2; i++) {
			sum += pq.top();
			pq.pop();
		}
		result += sum;
		pq.push(sum);
		sum = 0;
	}*/

	cout << result;
	return 0;
}