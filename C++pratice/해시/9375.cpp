#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int t;
	unordered_map<string, int> mp;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string wear, kind;
			cin >> wear >> kind;
			mp[kind]++;
		}
		
		int ans = 1;
		for (auto &p : mp) {
			//해당 종류의 없을 입지 않을 떄 경우를 추가해서 계산
			ans *= (p.second + 1);
		}

		//모든 옷을 입지 않았을 때 경우를 제외
		cout << ans -1 << '\n';
		
		//맵 초기화
		mp.clear();
	}
}