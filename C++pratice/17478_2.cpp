#include <iostream>
using namespace std;
int n;

void _var(const char* str, int cnt) { 
    for (int i = 0; i < cnt; i++) cout << "____";
    cout << str;
}

void solve(int cnt) {
    _var("\"����Լ��� ������?\"\n", cnt); 
    if (cnt == n) {
        _var("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", cnt);
    }
    else {
        _var("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", cnt);
        _var("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", cnt);
        _var("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", cnt);

        solve(cnt + 1);
    }
    _var("��� �亯�Ͽ���.\n", cnt);

}

int main() {
    cin >> n;

    solve(0);
}