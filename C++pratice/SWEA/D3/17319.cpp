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
        int n;
        cin >> n;

        string s, answer;
        cin >> s;

        answer = "No";
        //n이 1이거나 짝수가 아니면 둘로 나뉠 수 없음
        if (n % 2 == 0) {
            //중심을 기준으로 둘로 나누기
            int mid = n / 2;
            string left = s.substr(0, mid);
            string right = s.substr(mid, mid);

            if (left == right) answer = "Yes";
        }

        cout << '#' << test_case << ' ' << answer << '\n';


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}