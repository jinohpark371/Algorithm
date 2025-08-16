#include <iostream>
using namespace std;
#define MAX 2187 

int board[MAX][MAX]; 
int cnt[3];

bool isUniform(int x, int y, int size);

//������ ������ ���ϰ����� �˻� �� �ƴϸ� 3����ؼ� 9�� ��� �� ���ϰ��̸� �ش� �� ī��Ʈ+1��.
void count_paper(int x, int y, int size) {


    //���� ũ�⿡�� ��� ���� ���� ������ ���� ���� ����
    if (isUniform(x, y, size)) {
        //-1 -> 0, 0->1, 1->2
        // �� �ε����� �°� ���� ����
        cnt[board[x][y]+1]++;
        return;
    }
    //��� ���� ���� ������ ���Ѵٸ� 
    //3����Ͽ� �ٽ� Ž��
    else {
        int ns = size / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                //���� 3��� �� ��ǥ�� ���� ��ǥ�� 3��� ũ��� �ٽ� Ž��
                count_paper(x + i * ns, y + j * ns, ns);
            }
        }
    }

     
    
}


//�� ��ǥ���� ũ����� �ȿ��� ���ϰ��� �������� �˻�
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