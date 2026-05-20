#include<iostream>
#include<vector>

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
        int n, m;
        cin >> n >> m;
        vector<string> vecS(n, " ");
        vector<string> vecT(m, " ");

        for (int i = 0; i < n; i++) {
            cin >> vecS[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> vecT[i];
        }

        int q;
        cin >> q;

        cout << '#' << test_case << ' ';
        while (q--) {
            int year;
            cin >> year;

            cout << vecS[(year - 1) % n] << vecT[(year - 1) % m] << ' ';
        }
        cout << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}