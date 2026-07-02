#include <iostream>
using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        // 원의 반지름
        int n;
        cin >> n;

        // 원 안에 포함되는 격자점의 개수
        int cnt = 0;

        // x좌표를 -n부터 n까지 탐색
        for (int x = -n; x <= n; x++) {

            // y좌표를 -n부터 n까지 탐색
            for (int y = -n; y <= n; y++) {

                // (x, y)가 반지름 n인 원 안(경계 포함)에 있으면 개수 증가
                if (x * x + y * y <= n * n)
                    cnt++;
            }
        }

        cout << "#" << i + 1 << ' ' << cnt << '\n';
    }
}