#include <iostream>
#include<vector>
using namespace std;

int arr[6] = { 0 };

void DFS(vector<int>& vec, int st ,int depth) {
	if (depth == 6) {
		for (int i = 0; i < depth; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = st; i < vec.size(); i++) {
		arr[depth] = vec[i];
		DFS(vec,i+1 ,depth + 1);
	}
}

int main() {	
	while (true) {
		int k;
		cin >> k;
		if (k == 0) break;

		vector<int> vec;
		for (int i = 0; i < k; i++) {
			int num; cin >> num;
			vec.push_back(num);
		}

		DFS(vec, 0,0);
		cout << '\n';
	}
}