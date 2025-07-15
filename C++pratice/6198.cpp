#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        while (!s.empty() && s.top() <= h) {
            s.pop();
        }

        ans += s.size();

        s.push(h);
    }

    cout << ans << '\n';
    return 0;
}
