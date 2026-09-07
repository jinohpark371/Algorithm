#include<iostream>

using namespace std;

bool isPalindrome(string& s, int L, int R) {
    while (L < R) {
        if (s[L] != s[R]) return false;
        L++;
        R--;
    }
    return true;
}

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
        int n = s.length();
        //전체가 회문인지 확인
        bool whole = isPalindrome(s, 0, n - 1);
        //오른쪽 영역이 회문인지 확인
        bool right = isPalindrome(s, 0, n / 2 - 1);
        //왼쪽 영역이 회문인지 확인
        bool left = isPalindrome(s, n / 2 + 1, n - 1);
        if (whole && right && left) cout << "#" << test_case << ' ' << "YES" << '\n';
        else cout << "#" << test_case << ' ' << "NO" << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}