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
			// 쇠막대기의 시작을 나타내므로 스택에 push
			s.push(ans[i]);
		}
		else {
			// 닫는 괄호 ')'일 때
			s.pop(); // 바로 앞 괄호 '('와 짝을 이루므로 pop

			if (ans[i - 1] == ')') {
				// 직전도 ')'라면 -> 쇠막대기의 끝을 의미 -> 조각 1개 추가
				result++;
			}
			else {
				// 직전이 '('라면 -> 레이저 -> 현재 스택 크기만큼 조각 생성
				// 현재 스택의 크기가 겹치는 막대의 갯수
				result += s.size();
			}
		}
	}
	cout << result;
	return 0;
}
