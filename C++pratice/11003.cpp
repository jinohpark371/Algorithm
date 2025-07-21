#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    deque<pair<int, int>> dq;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        //������ ���Ӱ� ������ ���� ť�� �ڿ��� ���� ���Ͽ�
        //�׻� ���������� �����ϰ� ���� ���� ���� �տ� ���� ����
        while (!dq.empty() && dq.back().second >= num) {
            dq.pop_back();
        }

        //���Ӱ� ���� ���ڴ� �׻� �� �ڿ� ����

        dq.push_back({ i, num });

        //������ ��� �ּڰ��� ť�� �Ǿտ� �׻� �����ϹǷ� ����
        if (dq.front().first <= i - m) {
            dq.pop_front();
        }

        cout << dq.front().second<< " ";
    }
   
    return 0;
}