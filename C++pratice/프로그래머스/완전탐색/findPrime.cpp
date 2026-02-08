#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
int count;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


void DFS(string& numbers, unordered_set<int>& st, vector<bool>& used, string& cur) {

    //만든 숫자 집합에 포함시키며 중복확인 및 소수 갯수 카운트
    if (!cur.empty()) {
        int num = stoi(cur);
        if (isPrime(num) && st.insert(num).second) {
            count++;
        }
    }

    //숫자크기를 다 채움
    if (cur.size() == numbers.size()) {
        return;
    }


    for (int i = 0; i < numbers.size(); i++) {
        if (used[i]) continue;

        //숫자 붙이기
        cur.push_back(numbers[i]);
        used[i] = true;//방문처리
        //탐색진행
        DFS(numbers, st, used, cur);

        //갓다온 숫자 미방문처리
        cur.pop_back();
        used[i] = false;
    }

}


int solution(string numbers) {
    unordered_set<int> st;
    vector<bool> used(numbers.size(), false);
    string cur;
    count = 0;


    DFS(numbers, st, used, cur);


    return count;
}