#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int h = 1; h * h <= yellow; h++) {
        //약수 쌍 찾기
        if (yellow % h == 0) {
            int w = yellow / h;
            //yellow쪽 안쪽 넓이를 뺀 게 brown 넓이와 같다면 정답
            if (brown == (w + 2) * (h + 2) - w * h) {
                answer.push_back(w + 2);
                answer.push_back(h + 2);
                break;
            }
        }
    }
    return answer;
}