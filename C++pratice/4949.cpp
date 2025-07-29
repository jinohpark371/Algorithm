#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
	stack<char> s;
	string str;
	while (true) {
		//cin�� ������������ �����
		//get line�� ���� ���� ���� ��ü�� �о�ͼ�  str�� ����
		//���� �� \n�� ���� ��
		getline(cin, str);
		//�Է����� ��ȣ
		if (str == ".") break;

		bool isVaild = true;
		//������ �Է¹��� ���ڿ��� ���� ���� �ʱ�ȭ
		while (!s.empty()) s.pop();
		
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			// ���� ��ȣ�� stack�� push
			if (ch == '(' || ch == '[') {
				s.push(ch);
			}
			else if (ch == ')') {
				//������ ��� �ְų� top�� �ش� ��ȣ�� ���� ��ȣ�� �ƴϸ�
				if (s.empty() || s.top() != '(') {
					isVaild = false;
					break;
				}
				//�´� ��ȣ�̹Ƿ� ���ÿ���  pop()
				s.pop();
			}
			else if (ch == ']') {
				if (s.empty() || s.top() != '[') {
					isVaild = false;
					break;
				}
				s.pop();
			}
		}
		//������ �˻翡�� ���� ��ȣ�� ���ÿ� ���� �� �����Ƿ� �˻�
		if (!s.empty()) isVaild = false;
		cout << (isVaild ? "yes" : "no") << endl;
	}

	return 0;
}