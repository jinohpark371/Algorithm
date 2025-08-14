#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
const ll INF = 2'000'000'000LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;
    vector<ll> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i];

    sort(vec.begin(), vec.end());

    // m이 0이면 자기 자신(같은 인덱스)로 차이 0을 만들 수 있으므로 답은 0
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }

    // 왼쪽 포인터(구간의 왼쪽 끝)
    int left = 0;
    ll mindiff = INF;

    // 오른쪽 포인터를 오른쪽으로만 확장
    for (int right = 0; right < n; ++right) {
        // 현재 right에 대해, m 이상이 되는 동안 left를 당겨서(구간을 줄여서) 최소 차이 갱신
        // left < right: 같은 원소를 동시에 사용할 수 없으니 경계 보호
        while (left < right && vec[right] - vec[left] >= m) {
            mindiff = min(mindiff, vec[right] - vec[left]);
            ++left; // 더 짧은 구간을 시도
        }

        // while을 빠져나온 시점에서 아직도 m 이상이면(= left==right였을 가능성),
        // 한 번 더 확인 (여기서는 left==right면 차이가 0이라 m>0에서는 갱신되지 않음)
        if (vec[right] - vec[left] >= m) {
            mindiff = min(mindiff, vec[right] - vec[left]);
        }
    }

    cout << mindiff << '\n';
    return 0;
}
