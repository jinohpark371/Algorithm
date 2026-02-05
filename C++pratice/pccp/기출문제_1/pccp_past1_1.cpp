#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int seq = bandage[0]; //시전 시간
    int perSecond = bandage[1]; //초당 회복량
    int extra = bandage[2]; // 추가 체력

    int mmax = health; //최대 체력
    int idx = 0; //공격 인덱스

    int time = attacks.back()[0]; //총 게임 진행 시간

    int t = 0;//연속 성공시간
    for (int i = 1; i <= time; i++) {

        if (idx < attacks.size() && attacks[idx][0] == i) {
            health -= attacks[idx][1]; //해당 시간에 주어진 공격력 만큼 체력 깎기
            idx++; //다음 공격 준비
            t = 0;//연속 성공시간 초기화
            if (health <= 0) return -1;
            continue; //공격을 받은 시간에는 회복하지 못함
        }

        health = min(mmax, health + perSecond); //초당 체력회복
        t++; //성공연속시간증가
        if (t == seq) { //연속 성공시간이 시전시간과 동일시
            health = min(mmax, health + extra); //추가 체력회복
            t = 0;
        }

    }

    return health;

}