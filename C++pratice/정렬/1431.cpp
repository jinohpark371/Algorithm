#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int digit_sum(const string& s) {
	int sum = 0;
	//문자열의 각 문자를 비교하여 숫자문자라면 정수값 계산
	for (char c : s) {
		if (isdigit(c)) {
			sum += (c - '0');
		}
	}
	return sum;
}

//정렬 기준이 되는 비교함수
bool cmp(const string& a, const string& b) {
	//두 문자열의 길이가 다를때 길이비교
	//임의의 왼쪽인자 a가 오른쪽 인자 b보다 앞에 와야 한다면 true 리턴 아니면 false
	if (a.length() != b.length()) return a.length() < b.length();
	//두 문자열의 길이가 같다면 문자열에 포함된 숫자의 합을 비교
	int sa = digit_sum(a); int sb = digit_sum(b);
	if (sa != sb) return sa < sb;
	//두 문자열에서 숫자들의 합이 같다면 최종적으로 두 문자열 사전순 비교
	return a < b;
}

int main() {
	int n;
	cin >> n;
	vector<string> gitar(n);


	for (int i = 0; i < n; i++) cin >> gitar[i];


	sort(gitar.begin(), gitar.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << gitar[i] << '\n';
	}


	return 0;
}