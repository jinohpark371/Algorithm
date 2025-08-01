#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//���� Ž�� �Լ�
int lower_bound(vector<int>& arr, int target) {
	//�ʱ� �˻� ����
	int left = 0, right = arr.size();
	// Ž���� �������� target �̻��� ó�� ������ ��ġ�� left�� ��Ȯ�� ����
	//���� �� left == right
	while (left < right) {
		//�߰� ��ġ ���
		int mid = (left + right) / 2;
		//mid ���� target���� �۴ٸ�
		//target�� �����ʿ� ���� ������ ����
		if (arr[mid] < target)
			left = mid + 1;
		//���ݰ��� target�̻��̸� ���� �� ��ġ�� ���� �ĺ��ϱ� ������ �ʰ� ����
		else
			right = mid;
	}

	return left; // or right (�� �� ����)
}

int upper_bound(vector<int>& arr, int target) {
	int left = 0, right = arr.size();

	while (left < right) {
		int mid = (left + right) / 2;

		//target���� mid������ ũ�ų� ������
		//������ ���� �߾ӿ��� +1�� ��ġ���� �����Ͽ�
		//�ٽú��ϸ鼭 left�� right�� ������ ��ġ��
		//ó������ �ʰ��� ��ġ
		if (arr[mid] <= target)
			left = mid + 1;
		else
			right = mid;
	}

	return left; // �Ǵ� right
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	vector<int> cards(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cards[i] = num;
	}
	sort(cards.begin(), cards.end());

	cin >> m;
	while (m--){
		int x;
		cin >> x;
		//value �̻��� ù ��° ��ġ�� iterator�� ��ȯ, value�� ó�� ������ ��ġ
		int lower = lower_bound(cards.begin(), cards.end(), x) - cards.begin();
		//value �ʰ��� ù ��° ��ġ�� iterator�� ��ȯ, value ���� ���� ó�� ������ ��ġ 
		int upper = upper_bound(cards.begin(), cards.end(), x) - cards.begin();
		//lower_bound�� upper_bound�� �ݵ�� ���ĵ� �����̳ʿ����� ��� ����
		//lower_bound�� ��ȯ�ϴ� �� ��ġ(�ּ�)�� �� ��ġ���� v.begin()(��, ���� �ּ�)�� ����
		//���ۺ��� �� ĭ ������ �ִ��� = �ε��� �� �� �� ����

		//�ʰ��� ù��° �ε������� ó������ �ش� �� �̻��� �ε����� ���� ���ĵ� ������ ���� ���ӵǾ� �ִٸ�
		//�� ������ ���� �ش� ī�尡 ������ ����
		int count = upper - lower;

		cout << count << " ";
	}

	return 0;
}