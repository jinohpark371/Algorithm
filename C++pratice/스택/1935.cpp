#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n;
	stack<double> st;
	map<char, int> mp;
	vector<int> vec;
	string s;
	
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}

	//문자 숫자 매핑
	for (int i = 0; i < n; i++) {
		mp['A' + i] = vec[i];
	}


	for (char c : s) {
		if (c != '*' && c != '+'
			&& c != '/' && c != '-') {
			st.push(mp[c]);
		}
		else {
			double num1 = st.top(); st.pop();
			double num2 = st.top(); st.pop();

			if (c == '/') st.push(num2 / num1);
			else if (c == '*') st.push(num2 * num1);
			else if (c == '+') st.push(num2 + num1);
			else if (c == '-') st.push(num2 - num1);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();
}