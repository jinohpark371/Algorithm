#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			int num;
			cin >> num;
			pq.push(num);
			//�ּ����� ũ�⸦ n���� �����ϸ� ���ڰ� ���ö����� �׻� �ּڰ��� ����
			//�ᱹ �����ִ� ���ڵ� �� ��Ʈ�� n��° ū ���� �Ǵ� ��
			//n��°���� ū ���ڵ鸸 ��Ƴ���
			//��Ʈ�� �׻� ������� �˻��� ���ڵ� �߿��� n��° ū ���� �ǹ��ϰ�
			//��� ���ڸ� �˻��Ѵٸ� ��Ƴ��� ���ڵ� �߿� ��Ʈ�� ���� n��° ū ���� ��
			if (pq.size() > n) {
				pq.pop();
			}
		}
	}

	cout << pq.top();
	return 0;
}