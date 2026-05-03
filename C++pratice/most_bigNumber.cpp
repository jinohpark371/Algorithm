#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    for (int num : numbers) {
        vec.push_back(to_string(num));
    }

    // 두개를 순서를 바꿔가며 이어 붙였을때 더 큰 수라면 해당 a를 앞으로
    sort(vec.begin(), vec.end(), [](string a, string b) {return a + b > b + a; });

    for (string s : vec) {
        answer += s;
    }

    // 0000일때 그냥 0
    if (answer[0] == '0') return "0";

    return answer;
}