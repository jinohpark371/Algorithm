#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    vector<int> menu_time;//주문별 걸리는 시간
    int ssum = 0;//주문 처리에 걸리는 총 시간

    for (int i = 0; i < order.size(); i++) {
        menu_time.push_back(menu[order[i]]);
        ssum += menu[order[i]];
    }

    int idx = 0;//현재 주문
    int people = 0; //주문 웨이팅 시간
    int prevOutTime = 0;//과거 주문이 처리된 시간
    int mmax = 0;//최대인원
    //주문 총 처리시간 타임라인안에서 웨이팅하는 최대 인원 세기
    for (int i = 0; i <= ssum; i++) {

        //k초 마다 인원 증가
        if (i % k == 0 && i / k < order.size()) {
            people++;
            if (k * idx > prevOutTime) prevOutTime = i;
        }

        //현재 주문이 완료된 시간에 완료 인원 뺴주기
        if (prevOutTime + menu_time[idx] == i) {
            people--;
            idx++;//다음 주문
            prevOutTime = i; //마지막 주문 완료된 시간 갱신
        }

        mmax = max(mmax, people);
    }

    return mmax;
}