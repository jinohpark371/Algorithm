#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int result = 0;
	stack<char> s;
	string ans;
	cin >> ans;

	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] == '(') {
			// �踷����� ������ ��Ÿ���Ƿ� ���ÿ� push
			s.push(ans[i]);
		}
		else {
			// �ݴ� ��ȣ ')'�� ��
			s.pop(); // �ٷ� �� ��ȣ '('�� ¦�� �̷�Ƿ� pop

			if (ans[i - 1] == ')') {
				// ������ ')'��� -> �踷����� ���� �ǹ� -> ���� 1�� �߰�
				result++;
			}
			else {
				// ������ '('��� -> ������ -> ���� ���� ũ�⸸ŭ ���� ����
				// ���� ������ ũ�Ⱑ ��ġ�� ������ ����
				result += s.size();
			}
		}
	}
	cout << result;
	return 0;
}
