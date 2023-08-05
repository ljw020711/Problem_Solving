#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int hx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int hy[] = {2, 1, -2, -1, -2, -1, 2, 1};

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int horse, row, col;
  cin >> horse >> col >> row;

  int map[row][col];
  int visit[row][col][horse + 1];
  memset(visit, 0, sizeof(visit));
  
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> map[r][c];
    }
  }

  queue<tuple<int, int, int>> Q;
  Q.push({0, 0, 0});
  visit[0][0][0] = 1;
  
  while(!Q.empty())
  {
    tuple<int, int, int> cur = Q.front();
    Q.pop();

    if(get<0>(cur) == row - 1 &&  get<1>(cur) == col - 1)
    {
      cout << visit[get<0>(cur)][get<1>(cur)][get<2>(cur)] - 1;
      return 0;
    }

    int h_move = get<2>(cur);
    
    for(int i = 0; i < 4; i++)
    {
      int nx = get<0>(cur) + dx[i];
      int ny = get<1>(cur) + dy[i];

      if(nx >= 0 && nx < row && ny >= 0 && ny < col)
      {
        if(map[nx][ny] == 0 && visit[nx][ny][h_move] == 0)
        {
          visit[nx][ny][h_move] = visit[get<0>(cur)][get<1>(cur)][h_move] + 1;
          Q.push({nx, ny, h_move});
        }
      }
    }
    
    if(h_move < horse)
    { 
      for(int i = 0; i < 8; i++)
      {
        int nx = get<0>(cur) + hx[i];
        int ny = get<1>(cur) + hy[i];

        if(nx >= 0 && nx < row && ny >= 0 && ny < col)
        {
          if(map[nx][ny] == 0 && visit[nx][ny][h_move + 1] == 0)
          {
            visit[nx][ny][h_move + 1] = visit[get<0>(cur)][get<1>(cur)][h_move] + 1;
            Q.push({nx, ny, h_move + 1});
          }
        }
      }
    }
  }

  cout << -1;
}
