#include<iostream>
#include <deque>
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

        deque<char> dq;
        for (char c : s) {
            dq.push_back(c);
        }

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            long long command;
            cin >> command;
            //문자열의 크기 만큼 연산 시 원래 본인으로 돌아오므로 나머지 만큼만 계산
            command %= (long long)s.size(); //s.size()는 size_t이므로 long long 으로 형변환
            //맨 앞글자 제거후 뒤에 붙이기
            if (command > 0) {
                while (command--) {
                    char tmp = dq.front();
                    dq.pop_front();
                    dq.push_back(tmp);
                }
            }
            //맨 뒤글자 제거 후 앞에 붙이기
            else {
                command = abs(command);
                while (command--) {
                    char tmp = dq.back();
                    dq.pop_back();
                    dq.push_front(tmp);
                }
            }

        }

        while (!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
        cout << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}