#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int row, col;
  cin >> row >> col;

  char maze[row][col];
  int visit[row][col];
  memset(visit, 0, sizeof(visit));
  queue<pair<int, int>> exits;

  queue<pair<int, int>> fire;
  pair<int, int> jihoon;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> maze[r][c];
      
      if(maze[r][c] == 'F')
      {
        fire.push({r, c});
      }
      else if(maze[r][c] == 'J')
      {
        jihoon = {r, c};
      }
      
      if((maze[r][c] == '.' || maze[r][c] == 'J') && (r == 0 || r == row -1 || c == 0 || c == col - 1))
      {
        exits.push({r, c});
      }
    }
  }
  
  queue<pair<int, int>> QF;
  while(!fire.empty())
  {
    QF.push(fire.front());
    visit[fire.front().first][fire.front().second] = 1;
    fire.pop();
  }
  
  QF.push(jihoon);;
  visit[jihoon.first][jihoon.second] = 2;
  long long time_f[row][col];
  memset(time_f, 0, sizeof(time_f));
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  while(!QF.empty())
  {
    pair<int, int> cur = QF.front();
    QF.pop();

    if(visit[cur.first][cur.second] == 1)
    {
      for(int i = 0; i < 4; i++)
      {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];

        if(nx >= 0 && nx < row && ny >= 0 && ny < col)
        {
          if((maze[nx][ny] == '.' || maze[nx][ny] == 'J') && visit[nx][ny] == 0)
          {
            visit[nx][ny] = 1;
            QF.push({nx, ny});
          }
        }
      }
    }

    else if(visit[cur.first][cur.second] == 2)
    {
      for(int j = 0; j < 4; j++)
      {
        int nx = cur.first + dx[j];
        int ny = cur.second + dy[j];

        if(nx >= 0 && nx < row && ny >= 0 && ny < col)
        {
          if(maze[nx][ny] == '.' && visit[nx][ny] == 0)
          {
            visit[nx][ny] = 2;
            QF.push({nx, ny});
            time_f[nx][ny] = time_f[cur.first][cur.second] + 1;
          }
        }
      }
    }
  }
  
  long long fastest = 1001;
  while(!exits.empty())
  {
    pair<int, int> ex = exits.front();
    if(visit[ex.first][ex.second] == 2 && fastest > time_f[ex.first][ex.second])
    {
      fastest = time_f[ex.first][ex.second] + 1;
    }
    exits.pop();
  }

  if(fastest == 1001)
  {
    cout << "IMPOSSIBLE";
  }
  else
  {
    cout << fastest;
  }
}
