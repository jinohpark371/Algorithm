#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, k;

	while (cin >> n >> k) {

		//초기 도장 갯수
		long long stemp = n;
		//초기 치킨 주문수
		long long chiecken = n;

		while (stemp >= k) {
			long long newcChiecken = stemp / k;//현재 도장을 이용한 치킨 수
			chiecken += newcChiecken; //현재 먹은 치킨을 누적
			//현재 치킨을 주문하면서 생기는 도장 계산
			//도장을 k의 배수 사용하고 남은 도장 수 + 도장을 이용한 치킨 주문 수
			stemp = stemp % k + newcChiecken;
		}

		//지금까지 먹은 치킨 수
		cout << chiecken << '\n';
	}
	
	return 0;
}