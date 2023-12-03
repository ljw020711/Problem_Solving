#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int row, col;
int office[10][10];
int office2[10][10];
vector<pair<int, int>> cctv;
vector<pair<int, int>> wall;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int min_blank = 100;
int find_blank()
{
  int blank= 0;

  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      if(office2[r][c] == 0)
      {
        blank++;
      }
    }
  }

  return blank;
}

int find_cases()
{
  //cctv 방향 정하기
  int cases = 1 << (2 * cctv.size());
  
  for(int i = 0; i < cases; i++)
  {
    int curr = i;

    memset(office2, 0, sizeof(office2));
    for(int w = 0; w < wall.size(); w++)
    {
      office2[wall[w].first][wall[w].second] = 1;
    }
    
    for(int d = 0; d < cctv.size(); d++)
    {
      int dir = curr % 4;
      curr /= 4;

      int x = cctv[d].first;
      int y = cctv[d].second;

      //separate cases
      if(office[x][y] == 1)
      {
        int nx = x;
        int ny = y;

        while(office[nx][ny] != 6 && nx >= 0 && nx <= row && ny >= 0 && ny <= col)
        {
          office2[nx][ny] = 1;

          nx += dx[dir];
          ny += dy[dir];
        }
      }
      else if(office[x][y] == 2)
      {
        for(int j = 0; j < 3; j += 2)
        {
          int nx = x;
          int ny = y;
          
          while(office[nx][ny] != 6 && nx >= 0 && nx <= row && ny >= 0 && ny <= col)
          {
            office2[nx][ny] = 1;

            nx += dx[(dir + j) % 4];
            ny += dy[(dir + j) % 4];
          }
        }
      }
      else if(office[x][y] == 3)
      {
        for(int j = 0; j < 2; j++)
        {
          int nx = x;
          int ny = y;

          while(office[nx][ny] != 6 && nx >= 0 && nx <= row && ny >= 0 && ny <= col)
          {
            office2[nx][ny] = 1;

            nx += dx[(dir + j) % 4];
            ny += dy[(dir + j) % 4];
          }
        }
      }
      else if(office[x][y] == 4)
      {
        for(int j = 0; j < 3; j++)
        {
          int nx = x;
          int ny = y;

          while(office[nx][ny] != 6 && nx >= 0 && nx <= row && ny >= 0 && ny <= col)
          {
            office2[nx][ny] = 1;

            nx += dx[(dir + j) % 4];
            ny += dy[(dir + j) % 4];
          }
        }
      }
      else if(office[x][y] == 5)
      {
        for(int j = 0; j < 4; j++)
        {
          int nx = x;
          int ny = y;

          while(office[nx][ny] != 6 && nx >= 0 && nx <= row && ny >= 0 && ny <= col)
          {
            office2[nx][ny] = 1;

            nx += dx[(dir + j) % 4];
            ny += dy[(dir + j) % 4];
          }
        }
      }
    }
    
    int blk = find_blank();
    
    if(min_blank > blk)
    {
      min_blank = blk;
    }
  }

  return min_blank;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  //input 입력
  cin >> row >> col;

  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> office[r][c];

      if(office[r][c] >= 1 && office[r][c] <= 5)
      {
        cctv.push_back({r, c});
      }
      else if(office[r][c] == 6)
      {
        wall.push_back({r, c});
      }
    }
  }
  
  cout << find_cases();
}
