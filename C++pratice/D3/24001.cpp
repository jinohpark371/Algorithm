#include<iostream>
#include <cmath>

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
        string s;
        cin >> s;

        /*
        ?를 중간에 어떻게 선택하든
        결국 현재 위치를 가장 멀리 만드는 방향은
        한쪽 방향으로 최대한 몰아서 가는 선택
        이미 존재하는 L, R은 서로 상쇄되기 때문에
        ?를 섞어서 바꿔봐야 극값은
        전부 L 또는 전부 R 처리 중 하나에서 나온다
        */

        int mmax = 0;
        //?를 항상 L로 처리했을 때 거리
        int distL = 0;
        //?를 항상 R로 처리했을 때 거리
        int distR = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                distL--;
                distR--;
            }
            else if (s[i] == 'R') {
                distL++;
                distR++;
            }
            //?는 L, R로 각각 처리했을 때 거리
            else {
                distL--;
                distR++;
            }
            //?를 L로 처리했을때 거리와 R로만 처리했을때 거리로 각각 최댓값 계산
            mmax = max(mmax, abs(distL));
            mmax = max(mmax, abs(distR));
        }
        cout << mmax << '\n';


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}