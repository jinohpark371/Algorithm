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
        int h, w;
        cin >> h >> w;

        vector<vector<char>> board(h, vector<char>(w, ' '));

        bool isFull = true;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == '.') isFull = false;
            }
        }

        int rowCnt = 0;
        //행방향 검사
        for (int i = 0; i < h; i++) {
            bool isValid = true;
            for (int j = 0; j < w; j++) {
                if (board[i][j] != '#') {
                    isValid = false;
                    break;
                }
            }
            if (isValid) rowCnt++;
        }
        //열방향 검사
        int colCnt = 0;
        for (int i = 0; i < w; i++) {
            bool isValid = true;
            for (int j = 0; j < h; j++) {
                if (board[j][i] != '#') {
                    isValid = false;
                    break;
                }
            }
            if (isValid) colCnt++;
        }

        if (!isFull) {
            cout << rowCnt + colCnt << '\n';
        }
        else {
            cout << min(rowCnt, colCnt) << '\n';
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}