#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int row, col;
  cin >> col >> row;

  int box[row][col];
  int visit[row][col];
  memset(visit, 0, sizeof(visit));

  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++) 
    {
      cin >> box[r][c];
    }
  }

  queue<pair<int, int>> Q;
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};

  int max = -1;
  int day[row][col];
  memset(day, 0, sizeof(day));
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    { 
      if(box[r][c] == 1 && visit[r][c] == 0)
      {
        visit[r][c] = 1;
        Q.push({r, c});
      }
    }
  }
      
  while(!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    if(max < day[cur.first][cur.second])
    {
      max = day[cur.first][cur.second];
    }
         
    for(int i = 0; i < 4; i++ )
    {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx >= 0 && nx < row && ny >= 0 && ny < col)
      {
        if(visit[nx][ny] == 0 && box[nx][ny] == 0)
        {
          visit[nx][ny] = 1;
          Q.push({nx, ny});
          day[nx][ny] = day[cur.first][cur.second] + 1; 
        }
      }
    }
  }

  int error = 0;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      if(box[r][c] == 0 && day[r][c] == 0)
      {
        error = 1;
      }
    }
  }
  
  if(error)
  {
    cout << -1;
  }
  else
  {
    cout << max;
  }
}
