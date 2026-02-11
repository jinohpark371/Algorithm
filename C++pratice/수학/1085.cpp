#include <iostream>
#include <climits>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int mmin = INT_MAX;
	//현재점에서 위쪽 벽까지 거리
	mmin = min(mmin, h - y);
	//오른쪽 벽까지 거리
	mmin = min(mmin, w - x);
	//아래벽까지 거리
	mmin = min(mmin, y);
	//왼쪽벽까지 거리
	mmin = min(mmin, x);

	cout << mmin;
	return 0;
}