#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = { 1, 2, 3, 4, 5 };
vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, };

vector<int> solution(vector<int> answers) {
    vector<int> counts(4, 0);
    vector<pair<int, int>> scores;
    vector<int> answer;
    int idx_1 = 0;
    int idx_2 = 0;
    int idx_3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[idx_1])counts[1]++;
        if (answers[i] == two[idx_2])counts[2]++;
        if (answers[i] == three[idx_3])counts[3]++;

        idx_1 = (idx_1 + 1) % one.size();
        idx_2 = (idx_2 + 1) % two.size();
        idx_3 = (idx_3 + 1) % three.size();
    }

    for (int i = 1; i <= 3; i++) {
        scores.push_back({ counts[i], i });
    }

    sort(scores.begin(), scores.end());

    int maxScore = scores.back().first;
    for (int i = 0; i < scores.size(); i++) {
        if (maxScore == scores[i].first) {
            answer.push_back(scores[i].second);
        }
    }
    return answer;
}