#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int row, col;
  cin >> row >> col;

  char matrix[row][col];
  for(int r = 0; r < row; r++)
  { 
    for(int c = 0; c < col; c++)
    {
      cin >> matrix[r][c];
    }
  }
  
  queue<tuple<int, int, int>> Q;
  int visit[row][col][2];
  memset(visit, 0, sizeof(visit));

  Q.push({0,0,0});
  visit[0][0][0] = 1;
  visit[0][0][1] = 1;
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  while(!Q.empty())
  {
    tuple<int, int, int> curr = Q.front();
    int broken = get<2>(curr);
    Q.pop();

    if(get<0>(curr) == row - 1 && get<1>(curr) == col - 1)
    {
      cout << visit[get<0>(curr)][get<1>(curr)][broken];
      return 0;
    }
 
    for(int i = 0; i < 4; i++)
    {
      int nx = get<0>(curr) + dx[i];
      int ny = get<1>(curr) + dy[i];

      if(nx >= 0 && nx < row && ny >= 0 && ny < col)
      {
        if(visit[nx][ny][broken] == 0 && matrix[nx][ny] == '0')
        {
          visit[nx][ny][broken] = visit[get<0>(curr)][get<1>(curr)][broken] + 1;
          Q.push({nx, ny, broken});
        }

        if(broken == 0 && matrix[nx][ny] == '1' && visit[nx][ny] [broken]== 0)
        {
          visit[nx][ny][1] = visit[get<0>(curr)][get<1>(curr)][broken] + 1;
          Q.push({nx, ny, 1});
        }
      }
    }
  }

  cout << -1;
}
