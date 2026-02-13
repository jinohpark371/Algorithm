#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    //전화번호 사전순 정렬시 다른 문자열의 접두어가 될 수 있는 문자는 항상 앞에 존재
    //118 -> 1183 -> 119 -> 1198
    //접두어가 될 수 있는 관계는 연속적으로 모여 있게 됨
    for (int i = 0; i < phone_book.size() - 1; i++) {
        //첫 위치에 존재시
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            answer = false;
            break;
        }
    }
    return answer;
}