#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
	stack<char> s;
	string str;
	while (true) {
		//cin은 공백전까지만 저장됨
		//get line은 공백 포함 한줄 전체를 읽어와서  str에 저장
		//문장 끝 \n은 제거 됨
		getline(cin, str);
		//입력종료 신호
		if (str == ".") break;

		bool isVaild = true;
		//이전에 입력받은 문자열에 대한 스택 초기화
		while (!s.empty()) s.pop();
		
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			// 여는 괄호는 stack에 push
			if (ch == '(' || ch == '[') {
				s.push(ch);
			}
			else if (ch == ')') {
				//스택이 비어 있거나 top이 해당 괄호의 여는 괄호가 아니면
				if (s.empty() || s.top() != '(') {
					isVaild = false;
					break;
				}
				//맞는 괄호이므로 스택에서  pop()
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
		//마지막 검사에서 여는 괄호만 스택에 있을 수 있으므로 검사
		if (!s.empty()) isVaild = false;
		cout << (isVaild ? "yes" : "no") << endl;
	}

	return 0;
}