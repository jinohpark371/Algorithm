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
        int n, p;
        cin >> n >> p;

        //누적합 경로
        long long sum = 0;
        //누적합 경로와 p가 겹치는 여부
        bool blocked = false;

        for (int i = 1; i <= n; i++) {
            sum += i;
            //누적합 경로와 겹칠 떄 
            if (sum == p) {
                blocked = true;
                break;
            }
        }
        //현재 선택의 갯수를 통한 이동가능한 최대 층
        long long s = n * (n + 1) / 2;

        //누적합 경로와 겹칠때 최대 층 유지를 위해 맨 아래 층 1 제외
        if (blocked) {
            cout << s - 1 << '\n';
        }
        //누적합 경로와 겹치지 않을 떄 최대 층이 정답
        else {
            cout << s << '\n';
        }


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}