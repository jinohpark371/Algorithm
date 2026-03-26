#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s;//idx 저장 스택

    for (int i = 0; i < n; i++) {
        //가격이 떨어졌을떄 현재 stack의 top idx와 현재 i의
        //차가 idx번쨰 요소가 가격이 떨어지지 않는 시간
        while (!s.empty() && prices[s.top()] > prices[i]) {
            int idx = s.top(); s.pop();
            answer[idx] = i - idx;
        }
        //다음주식과 비교를 위해 항상 현재 i는 push
        s.push(i);
    }

    //스택 은 비내림차순을 유지하므로 
    //각 스택에 있는 idx와 
    //prices의 마지막 idx n-1의 차가 주식가격이 떨어지지 않는 시간
    while (!s.empty()) {
        int idx = s.top(); s.pop();
        answer[idx] = n - 1 - idx;
    }

    return answer;
}