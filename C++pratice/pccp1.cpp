#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(vector<vector<int>> players) {
    int n = players.size();
    vector<int> answers;

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({ players[i][1],i });
    }
    // �ð� ���� ���� (������ �� ����)
    //pair�� ���� first �� �������� 
    // �� first�� ���ٸ� second�� �������� ��
    sort(arr.begin(), arr.end());

    /*
   pair�� second�� ���� �ε����� ����� �δ� �� �ٽ��̾���,
   ���� �� rank+1�� �ٽ� actualRank[�����ε���]�� ����ִ� �������
   ��ġ�� �״��, ������ ���ĵ� ����� �ݿ�
   */
    vector<int> actualRank(n);
    for (int rank = 0; rank < n; rank++) {
        int idx = arr[rank].second;
        //���� ��ġ(�ε���)�� ���� ���ĵ� idx����+1(rank+1)�� ������ ����
        actualRank[idx] = rank + 1;
    }

    for (int i = 0; i < n; i++) {
        //��ǥ ������ ���� ���� ���� ũ�ٸ� ���
        if (players[i][0] >= actualRank[i]) answers.push_back(1);
        else answers.push_back(0);
    }

    return answers;
}

int main() {
    vector<vector<int>> players = {
        {3, 12}, {1, 10}, {3, 15}, {3, 14}, {2, 11}
    }; // 1 1 0 0 1

    vector<int> ans = solution(players);
    for (int x : ans) cout << x << " ";
}