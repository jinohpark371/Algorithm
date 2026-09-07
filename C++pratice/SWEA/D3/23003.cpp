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
    string arr[6] = { "red", "orange", "yellow", "green", "blue", "purple" };

    for (test_case = 1; test_case <= T; ++test_case)
    {

        string s, t;
        cin >> s >> t;

        int idxS = -1;
        int idxT = -1;
        for (int i = 0; i < 6; i++) {
            if (s == arr[i]) idxS = i;
            if (t == arr[i]) idxT = i;
        }

        // 두 색상이 같을때
        if (idxS == idxT) {
            cout << "E" << '\n';
        }
        //한쪽 기준 색상으로 좌우로 한변을 공유하는지 확인
        else if ((idxS + 5) % 6 == idxT ||
            (idxS + 1) % 6 == idxT) {
            cout << "A" << '\n';
        }
        //마주보고 있는 색상인지 확인
        else if ((idxS + 3) % 6 == idxT) {
            cout << "C" << '\n';
        }
        else {
            cout << "X" << '\n';
        }


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}