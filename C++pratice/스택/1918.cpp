#include <iostream>
#include <stack>
using namespace std;

//우선순위 높은 연산자는
//"나중에 들어가서 먼저 나와야 한다"

int main() {
	string s;
	stack<char> st;
	cin >> s;
	for (char c : s) {
		if (isalpha(c)) {
			cout << c;
		}
		else if (c == '(') st.push(c);
		else {
			//스택이 비어있을땐 push
			if (st.empty()) { st.push(c); continue; }
			//)를 만낫을땐 (을 만날때까지 pop
			if (c == ')') {
				while (!st.empty() && st.top() != '(') {
					cout << st.top(); st.pop();
				}
				st.pop();
				continue;
			}

			// * or \ 일땐 본인보다 연산 우선순위가 
			// 같거나 높은걸 먼저 연산하기 때문에 같거나 높은 우선순위를
			//모두 pop하며 출력
			if (c == '*' || c == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					cout << st.top(); st.pop();
				}
				st.push(c);
			}
			//c: - or +
			//이것도 마찬가지 이유로 같거나 높은  (를 만나기 전까지 모두 출력
			else {
				//-, + 일땐 (전까지 모두 pop
				while (!st.empty() && (st.top() != '(')) {
					cout << st.top(); st.pop();
				}
				st.push(c);
			}
		}
	}

	//스택에 있는 나머지 연산들은 top쪽에 잇을 수록 연산 우선순위가 높으므로
	//먼저 출력 즉 먼저 연산됨
	while (!st.empty()) {
		cout << st.top(); st.pop();
	}
}