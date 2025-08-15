#include <iostream>
using namespace std;

/*
모든 재귀가 동일한 실행 단계를 가짐
재귀 호출 hanoi(n, from, to, via)는 언제나 같은 3단계 구조
1️ n-1개를 보조 타워로 이동
2️ 남은 1개(가장 큰 원판)를 목적지 타워로 이동
3️ 보조 타워에 있던 n-1개를 목적지 타워로 이동
*/
void hanoi(int n,int from, int to, int via) {
    if (n == 1) {
        cout << from << " " << to << '\n';
        return;
    }
    hanoi(n - 1, from, via, to);
    //항상 맨 아래를 제외한 나머지 원판들은 보조타워로 이동
    cout << from << " " << to << '\n';
    //맨 아래에 있는 원판은 목적지로 이동
    hanoi(n - 1, via, to, from);
    //보조타워에 있는 원판들을 원래 목적지로 이동
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n"; // 이동 횟수: 2^n - 1
    hanoi(n, 1, 3, 2); // 1번 → 3번 기둥으로 옮김, 2번은 보조
    return 0;
}
