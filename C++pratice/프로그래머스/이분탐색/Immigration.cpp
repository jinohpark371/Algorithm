#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left, right;

    int ssize = times.size() - 1;
    sort(times.begin(), times.end());
    //최소 심사 시간과 최대 심사 시간
    left = 1; right = (long long)times[ssize] * n;

    answer = right;
    while (left <= right) {
        long long mid = (left + right) / 2;

        //mid시간으로 처리가능한 인원수
        long long count = 0;
        for (auto time : times) {
            count += mid / time;
        }

        if (count >= n) {
            //현재 시간으로 n명 처리가능시
            //최솟시간 갱신
            if (mid <= answer) {
                answer = mid;
            }
            //더 적은 범위에서 탐색시작
            right = mid - 1;
        }
        else if (count < n) {
            //더 큰 범위에서 탐색시작
            left = mid + 1;
        }

    }

    return answer;
}