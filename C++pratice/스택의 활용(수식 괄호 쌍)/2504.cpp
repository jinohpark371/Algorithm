#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	stack<char> s;
	cin >> str;
	int num = 1; //괄호의 가중치를 누적할 값
	int sum = 0; //누적한 값을 누적해서 더할 값
	for (int i = 0; i < str.length(); i++) {
		//여는 괄호가 나올시 가중치 2증가
		if (str[i] == '(') {
			num *= 2;
			s.push(str[i]);
		}
		//여는 괄호가 나올시 가중치 3증가
		else if (str[i] == '[') {
			num *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			//이 때 스택이 비어 있거나 top이 (이 아닐시 괄호는 유효하지 않음
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			// )닫는 괄호가 나올시 그동안 쌓였던 가중치를
			//몰아서 더함
			if (str[i - 1] == '(') sum += num;
			//( 하나 정리 후에 자신의 가중치는 2로 나누어 정리
			s.pop();
			num /= 2;
		}
		else {
			//이 때 스택이 비어 있거나 top이 [이 아닐시 괄호는 유효하지 않음
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			// ]닫는 괄호가 나올시 그동안 쌓였던 가중치를
			//몰아서 더함
			if (str[i - 1] == '[') sum += num;
			s.pop();
			//] 하나 정리 후에 자신의 가중치는 2로 나누어 정리
			num /= 3;
		}
	}
	// ( 하나이거나  스택에 여는 괄호가 남아 있다면 괄효는 유효하지 않음
	if (s.empty())cout << sum;
	else cout << 0;
	return 0;
}
