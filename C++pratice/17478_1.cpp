#include <iostream>  
#include <string>  
using namespace std;  

string first = "\"����Լ��� ������?\""; 
string second = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
string third = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
string four = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"";

string five = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";
string six = "��� �亯�Ͽ���.";

int  str = 4;
void recursion2(int num);


void recursion1(int n, int num) {  
    if (num > n) {
        recursion2(num - 2);
        return;
    }  
    cout << string(num * str, '_') << first << endl;

    if (num <= n - 1){
        cout << string(num * str, '_') << second << endl;
        cout << string(num * str, '_') << third << endl;
        cout << string(num * str, '_') << four << endl;
    }
    else {
        cout << string(num * str, '_') << five << endl;
        cout << string(num * str, '_') << six << endl;
    }
 
    num++;
    recursion1(n, num);
}  

void recursion2( int num) {
    if (num < 0) return;
    
    cout << string(num * str, '_') << six << endl;
    num--;
    recursion2(num);
}

int main() {  
    int n;  
    cin >> n;  
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;  

    recursion1(n,0);  
}