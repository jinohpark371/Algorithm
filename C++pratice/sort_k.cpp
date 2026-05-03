#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sorted;
    for (auto command : commands) {
        sorted = array;
        //시작범위에서 끝범위까지만 정렬
        sort(sorted.begin() + command[0] - 1, sorted.begin() + command[1]);
        //해당 범위 내에서 k번째 수 저장
        answer.push_back(sorted[command[0] - 1 + command[2] - 1]);
        sorted.clear();
    }
    return answer;
}