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
        string s;
        int k;
        cin >> s >> k;

        if (k == 0) {

            if (s[0] == 'o') {
                cout << "#" << test_case << " " << 0 << '\n';
            }
            else if (s[1] == 'o') {
                cout << "#" << test_case << " " << 1 << '\n';
            }
            else {
                cout << "#" << test_case << " " << 2 << '\n';
            }

        }
        //왼쪽, 오른쪽이 시작점일때 홀수번쨰엔 중간 짝수 번쨰엔 왼/오
        else if (s[0] == 'o' || s[2] == 'o') {

            if (k % 2 == 1) {
                cout << "#" << test_case << " " << 1 << '\n';
            }
            else {
                cout << "#" << test_case << " " << 0 << '\n';
            }
        }
        //중간이 시작점일떄 홀수 번쨰엔 왼/오 짝수 번쨰엔 중간
        else if (s[1] == 'o') {
            if (k % 2 == 1) {
                cout << "#" << test_case << " " << 0 << '\n';
            }
            else {
                cout << "#" << test_case << " " << 1 << '\n';
            }
        }

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}