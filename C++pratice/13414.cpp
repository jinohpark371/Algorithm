#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}


int main() {
	int k, l;
	cin >> k >> l;

	map<string, int> mp;
	vector<pair<string, int>> vec;

	//현재 클릭 순서
	int order = 1;
	while (l--) {
		string s;
		cin >> s;
		//현재 들어온 학번에 대한 현재 순서 할당
		if (!mp.count(s)) { mp[s]=order; }
		else {
			//이미 대기열에 존재시 해당 학번 기존 순서에서 현재 순서로 변경
			//현재 순서 증가
			mp[s] = order++;
		}
		
	}

	for (auto m : mp) {
		vec.push_back(m);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < k && i<vec.size(); i++) {
		cout << vec[i].first << '\n';
	}
}