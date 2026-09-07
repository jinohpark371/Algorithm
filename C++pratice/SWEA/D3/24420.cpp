#include<iostream>
#include<vector>
#include <set>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen(&quot;input.txt&quot;, &quot;r&quot;, stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, m;
        cin >> n >> m;

        set<int> setA;
        set<int> setB;

        for (int i = 0; i < n; i++) {
            int item;
            cin >> item;
            setA.insert(item);
        }

        for (int i = 0; i < m; i++) {
            int item;
            cin >> item;
            setB.insert(item);
        }

        //A의 모든 원소가 B에 존재 여부
        bool BhasA = true;
        //B의 모든 원소가 A에 존재 여부
        bool AhasB = true;

        //A의 모든 원소가 B에 존재 여부 확인
        for (int itemA : setA) {
            if (!setB.count(itemA)) {
                BhasA = false;
                break;
            }
        }
        //B의 모든 원소가 A에 존재 여부 확인         
        for (int itemB : setB) {
            if (!setA.count(itemB)) {
                AhasB = false;
                break;
            }
        }

        if (BhasA && AhasB) {
            cout << '=' << '\n';
        }
        else if (BhasA && !AhasB) {
            cout << '<' << '\n';
        }
        else if (AhasB && !BhasA) {
            cout << '>' << '\n';
        }
        else {
            cout << '?' << '\n';
        }

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}