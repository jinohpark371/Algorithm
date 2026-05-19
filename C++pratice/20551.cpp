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
        vector<int> vec(3);

        for (int i = 0; i < 3; i++) {
            cin >> vec[i];
        }

        //가장 작은 1이 마지막 상자에 있을 때 불가능

        bool isValid = true;
        int ans = 0;

        if (vec[2] == 1) {
            isValid = false;
        }
        else {
            if (vec[1] >= vec[2]) {
                //최소로 해야하는 연산 계산
                ans += vec[1] - (vec[2] - 1);
                //연산 후 두번쨰 사탕 갯수 상태
                vec[1] = vec[2] - 1;
            }

            //2번째 상자에 적용될 사탕 갯수가 1이하일때 문제 조건 불충족
            if (vec[2] <= 1) isValid = false;

            if (vec[0] >= vec[1]) {
                //최소로 해야하는 연산 계산
                ans += vec[0] - (vec[1] - 1);
                vec[0] = vec[1] - 1;
            }

            //1번째 상자에 적용될 사탕의 갯수가 1보다 적을때 문제 조건 불충족
            if (vec[0] < 1) isValid = false;
        }

        if (isValid) {
            cout << "#" << test_case << ' ' << ans << '\n';
        }
        else {
            cout << "#" << test_case << ' ' << -1 << '\n';
        }

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}