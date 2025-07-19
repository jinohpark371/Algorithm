#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    // 볼 수 있는 옥상의 총 개수
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        //현재 탑 h와 스택의 top을 비교 후 자신을 볼 수 있는 빌딩만 남기기
        while (!s.empty() && s.top() <= h) {
            s.pop();
        }
        //현재 탑을 볼 수 있는 빌딩 갯수 세기
        ans += s.size();

        //현재 탑 스택에 push하여 다음 계산 준비
        s.push(h);
    }

    cout << ans << '\n';
    return 0;
}
