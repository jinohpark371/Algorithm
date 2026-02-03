#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> freq;
vector<string> words;

bool cmp(string a, string b) {
	if (freq[a] != freq[b]) {
		return freq[a] > freq[b];
	}
	else if (a.length() != b.length()) {
		return a.length() > b.length();
	}

	//사전순 정렬
	return a < b;
}

int main() {
	
	int N, M;
	cin >> N >> M;

	//M개 이상인 단어만 입력 받기
	for(int i=0; i<N; i++){
		string word;
		cin >> word;
		if (word.length() >= M) {
			//처음 들어온 단어만 저장
			if (!freq.count(word)) {
				words.push_back(word);
			}
			freq[word]++; //빈도 수 증가
		}
	}

	//단어 정렬
	sort(words.begin(), words.end(), cmp);

	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << '\n';
	}
}