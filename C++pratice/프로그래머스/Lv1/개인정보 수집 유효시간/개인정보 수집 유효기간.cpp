#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int toDays(int year, int mon, int day) { return year * 12 * 28 + mon * 28 + day; }

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
  vector<int> answer;
  map<string, int> term;
  for (auto t : terms)
  {
    stringstream ss(t);
    string type, time;
    ss >> type >> time;
    term[type] = stoi(time);
  }

  stringstream ss(today);
  string y, m, d;
  getline(ss, y, '.');
  getline(ss, m, '.');
  getline(ss, d, '.');

  int year = stoi(y);
  int mon = stoi(m);
  int day = stoi(d);

  int toDayDays = toDays(year, mon, day);

  for (int i = 0; i < privacies.size(); i++)
  {
    stringstream ss(privacies[i]);
    string from, type;
    ss >> from >> type;

    stringstream ff(from);
    string y, m, d;
    getline(ff, y, '.');
    getline(ff, m, '.');
    getline(ff, d, '.');

    int start_year = stoi(y);
    int start_mon = stoi(m);
    int start_day = stoi(d);

    int expire = toDays(start_year, start_mon, start_day) + term[type] * 28;

    if (expire <= toDayDays)
      answer.push_back(i + 1);
  }

  return answer;
}