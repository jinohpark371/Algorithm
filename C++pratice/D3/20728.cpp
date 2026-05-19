#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, k;
        cin >> n >> k;

        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());
        int mmin = 1e9; //1 × 10^9
        //정렬 후 k 크기의 범위 안에서 사탕 갯수의 차이 중 가장 작은 차이를 확인
        for (int left = 0; left <= n - k; left++) {
            int right = left + k - 1;
            mmin = min(mmin, vec[right] - vec[left]);

        }
        cout << '#' << test_case << " " << mmin << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}