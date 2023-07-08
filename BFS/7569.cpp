#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int boxes[103][103][103];
int visit[103][103][103];

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int row, col, height;
  cin >> col >> row >> height;
  
  queue<tuple<int, int, int>> Q;  
  for(int h = 0; h < height; h++)
  {
    for(int r = 0; r < row; r++)
    {
      for(int c = 0; c < col; c++)
      {
        cin >> boxes[h][r][c];
        
        if(boxes[h][r][c] == 1 && visit[h][r][c] == 0)
        {
          Q.push({h, r, c});
          visit[h][r][c] = 1;
        }
      }
    }
  }

  int dx[] = {0, 1, 0, -1, 0, 0};
  int dy[] = {1, 0, -1, 0, 0, 0};
  int dz[] = {0, 0, 0, 0, 1, -1};

  int ans = -1;
  while(!Q.empty())
  {
    tuple<int, int, int> cur = Q.front();
    Q.pop();
    
    for(int i = 0; i < 6; i++)
    {
      int nx = get<1>(cur) + dx[i];
      int ny = get<2>(cur) + dy[i];
      int nz = get<0>(cur) + dz[i];

      if(nx >= 0 && nx < row && ny >= 0 && ny < col && nz >= 0 && nz < height)
      {
        if(visit[nz][nx][ny] == 0 && boxes[nz][nx][ny] != -1)
        {
          Q.push({nz, nx, ny});
          visit[nz][nx][ny] = visit[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
      }
    }
 }

  for(int h = 0; h < height; h++)
  {
    for(int r = 0; r < row; r++)
    {
      for(int c = 0; c < col; c++)
      {
        
        if(visit[h][r][c] == 0 && boxes[h][r][c] != -1)
        {
          cout << -1;
          return 0;
        }
        
        ans = max(ans, visit[h][r][c]);
      }
    }
  }

  cout << ans - 1;  
}
