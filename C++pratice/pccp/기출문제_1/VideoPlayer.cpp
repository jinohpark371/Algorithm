#include <string>
#include <vector>

using namespace std;

int toSecond(string str) {
    string m = str.substr(0, 2);
    string s = str.substr(3, 2);

    int num = stoi(m) * 60;
    num += stoi(s);

    return num;
}

string to_MMSS(int sec) {
    int m = sec / 60;
    int s = sec % 60;

    string min = to_string(m);
    string ssec = to_string(s);

    if (min.length() == 1) {
        min = '0' + min;
    }

    if (ssec.length() == 1) {
        ssec = '0' + ssec;
    }

    return min + ':' + ssec;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    int video_length = toSecond(video_len);
    int position = toSecond(pos);
    int start = toSecond(op_start);
    int end = toSecond(op_end);


    for (auto command : commands) {
        if (start <= position && position <= end) {
            position = end;
        }

        if (command == "prev") {
            position = max(0, position - 10);
        }
        else if (command == "next") {
            position = min(video_length, position + 10);
        }
    }

    //마지막 명령어 수행 후 오프닝 체크
    if (start <= position && position <= end) {
        position = end;
    }
    return to_MMSS(position);
}