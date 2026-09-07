#include<iostream>
#include<vector>
#include<cmath>
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

        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        int diff = 0;
        int idx = -1;
        for (int i = 1; i < n - 1; i++) {
            //중간좌표를 경유하는 거리
            int dist1 = abs(vec[i] - vec[i - 1]) + abs(vec[i + 1] - vec[i]);
            //중간좌표를 건너뛰었을 때 거리
            int dist2 = abs(vec[i + 1] - vec[i - 1]);
            //건너뛰었을때 더 적은 거리일떄
            //최대 감소량을 가진 좌표 처리
            if (dist2 < dist1) {
                if (diff < dist1 - dist2) {
                    diff = dist1 - dist2;
                    idx = i;
                }
            }
        }
        //전체 거리 계산
        int total = 0;
        for (int i = 1; i < n; i++) {
            int temp = abs(vec[i] - vec[i - 1]);
            total += temp;
        }
        //새 전체 거리=원래 전체 거리−dist1+dist2
        //원래 전체 거리−(dist1−dist2)
        //모든 정점을 고려한 거리 -  제외된 좌표에 대한 감소량 = 해당 좌표를 제외한 총 거리
        cout << total - diff << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}