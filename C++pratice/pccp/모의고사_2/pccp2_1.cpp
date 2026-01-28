#include <string>
#include <vector>

using namespace std;

//시계방향
int dx[] = { 0, 1, 0, -1 }; //상 우 하 좌
int dy[] = { 1, 0, -1, 0 };
vector<int> solution(string command) {
    vector<int> answer;

    int x = 0, y = 0; //초기좌표
    int dir = 0; //초기방향
    for (char c : command) {
        if (c == 'R') dir = (dir + 1) % 4; //오른쪽 방향 회전
        else if (c == 'L') dir = (dir + 3) % 4; //왼쪽 방향 회전
        else if (c == 'G') { //전진
            x += dx[dir];
            y += dy[dir];
        }
        else { //후진
            x -= dx[dir];
            y -= dy[dir];
        }
    }

    answer.push_back(x);
    answer.push_back(y);

    return answer;
}