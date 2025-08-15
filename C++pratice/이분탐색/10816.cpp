#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//이진 탐색 함수
int lower_bound(vector<int>& arr, int target) {
	//초기 검색 범위
	int left = 0, right = arr.size();
	// 탐색이 좁혀져서 target 이상이 처음 나오는 위치가 left에 정확히 남음
	//종료 시 left == right
	while (left < right) {
		//중간 위치 계산
		int mid = (left + right) / 2;
		//mid 값이 target보다 작다면
		//target은 오른쪽에 있음 왼쪽은 버림
		if (arr[mid] < target)
			left = mid + 1;
		//지금값이 target이상이면 지금 이 위치도 정답 후보니까 버리지 않고 유지
		else
			right = mid;
	}

	return left; // or right (둘 다 같음)
}

int upper_bound(vector<int>& arr, int target) {
	int left = 0, right = arr.size();

	while (left < right) {
		int mid = (left + right) / 2;

		//target값이 mid값보다 크거나 값으면
		//범위를 현재 중앙에서 +1한 위치에서 시작하여
		//다시비교하면서 left와 right가 같아진 위치가
		//처음으로 초과한 위치
		if (arr[mid] <= target)
			left = mid + 1;
		else
			right = mid;
	}

	return left; // 또는 right
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	vector<int> cards(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cards[i] = num;
	}
	sort(cards.begin(), cards.end());

	cin >> m;
	while (m--){
		int x;
		cin >> x;
		//value 이상인 첫 번째 위치의 iterator를 반환, value가 처음 나오는 위치
		int lower = lower_bound(cards.begin(), cards.end(), x) - cards.begin();
		//value 초과인 첫 번째 위치의 iterator를 반환, value 다음 값이 처음 나오는 위치 
		int upper = upper_bound(cards.begin(), cards.end(), x) - cards.begin();
		//lower_bound와 upper_bound는 반드시 정렬된 컨테이너에서만 사용 가능
		//lower_bound가 반환하는 건 위치(주소)고 그 위치에서 v.begin()(즉, 시작 주소)를 빼면
		//시작부터 몇 칸 떨어져 있는지 = 인덱스 를 알 수 있음

		//초과된 첫번째 인덱스에서 처음으로 해당 값 이상인 인덱스를 빼면 정렬된 곳에서 값이 연속되어 있다면
		//이 범위의 값은 해당 카드가 출현한 갯수
		int count = upper - lower;

		cout << count << " ";
	}

	return 0;
}