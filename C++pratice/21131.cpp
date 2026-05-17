#include<iostream>
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
        int n; cin >> n;
        vector<vector<int>> vec(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> vec[i][j];
            }
        }
        //연산 횟수 여부
        int ans = 0;
        //전치 여부
        bool flipped = false;

        //가장 바깥 행부터 탐색
        for (int i = n; i >= 1; i--) {

            //전치 여부에 따라
            //정상/비정상을 반대로 해석

            bool ok;
            //정상 상태 일떄
            if (!flipped) {
                //정상 상태의 행의 첫번쨰 값 확인
                ok = (vec[i][1] == (i - 1) * n + 1);
            }
            //전치 상태
            else {
                //전치 상태일땐 행의 첫번재 값 확인
                ok = (vec[i][1] == i);
            }

            //정상상태 아닐 떄
            if (!ok) {
                //연산 횟수 증가
                ans++;
                //전치 여부 토글
                flipped = !flipped;
            }

        }
        cout << ans << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}