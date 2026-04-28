#include <iostream>
using namespace std;

bool board[100][100] = { false };

int main() {
	int n;
	cin >> n;
	while (n--) {
		int leftX, leftY;
		cin >> leftX >> leftY;

		for (int i = leftX; i < leftX + 10; i++) {
			for (int j = leftY; j < leftY + 10; j++) {
				board[i][j] = true;
			}
		}
	}

	int area = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j]) area++;
		}
	}

	cout << area;
	return 0;
}