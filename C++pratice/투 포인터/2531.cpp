#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	vector<int> vec(n);
	vector<int> cnt(3001, 0);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	//초기 0번부터 k-1번까지 구간의 초밥 종류 계산 및 
	// 종료별 초밥 수 계산
	int kind = 0;
	for (int i = 0; i < k; i++) {
		if (cnt[vec[i]] == 0) kind++;
		cnt[vec[i]]++;
	}

	//쿠폰번호를 통한 초밥종류 증가 판별
	int ans = kind + (cnt[c] == 0);

	int left = 0;
	for (int i = 1; i < n; i++) {
		//왼쪽 구간 초밥 빼기
		cnt[vec[left]]--;
		//왼쪽 초밥을 뺐을 때 해당 초밥 번호에 대한 갯수가 0일떄 종류 감소
		if (cnt[vec[left]] == 0) kind--;
		//다음 구간 준비
		left++;

		//오른쪽 구간 초밥 추가
		int right = (i + k - 1) % n;
		//기존 카운트 배열에 없는 초밥이라면 종류 증가
		if (cnt[vec[right]] == 0)kind++;
		//현재 구간 해당 초밥 번호에 대한 갯수 증가
		cnt[vec[right]]++;

		//최대 종류 갱신
		ans = max(ans, kind+(cnt[c]==0));
	}

	cout << ans;
	return 0;
}