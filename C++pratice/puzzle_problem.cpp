#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> copied_diffs;
vector<int> copied_times;

long long getTime(int level) {
    long long time = 0;
    int time_idx = 0;
    for (auto diff : copied_diffs) {
        if (diff <= level) {
            time += copied_times[time_idx];
        }
        else {
            if (time_idx == 0) {
                time += copied_times[time_idx];
            }
            else {
                int cnt = diff - level;
                long long total = cnt * (copied_times[time_idx] + copied_times[time_idx - 1]) + copied_times[time_idx];
                time += total;
            }
        }
        time_idx++;
    }
    return time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int level = 0;
    copied_diffs = diffs;
    copied_times = times;
    sort(diffs.begin(), diffs.end());

    int left = 1;
    int right = diffs[diffs.size() - 1];
    while (left <= right) {
        int mid = (left + right) / 2;
        //더 낮은 숙련도로 가능한지 확인
        if (getTime(mid) <= limit) {
            level = mid; // 정답 갱신
            //mid보다 낮은 범위로 변경
            right = mid - 1;
        }
        else {
            //mid보다 높은 범위로 변경
            left = mid + 1;
        }
    }
    return level;
}