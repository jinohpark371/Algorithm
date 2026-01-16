#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string input_string) {

    //문자 등장 관리 집합
    set<char> appeared;
    //외톨이 문자 관리 집합
    set<char> lonely;
    string answer = "";

    for (int i = 1; i < input_string.length(); i++) {
        //연결이 끝났을때
        if (input_string[i - 1] != input_string[i]) {
            //현재 문자 방문 여부로 외톨이 판별
            if (appeared.count(input_string[i])) {
                lonely.insert(input_string[i]);
            }
            //연결이 끝난 이전 문자는 방문 처리
            appeared.insert(input_string[i - 1]);
        }
    }

    for (char c : lonely) {
        answer += c;
    }


    return answer.empty() ? "N" : answer;
}