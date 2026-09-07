#include<iostream>
#include <set>
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

        vector<int> vecA;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            vecA.push_back(num);
        }

        vector<int> vecB;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            vecB.push_back(num);
        }

        set<int> setA;
        set<int> setB;
        int idxA = 0;
        int idxB = 0;
        int order = 0;
        while (idxA < n || idxB < n) {
            //A팀 선수 뽑기
            if (order % 2 == 0) {
                //이미 A팀에 존재하거나 B팀에 해당 선수 번호 존재여부 확인
                //존재시 선발되지 않고 다음으로 높은 선발 순위를 가진 위치까지 
                while (idxA < n && setA.count(vecA[idxA]) || setB.count(vecA[idxA])) idxA++;
                if(idxA < n)  setA.insert(vecA[idxA]);
               
            }
            //B팀 선수 뽑기
            else {
                //이미 B팀에 존재하거나 A팀에 해당 선수 번호 존재여부 확인
                //존재시 선발되지 않고 다음으로 높은 선발 순위를 가진 위치까지 이동
                while (idxB < n && setA.count(vecB[idxB]) || setB.count(vecB[idxB])) idxB++;
                if (idxB < n ) setB.insert(vecB[idxB]);


            }
            order++; //순서변경

        }
        //A, B팀 소속여부 출력
        for (int i = 1; i <= n; i++) {
            if (setA.count(i)) cout << "A";
            else cout << "B";
        }
        cout << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.

}