#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	stack<char> s;
	cin >> str;
	int num = 1; //��ȣ�� ����ġ�� ������ ��
	int sum = 0; //������ ���� �����ؼ� ���� ��
	for (int i = 0; i < str.length(); i++) {
		//���� ��ȣ�� ���ý� ����ġ 2����
		if (str[i] == '(') {
			num *= 2;
			s.push(str[i]);
		}
		//���� ��ȣ�� ���ý� ����ġ 3����
		else if (str[i] == '[') {
			num *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			//�� �� ������ ��� �ְų� top�� (�� �ƴҽ� ��ȣ�� ��ȿ���� ����
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			// )�ݴ� ��ȣ�� ���ý� �׵��� �׿��� ����ġ��
			//���Ƽ� ����
			if (str[i - 1] == '(') sum += num;
			//( �ϳ� ���� �Ŀ� �ڽ��� ����ġ�� 2�� ������ ����
			s.pop();
			num /= 2;
		}
		else {
			//�� �� ������ ��� �ְų� top�� [�� �ƴҽ� ��ȣ�� ��ȿ���� ����
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			// ]�ݴ� ��ȣ�� ���ý� �׵��� �׿��� ����ġ��
			//���Ƽ� ����
			if (str[i - 1] == '[') sum += num;
			s.pop();
			//] �ϳ� ���� �Ŀ� �ڽ��� ����ġ�� 2�� ������ ����
			num /= 3;
		}
	}
	// ( �ϳ��̰ų�  ���ÿ� ���� ��ȣ�� ���� �ִٸ� ��ȿ�� ��ȿ���� ����
	if (s.empty())cout << sum;
	else cout << 0;
	return 0;
}
