#include<iostream>
#include <map>
#include <string>
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

        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        bool isValid = true;
        for (auto m : mp) {
            if (m.second != 2) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            for (auto m : mp) {
                int first = s.find(m.first);
                int second = s.rfind(m.first);

                int dist = m.first - '0';

                if ((second - first - 1) != dist) {
                    isValid = false;
                    break;
                }

            }
        }

        if (isValid) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}