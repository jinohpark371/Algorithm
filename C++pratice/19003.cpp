#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ispandrime(string& s, int L, int R) {
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
        int n, m;
        cin >> n >> m;
        vector<string> vec;
        vector<bool> selected(n, false);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            vec.push_back(s);
        }

        //해당 문자열의 reverse한 문자열 쌍의 수
        int pairCnt = 0;
        for (int i = 0; i < n; i++) {
            //기존에 추가된 짝 수행 x
            if (selected[i]) continue;
            //현재 문자 기준 반전 문자 생성
            string reversed = vec[i];
            reverse(reversed.begin(), reversed.end());
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (selected[j]) continue;
                if (vec[j] == reversed) {
                    selected[i] = true;
                    selected[j] = true;
                    pairCnt++;
                    break;
                }
            }

        }
        //중앙 중앙 팰린드롬의 최대 크기
        int middleCntMax = 0;
        for (int i = 0; i < n; i++) {
            //기존 pair 건너뛰기
            if (selected[i]) continue;
            //중앙 팰린드롬의 최대 크기 검사
            if (ispandrime(vec[i], 0, m - 1)) {
                middleCntMax = max(middleCntMax, (int)vec[i].length());
            }
        }


        //최대 크기
        cout << "#" << test_case << ' ' << (pairCnt * 2 * m) + middleCntMax << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}