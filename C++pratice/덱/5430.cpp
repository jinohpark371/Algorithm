#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string funcs, arrStr;
        int n;
        cin >> funcs >> n >> arrStr;

        deque<int> dq;
        string num = "";

        for (char ch : arrStr) {
            if (isdigit(ch)) {
                num += ch;
            }
            else if (!num.empty()) {
                dq.push_back(stoi(num));
                num = "";
            }
        }

        bool isReversed = false;
        bool error = false;

        for (char f : funcs) {
            if (f == 'R') {
                isReversed = !isReversed;
            }
            else if (f == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                //�������� �ʾҴٸ� �� �� ��� ����
                if (!isReversed) dq.pop_front();
                //���������ٸ� �� �� ��� ����
                else dq.pop_back();
            }
        }

        if (error) {
            cout << "error\n";
        }
        else {
            cout << "[";
            if (!dq.empty()) {
                if (!isReversed) {
                    cout << dq.front(); dq.pop_front();
                    while (!dq.empty()) {
                        cout << "," << dq.front(); dq.pop_front();
                    }
                }
                else {
                    cout << dq.back(); dq.pop_back();
                    while (!dq.empty()) {
                        cout << "," << dq.back(); dq.pop_back();
                    }
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
