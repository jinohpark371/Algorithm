#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string, int> mp;
    for (auto cloth : clothes) {
        mp[cloth[1]]++;
    }

    for (auto m : mp) {
        answer *= (m.second + 1); //해당 옷을 안입는 경우의 수 추가
    }


    return answer - 1; //모두 안입는 경우 제외
}