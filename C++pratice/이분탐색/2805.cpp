#include <iostream>
#include <vector>
using namespace std;

vector<int> trees;
int n, m;

long long binary_search(long long st, long long en) {
	//정답 저장용 변수
	long long result = 0;
	while (st <= en) {
		long long mid = (st + en) / 2;
		long long sum = 0;
		for (int t : trees) {
			//현재 나무 높이가 절단기 높이 보다 클때
			if (t > mid) {
				sum = sum + (t - mid);
			}
			
		}

		//현재 가져갈 수 있는 나무 양이 m보다 크거나 같을때
		//절단기 높이 탐색 범위를 현재 mid+1에서 en까지로 설정
		if (sum >= m) {
			result = mid; //정답 갱신
			st = mid + 1; //탐색범위 갱신
		}
		//현재 가져갈 수 있는 나무 양이 m보다 작을때
		//절단기 높이 탐색 범위를 현재 st에서 mid-1까지로 설정
		else if (sum < m) {
			en = mid - 1;
		}
	}

	return result;
}

int main() {
	cin >> n >> m;

	long long maxH = 0;
	for (int i = 0; i < n; i++) {
		long long num; cin >> num;
		maxH = max(num, maxH);
		trees.push_back(num);
	}

	cout << binary_search(0, maxH);


}