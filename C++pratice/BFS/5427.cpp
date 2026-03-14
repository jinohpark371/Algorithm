#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int w, h;
vector<vector<int>> adj;
queue<pair<int, int>> qs; 
queue<pair<int, int>> qf;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int BFS() {
	int t = 0;
	while (!qs.empty()) {

		int fsize = qf.size();
		while (fsize--) {
			auto [x, y] = qf.front(); qf.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nextX = x + dx[dir];
				int nextY = y + dy[dir];

				if (nextX < 0 || nextX >=h
					|| nextY <0 || nextY >=w
					|| adj[nextX][nextY] == '#') continue;

				if (adj[nextX][nextY] == '.') {
					adj[nextX][nextY] = '*';
					qf.push({ nextX, nextY });
				}
			}
		}

		int ssize = qs.size();
		while (ssize--) {
			auto [x, y] = qs.front(); qs.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nextX = x + dx[dir];
				int nextY = y + dy[dir];

				if (nextX < 0 || nextX >=h
					|| nextY <0 || nextY >=w) return t + 1;

				if (adj[nextX][nextY] == '*' 
						|| adj[nextX][nextY] == '#') continue;

				if (adj[nextX][nextY] == '.') {
					adj[nextX][nextY] = '@';
					qs.push({ nextX, nextY });
				}
			}
		}
		t++;
	}
	
	return -1;
}


int main() {
	int t;
	cin >> t;

	

	while (t--) {
		cin >> w >> h;
		adj.assign(h , vector<int>(w , 0));


		for (int i = 0; i < h; i++) {
			string s; cin >> s;

			for (int j = 0; j < w; j++) {
				if (s[j] == '@') {
					qs.push({ i, j });
				}
				else if (s[j] == '*') {
					qf.push({ i, j });
				}
				adj[i][j] = s[j];
			}
		}

		int time = BFS();
		if (time == -1) cout << "IMPOSSIBLE" << '\n';
		else cout << time << '\n';
		
		while (!qs.empty()) qs.pop();
		while (!qf.empty()) qf.pop();
	}
	

}