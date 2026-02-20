#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main() {
	int st, en;
	cin >> st >> en;

	for (int i = 1; vec.size() <=1000; i++) {
		int j = i;
		while (j--) vec.push_back(i);
	}
	
	long long sum = 0;
	for (int i = st-1; i <= en-1; i++) {
		sum += vec[i];
	}

	cout << sum;
	return 0;
}