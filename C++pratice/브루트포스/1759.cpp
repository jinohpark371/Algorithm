#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> vec;
vector<char> seq;
string vowels = "aeiou";

void DFS(int st, int depth, int vowel, int cons) {
	if (depth == l && vowel >= 1 && cons >= 2) {
		for (int i = 0; i < depth; i++) {
			cout << seq[i];
		}
		cout << '\n';
		return;
	}

	for (int i = st; i < c; i++) {
		//현재 함수의 vowel, cons 값은 절대 변하지 않는다
		//재귀 호출할 때 새로운 상태를 만들어 전달
		//재귀 호출 후 다음 숫자로 넘어갈때
		//본인에 대한 카운팅 제외를 위해서
		seq[depth] = vec[i];
		if (vowels.find(vec[i]) != string::npos) {
			DFS(i + 1, depth + 1, vowel + 1, cons);
		}
		else {
			DFS(i + 1, depth + 1, vowel, cons+1);
		}
		
	}
}

int main(){
	cin >> l >> c;
	vec.assign(c, 0);
	seq.assign(c, 0);
	for (int i = 0; i < c; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());
	DFS(0, 0, 0, 0);
}