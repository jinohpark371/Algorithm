#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
  vector<int> answer;
  map<string, int> In;
  map<string, int> period;
  map<string, int> price;

  for (auto record : records)
  {
    stringstream ss(record);

    int hour, min;
    string carNumber, inOrOut;
    char c;
    ss >> hour >> c >> min >> carNumber >> inOrOut;
    // 입차시 시간을 분으로 환산 후 기록
    if (inOrOut == "IN")
    {
      In[carNumber] = hour * 60 + min;
    }
    // 출차시 주차장에 머무른 시간 기록
    // 입차 기록 삭제
    else
    {
      period[carNumber] += (hour * 60 + min) - In[carNumber];
      In.erase(carNumber);
    }
  }
  // 입차만 한 차량, (입출하 후 입차)차량 머문시간계산에 포함
  for (auto &[carNumber, time] : In)
  {
    // 입출하 후 입차 차량은 이미 기록에 있으므로 누적계산
    period[carNumber] += (60 * 23 + 59) - In[carNumber];
  }

  // 차량 번호 별 금액 계산
  for (auto &[carNumber, time] : period)
  {
    // 출차한 금액 산정
    if (time > fees[0])
    {
      // 초과시간이 1분이라도 있을때 단위시간 적용을 위해 추차장 머문 시간 +(단위 시간 -1)
      price[carNumber] = fees[1] + (((time - fees[0]) + (fees[2] - 1)) / fees[2]) * fees[3];
    }
    else
    {
      price[carNumber] = fees[1];
    }
  }

  // 차량별(번호 오름차순 정렬) 가격 저장
  for (auto pri : price)
  {
    answer.push_back(pri.second);
  }

  return answer;
}