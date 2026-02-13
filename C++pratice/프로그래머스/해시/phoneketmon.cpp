#include <vector>
#include <set>
#include <algorithm>   
using namespace std;

int solution(vector<int> nums)
{
    set<int> st(nums.begin(), nums.end());
    //현재 종류가 N/2 보다 클시 최대 N/2를 고를 수 있음 
    //현재 종류가 N/2 보다 작을시 최대로 현재 종류 수를 고를 수 있음 
    return min((int)st.size(), (int)nums.size() / 2);
}