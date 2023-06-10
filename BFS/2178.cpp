#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int row, col;
  cin >> row >> col;

  int maze[row][col];
  int visit[row][col];
  memset(visit, 0, sizeof(visit));
  int distance[row][col];
  memset(distance, 0, sizeof(distance));
  string input;
  
  for(int r = 0; r < row; r++)
  {
    cin >> input;
    for(int c = 0; c < col; c++)
    {
      maze[r][c] = input[c] - '0';
    }
  }

  queue<pair<int, int>> Q;
  Q.push({0, 0});
  visit[0][0] = 1;
  distance[0][0] = 1;

  int count = 0;
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0 ,-1, 0};
  while(!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();
    count = distance[cur.first][cur.second] + 1;
    
    for(int i = 0; i < 4; i++)
    {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx >= 0 && nx < row && ny >= 0 && ny < col)
      {
        if(maze[nx][ny] == 1 && visit[nx][ny] == 0)
        {
          visit[nx][ny] = 1;
          Q.push({nx, ny});

          distance[nx][ny] = count;
        }
      }
    }
  }

  cout << distance[row-1][col-1];
}
