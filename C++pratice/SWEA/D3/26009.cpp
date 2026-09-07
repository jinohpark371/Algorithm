#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        const long long MOD = 998244353;
        long long a, b, c;
        cin >> a >> b >> c;
        //모든 조합을 만들어내는게 아닌 각 항을 분배법칙으로 각 항의 합을 구한 후 곱함
        long long sumA = a * (a + 1) / 2;
        long long sumB = b * (b + 1) / 2;
        long long sumC = c * (c + 1) / 2;

        //(a×b)modm=((amodm)(bmodm))modm
        //세개를 한꺼번에 곱하는 건 overflow 위험 존재
        long long ans = sumA % MOD;
        ans = (ans * (sumB % MOD)) % MOD;;
        ans = (ans * (sumC % MOD)) % MOD;


        cout << ans << '\n';


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}