#include <iostream>
using namespace std;
#define MAX 2187 

int board[MAX][MAX]; 
int cnt[3];

bool isUniform(int x, int y, int size);

//“현재 구간이 단일값인지 검사 → 아니면 3등분해서 9개 재귀 → 단일값이면 해당 수 카운트+1”.
void count_paper(int x, int y, int size) {


    //현재 크기에서 모두 값은 값을 가지면 단일 갯수 증가
    if (isUniform(x, y, size)) {
        //-1 -> 0, 0->1, 1->2
        // 각 인덱스에 맞개 갯수 증가
        cnt[board[x][y]+1]++;
        return;
    }
    //모두 같은 값을 가지지 못한다면 
    //3등분하여 다시 탐색
    else {
        int ns = size / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                //각각 3등분 한 좌표의 시작 좌표와 3등분 크기로 다시 탐색
                count_paper(x + i * ns, y + j * ns, ns);
            }
        }
    }

     
    
}


//각 좌표에서 크기범위 안에서 단일값을 가지는지 검사
bool isUniform(int x, int y, int size) {
    int v = board[x][y];
    for (int i = x; i < x+size; i++) {
        for (int j = y; j < y+ size; j++) {
            if (v != board[i][j]) {
                return false;
            }
            
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    

    count_paper(0, 0, n);
    for (int i = 0; i < 3;i++) {
        cout << cnt[i] << '\n';
   }

    return 0;
}