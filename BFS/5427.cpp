#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc_num;
  cin >> tc_num;

  for(int i = 0; i < tc_num; i++)
  {
    int row, col;
    cin >> col >> row;
    
    queue<pair<int, int>> Q;
    char building[row][col];
    pair<int, int> start, fire;
    int visit[row][col];
    memset(visit, 0, sizeof(visit));
    
    for (int r = 0; r < row; r++) 
    {
      for (int c = 0; c < col; c++)
      {
        cin >> building[r][c];
      
        if(building[r][c] == '*')
        {
          fire.first = r;
          fire.second = c;

          visit[r][c] = -1;
          Q.push(fire);
        }

        else if (building[r][c] == '@') 
        {
          start.first = r;
          start.second = c;

          visit[r][c] = 1;
        }
      }
    }
    Q.push(start);

    int safe = 0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    pair<int, int> time;
    while (!Q.empty())
    {
      pair<int, int> curr = Q.front();
      Q.pop();

      if ((curr.first == 0 || curr.second == 0 || curr.first == row - 1 || curr.second == col - 1) && visit[curr.first][curr.second] != 0 && visit[curr.first][curr.second] != -1) 
      {
        safe = 1;
        time.first = curr.first;
        time.second = curr.second;
        break;
      }

      for (int i = 0; i < 4; i++) 
      {
        int nx = curr.first + dx[i];
        int ny = curr.second + dy[i];

        if (nx >= 0 && nx < row && ny >= 0 && ny < col) 
        {
          if (visit[nx][ny] == 0 && building[nx][ny] == '.') 
          {
            if (visit[curr.first][curr.second] > 0) 
            {
              visit[nx][ny] = visit[curr.first][curr.second] + 1;
            }
            else
            {
              visit[nx][ny] = visit[curr.first][curr.second];
            }
            Q.push({nx, ny});
          }
        }
      }
    }

    if(safe)
    {
      cout << visit[time.first][time.second] << '\n';
    }
    else
    {
      cout << "IMPOSSIBLE\n";
    }
  }
}
