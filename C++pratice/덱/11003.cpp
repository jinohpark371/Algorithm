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
        
        //덱에선 새롭게 들어오는 수와 큐의 뒤에서 부터 비교하여
        //항상 오름차순을 유지하고 가장 작은 값이 앞에 오게 유지
        while (!dq.empty() && dq.back().second >= num) {
            dq.pop_back();
        }

        //새롭게 들어온 숫자는 항상 덱 뒤에 삽입

        dq.push_back({ i, num });

        //범위를 벗어난 최솟값은 큐의 맨앞에 항상 존재하므로 삭제
        if (dq.front().first <= i - m) {
            dq.pop_front();
        }

        cout << dq.front().second<< " ";
    }
   
    return 0;
}