#include <iostream>
#include <vector>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
string shape = "^v<>";
string cmdChar = "UDLR";

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    int H, W;
    cin >> H >> W;
    vector<string> board(H);

    int r, c;
    for (int i = 0; i < H; i++)
    {
      string s;
      cin >> s;
      size_t pos = s.find_first_of("^v<>");
      if (pos != string::npos)
      {
        r = i;
        c = pos;
      }
      board[i] = s;
    }

    int N;
    cin >> N;
    string commands;
    cin >> commands;

    for (char cmd : commands)
    {
      if (cmd == 'S')
      { // 현재방향
        int d = shape.find(board[r][c]);

        int nr = r + dr[d];
        int nc = c + dc[d];
        while (nr >= 0 && nr < H && nc >= 0 && nc < W)
        {
          if (board[nr][nc] == '#')
            break;
          else if (board[nr][nc] == '*')
          {
            board[nr][nc] = '.';
            break;
          }
          nr += dr[d];
          nc += dc[d];
        }
      }
      else
      {
        int d = cmdChar.find(cmd);
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr >= 0 && nr < H && nc >= 0 && nc < W && board[nr][nc] == '.')
        {
          board[r][c] = '.';
          r = nr;
          c = nc;
        }
        board[r][c] = shape[d];
      }
    }

    cout << '#' << i + 1 << ' ';
    for (auto &row : board)
      cout << row << '\n';
  }
}