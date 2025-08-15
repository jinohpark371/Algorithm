#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    // �� �� �ִ� ������ �� ����
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        //���� ž h�� ������ top�� �� �� �ڽ��� �� �� �ִ� ������ �����
        while (!s.empty() && s.top() <= h) {
            s.pop();
        }
        //���� ž�� �� �� �ִ� ���� ���� ����
        ans += s.size();

        //���� ž ���ÿ� push�Ͽ� ���� ��� �غ�
        s.push(h);
    }

    cout << ans << '\n';
    return 0;
}
