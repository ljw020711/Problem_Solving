#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int room[52][52];
queue<tuple<int, int, int>> vaccum;
int visit[52][52];
int row, col, start_x, start_y, dir;

//North, East, South, West
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> row >> col;
  cin >> start_x >> start_y >> dir;

  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> room[r][c];
    }
  }

  vaccum.push({start_x, start_y, dir});

  while(!vaccum.empty())
  {
    int x, y, d;
    tie(x, y, d) = vaccum.front();
    vaccum.pop();
    if(visit[x][y] == 0)
    {
      visit[x][y] = 1;
    }

    int uncleaned = 0;
    for(int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx >= 0 && nx < row && ny >= 0 && ny < col)
      {
        if(visit[nx][ny] == 0 && room[nx][ny] != 1)
        {
          uncleaned++;
        }
      }
    }

    if(uncleaned == 0)
    {
      int bk_x = x - dx[d];
      int bk_y = y - dy[d];
      if(room[bk_x][bk_y] != 1)
      {
        vaccum.push({bk_x, bk_y, d});
      }
    }
    else
    {
      for(int j = 0; j < 4; j++)
      {
        d = (d + 3) % 4;
        
        int ft_x = x + dx[d];
        int ft_y = y + dy[d];
        
        if(room[ft_x][ft_y] != 1 && visit[ft_x][ft_y] == 0)
        {
          vaccum.push({ft_x, ft_y, d});
          break;
        }
      }
    }
  }

  int cleaned = 0;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      if(visit[r][c] == 1)
      {
        cleaned++;
      }
    }
  }

  cout << cleaned;
}
