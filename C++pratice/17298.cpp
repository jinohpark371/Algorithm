#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec1(n);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec1[i]= num;
	}

	vector<int> vec2(n, -1);
	stack<int> s;

	for (int i = 0; i < n; i++) {
		while (!s.empty() && vec1[s.top()] < vec1[i]) {
			vec2[s.top()] = vec1[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i];
		if (i != vec2.size()) cout << " ";
	}
	
}