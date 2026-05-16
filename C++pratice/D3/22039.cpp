#include<iostream>

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
        int n; cin >> n;

        //항 3개씩 묶어서 2 / 1 이렇게 BA에 분배하는데
        //나머지 1개가 남으므로 불가능
        if (n % 3 == 1) {
            cout << "impossible" << '\n';
        }
        else {
            //나머지 2개는 1 1 이므로 각각 집합에 분배
            if (n % 3 == 2) cout << "BA";

            // 작은 2개항 / 큰 1개의 항 각 집합에 분배
            int t = n / 3;
            while (t--) {
                cout << "BBA";
            }
            cout << "\n";
        }

    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}