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

    // m�� 0�̸� �ڱ� �ڽ�(���� �ε���)�� ���� 0�� ���� �� �����Ƿ� ���� 0
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }

    // ���� ������(������ ���� ��)
    int left = 0;
    ll mindiff = INF;

    // ������ �����͸� ���������θ� Ȯ��
    for (int right = 0; right < n; ++right) {
        // ���� right�� ����, m �̻��� �Ǵ� ���� left�� ��ܼ�(������ �ٿ���) �ּ� ���� ����
        // left < right: ���� ���Ҹ� ���ÿ� ����� �� ������ ��� ��ȣ
        while (left < right && vec[right] - vec[left] >= m) {
            mindiff = min(mindiff, vec[right] - vec[left]);
            ++left; // �� ª�� ������ �õ�
        }

        // while�� �������� �������� ������ m �̻��̸�(= left==right���� ���ɼ�),
        // �� �� �� Ȯ�� (���⼭�� left==right�� ���̰� 0�̶� m>0������ ���ŵ��� ����)
        if (vec[right] - vec[left] >= m) {
            mindiff = min(mindiff, vec[right] - vec[left]);
        }
    }

    cout << mindiff << '\n';
    return 0;
}
