#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int maxW = 0;
    int maxH = 0;
    for (auto card : sizes) {
        //더 긴변을 가로변으로 처리
        int big = max(card[0], card[1]);
        int small = min(card[0], card[1]);

        maxW = max(maxW, big);
        maxH = max(maxH, small);
    }



    answer = maxW * maxH;
    return answer;
}