#include<iostream>
#include<algorithm>

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

        string s, e;
        cin >> s >> e;

        bool isReverse = false;
        //e에게 적용한 연산을 롤백하는 방식으로 되돌려서 s와 같은 상태가 될 수 있는지 확인 
        while (s.length() != e.length()) {
            //일반 상태(뒤쪽 문자 확인)
            if (!isReverse) {
                if (e[e.length() - 1] == 'X') {
                    e.erase(e.length() - 1);
                }
                else if (e[e.length() - 1] == 'Y') {
                    //뒤집힘 여부 토글
                    isReverse = !isReverse;
                    e.erase(e.length() - 1);
                }
            }
            //뒤집힌 상태(앞쪽 문자 확인)
            else {
                if (e[0] == 'X') {
                    e.erase(e.begin());
                }
                else if (e[0] == 'Y') {
                    //뒤집힘 여부 토글
                    isReverse = !isReverse;
                    e.erase(e.begin());
                }
            }
        }

        //뒤집힘 상태일때 처리
        if (isReverse) reverse(e.begin(), e.end());

        //e에 적용한 연산을 롤백해서 시작상태 s와 같다면 유효함
        if (s == e) {
            cout << "#" << test_case << " " << "Yes" << '\n';
        }
        else {
            cout << "#" << test_case << " " << "No" << '\n';
        }

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}