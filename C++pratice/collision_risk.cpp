#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    //각 로봇들의 이동경로
    vector<vector<pair<int, int>>> paths(routes.size());
    int paths_idx = 0;
    for (auto route : routes) {
        //시작 포인트
        int start = route[0];
        int st_r = points[start - 1][0];
        int st_c = points[start - 1][1];

        paths[paths_idx].push_back({ st_r, st_c });
        for (int i = 1; i < route.size(); i++) {

            //종료 포인트
            int next = route[i];
            int end_r = points[next - 1][0];
            int end_c = points[next - 1][1];

            //경로 저장            
            while (st_r != end_r || st_c != end_c) {
                if (st_r != end_r) {
                    if (st_r < end_r) {
                        st_r++;
                    }
                    else {
                        st_r--;
                    }
                }
                else if (st_c != end_c) {
                    if (st_c < end_c) {
                        st_c++;
                    }
                    else {
                        st_c--;
                    }
                }
                paths[paths_idx].push_back({ st_r, st_c });
            }
        }
        paths_idx++;
    }

    //최대 시간 계산
    int maxTime = 0;
    for (auto path : paths) {
        maxTime = max(maxTime, (int)path.size());
    }

    for (int t = 0; t < maxTime; t++) {
        //현재 시간에서 각 좌표에 로봇이 들어온 횟수 계산
        int robot_idx = 0;
        map<pair<int, int>, int> count;
        while (robot_idx < paths.size()) {
            if (t < paths[robot_idx].size()) {
                count[paths[robot_idx][t]]++;
            }
            robot_idx++;
        }
        //현재 시간에서 좌표 별 중복 횟수 누적 계산
        for (auto c : count) {
            if (c.second >= 2) answer++;
        }
    }


    return answer;
}