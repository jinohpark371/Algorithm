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
        //64비트 정수(long long)으로 저장할 수 없을 정도로 상당히 큰 범위
        //string으로 처리
        string A, B;
        cin >> A >> B;
        //A == B 이면
        //수가 하나뿐이니까 답은 그 수 자체.
        //A < B 이면
        //구간 안에 반드시 연속된 두 수가 존재 gcd가 1.
        //gcd(n,n+1)=1

        string answer;
        if (A == B) {
            answer = A;
        }
        else {
            answer = '1';
        }

        cout << '#' << test_case << ' ' << answer << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}