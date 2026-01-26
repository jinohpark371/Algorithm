#include <string>
#include <vector>

using namespace std;


vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;

    for (auto query : queries) {
        int n = query[0];
        int p = query[1];

        //맨 아래 자식에서 부모 방향으로 인덱스 번호 경로 저장
        vector<int> path;
        for (int i = 0; i < n - 1; i++) {
            //현재 부모 기준 인덱스 번호로 경로 저장
            path.push_back((p - 1) % 4);
            //부모 번호 결정
            p = (p - 1) / 4 + 1;
        }

        //최상위 부모부터 자식 방향으로 경로 탐색
        string cur = "Rr"; 3
            for (int i = path.size() - 1; i >= 0; i--) {
                //자식이 RR 이거나 rr이면 아래 모든 자식은 해당 값
                if (cur == "RR" || cur == "rr") break;

                int idx = path[i];
                if (idx == 0) cur = "RR";
                else if (idx == 3) cur = "rr";
                else cur = "Rr";

            }

        answer.push_back(cur);
    }
    return answer;
}