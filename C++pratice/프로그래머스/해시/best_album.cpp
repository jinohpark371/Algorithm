#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, string>> sorted_cnt;
    map<string, int> cnt;
    map<string, vector<pair<int, int>>> mp;

    int ssize = genres.size();

    for (int i = 0; i < ssize; i++) {
        cnt[genres[i]] += plays[i];
        mp[genres[i]].push_back({ plays[i], i });
    }

    for (auto c : cnt) {
        sorted_cnt.push_back({ c.second, c.first });
    }

    sort(sorted_cnt.begin(), sorted_cnt.end(), greater<pair<int, string>>());

    for (auto sc : sorted_cnt) {
        string genre = sc.second;
        sort(mp[genre].begin(), mp[genre].end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first) return a.first > b.first;
            else {
                return a.second < b.second;
            }
            });
        if (mp[genre].size() >= 2) {
            answer.push_back(mp[genre][0].second);
            answer.push_back(mp[genre][1].second);
        }
        else {
            answer.push_back(mp[genre][0].second);
        }
    }

    return answer;
}