#include<iostream>
#include <vector>
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
        vector<int> vec(2 * n);
        vector<bool> isDiscount(2 * n, false);
        for (int i = 0; i < 2 * n; i++) {
            cin >> vec[i];
        }

        for (int i = 2 * n - 1; i >= 0; i--) {
            //이미 할인가로 결정된 가격은 건너뛰기 
            if (isDiscount[i]) continue;
            //현재 가격을 기준으로 계산한 할인 가격
            int discount = vec[i] / 4;
            for (int j = i - 1; j >= 0; j--) {
                //할인가 찾기 
                if (!isDiscount[j] && vec[j] == vec[i] - discount) {
                    //할인 가격 표시
                    isDiscount[j] = true;
                    break;
                }
            }
        }
        //할인가 출력
        cout << '#' << test_case << ' ';
        for (int i = 0; i < 2 * n; i++) {
            if (isDiscount[i]) cout << vec[i] << ' ';
        }
        cout << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}