#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> vec1(n); //원본
	vector<int> vec2(n); //정렬용

	for (int i = 0; i < n; i++) {
		cin >> vec1[i];
		vec2[i] = vec1[i];
	}

	sort(vec2.begin(), vec2.end());

	//N^2의 시간복잡도
	/*for (int i = vec1.size() - 1; i >0; i--) {
		if (vec1[i] == vec1[i - 1]) {
			vec1.erase(vec1.begin()+i); erase는 O(N) 시간 걸림!
		} erase()는 지운 이후의 모든 원소를 앞으로 이동시키기 때문에 최악의 경우 O(N^2) 이 된다.
	}*/
	/*unipue를 통해 벡터에 있는 중복된 요소들을 제거할 수 있고 새로운 끝 위치를 반환
	대상 벡터는 정렬되어야 하고 중복이 제거된 마지막 요소 다음 위치의 반복자를 반환
	실제로 컨테이너의 크기가 줄지는 않고 단지 중복된 값들을 뒤로 밀어냄
	*/
	//시간 복잡도:  O(N)
	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
	//vec2.erase(새로운 끝, vec2.end())
	//erase()는 [새로운 끝, vec2.end()) 범위를 벡터에서 실제로 삭제함
	//뒤로 밀려난 중복요소들을 벡터에서 제거 (N)

	//앞당길 필요 없이 그냥 통째로 잘라내기만 하면 됨

	for (int item : vec1) {
		int count = lower_bound(vec2.begin(), vec2.end(), item) - vec2.begin();
		cout << count << " ";
	}

	return 0;
}