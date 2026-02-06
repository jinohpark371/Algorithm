#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;

    //참가자 이름에 대한 인원 수 증가
    for (auto p : participant) {
        m[p]++;
    }

    //참가자 이름으로 완주한 사람빼기
    for (auto c : completion) {
        m[c]--;
    }

    //미완주자 찾기
    for (auto i : m) {
        //참가자 이름을 카운트하고 완주자 목록에서 해당 이름을 빼줄때 0이 아니라면 완주자가 아님
        if (i.second != 0) {
            answer = i.first;
            break; //오직 한 명 밖에 없음
        }
    }

    return answer;
}