#include <iostream>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int arr[1000][1000] = { 0 };

int main() {
	int n, target;
	cin >> n;
	cin >> target;

	int x = n / 2, y = n / 2;
	arr[x][y] = 1;

	pair<int, int> ans;
	if (target == 1) ans = { x + 1, y + 1 };

	int len = 1, dir = 0, num = 1;
	while (num < n * n) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < len; j++) {
				if (num == n * n) break;

				num++;
				int nextx = x + dx[dir];
				int nexty = y + dy[dir];
				arr[nextx][nexty] = num;

				x = nextx;
				y = nexty;
				
				if (num == target) ans = { nextx + 1, nexty + 1 };

			}
			dir = (dir + 1) % 4;
		}
		len++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << ans.first << ' ' << ans.second;
	return 0;
}