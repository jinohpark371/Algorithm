#include <iostream>
#include <vector>
using namespace std;

int n, m;
int d = 2;
bool isCollect = false;
vector<pair<char, int>> vec;
vector<pair<char, int>> seq;
string copyTarget = "";

void DFS(int st, int depth) {
	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			if (seq[i].first != copyTarget[i]) return;
		}

		bool isVaild = true;
		for (int i = 1; i < depth; i++) {
			if (seq[i].second - seq[i - 1].second <= d) continue;
			else {
				isVaild = false;
				break;
			}
		}

		if (isVaild) {
			isCollect = true;
		}
		return;

	}

	for (int i = st; i < n; i++) {
		seq[depth].first = vec[i].first;
		seq[depth].second = vec[i].second;
		DFS(i + 1, depth + 1);
	}
}


int main() {
	string text = "sdfsdgsdg";
	string target = "sdd";

	n = text.length();
	m = target.length();
	copyTarget = target;

	for (int i = 0; i < n; i++) {
		vec.push_back({ text[i], i });
	}

	seq.assign(m, { ' ', 0 });

	DFS(0, 0);


	cout << isCollect;
}