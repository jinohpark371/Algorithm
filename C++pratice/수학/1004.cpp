#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;

		int count = 0;
		while (n--) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			
			bool startInside = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r*r;
			bool endInside = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r*r;
		
			if (startInside != endInside) {
				count++;
			}
		}

		cout << count << '\n';
		count = 0;

		
	}
}