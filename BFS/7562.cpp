#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int tc_num;
  cin >> tc_num;

  for(int i = 0; i < tc_num; i++)
  {
    int board_len;
    cin >> board_len;
    int visit[board_len][board_len];
    memset(visit, 0, sizeof(visit));
    
    queue<pair<int, int>> knight;
    pair<int, int> curr, target;
    cin >> curr.first >> curr.second >> target.first >> target.second;
    knight.push(curr);
    visit[curr.first][curr.second] = 1;

    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    while(!knight.empty())
    {
      curr = knight.front();
      knight.pop();

      for(int i = 0; i < 8; i++)
      {
        int nx = curr.first + dx[i];
        int ny = curr.second + dy[i];

        if(nx >= 0 && nx < board_len && ny >=0 && ny < board_len)
        {
          if(visit[nx][ny] == 0)
          {
            visit[nx][ny] = visit[curr.first][curr.second] + 1;
            knight.push({nx, ny});
          }
        }
      }
    }

    cout << visit[target.first][target.second] - 1 << '\n';
  }
}
