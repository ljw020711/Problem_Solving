#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int tc_num;
  cin >> tc_num;

  for(int i = 0; i < tc_num; i++)
  {
    int row, col;
    cin >> row >> col;
    int farm[row][col];
    memset(farm, 0, sizeof(farm));
    
    int cabbage;
    cin >> cabbage;

    while(cabbage--)
    {
      int x, y;
      cin >> x >> y;

      farm[x][y] = 1;
    }

    queue<pair<int, int>> Q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int visit[row][col];
    memset(visit, 0, sizeof(visit));

    int count = 0;
    for(int r = 0; r < row; r++)
    {
      for(int c = 0; c < col; c++)
      {
        if(visit[r][c] == 0 && farm[r][c] == 1)
        {
          Q.push({r, c});
          count++;
          
          while(!Q.empty())
          {
            pair<int, int> cur = Q.front();
            Q.pop();

            for(int i = 0; i < 4; i++)
            {
              int nx = cur.first + dx[i];
              int ny = cur.second + dy[i];

              if(nx >= 0 && nx < row && ny >= 0 && ny < col)
              {
                if(farm[nx][ny] == 1 && visit[nx][ny] == 0)
                {
                  Q.push({nx, ny});
                  visit[nx][ny] = 1;
                }
              }
            }
          }
        }
      }
    }

    cout << count << '\n';
  }
}
