#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int mountain[303][303];
int visit[303][303];
int water[303][303];

int row, col, year;


int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 ,-1};


int split()
{
  int amount = 0;
  
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      if(mountain[r][c] != 0 && visit[r][c] == 0)
      {
        amount++;
        //cout << mountain[r][c];
        queue<pair<int, int>> Q;
        Q.push({r, c});
        visit[r][c]++;

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
              if(mountain[nx][ny] != 0 && visit[nx][ny] == 0)
              {
                visit[nx][ny] = 1;
                Q.push({nx, ny});
              }
            }
          }
        }
      }
    }
  }
 
  return amount;
}

int melt()
{
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      if(mountain[r][c] != 0 && visit[r][c] == 0)
      {
        for(int i = 0; i < 4; i++)
        {
          int nx = r + dx[i];
          int ny = c + dy[i];

          if(nx >= 0 && nx < row && ny >= 0 && ny < col)
          {
            if(mountain[nx][ny] == 0)
            {
              water[r][c]++;
            }
          }
        }
      }
    }
  }

  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      mountain[r][c] -= water[r][c];
      
      if(mountain[r][c] < 0)
      {
        mountain[r][c] = 0;
      }
    }
  }
  
  return 0;
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> row >> col;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> mountain[r][c];
    }
  }

  int sp = 0;
  int n = 0;
  while(1)  
  {
    year++;   //년도 증가
    memset(visit, 0, sizeof(visit));
    memset(water, 0, sizeof(visit));
    melt();  //빙산 녹기
    sp = split();

    if(sp == 0)  //덩어리 개수 확인
    {
      cout << 0;
      return 0;
    }
    else if(sp >= 2)
    {
      cout << year;
      return 0; 
    }
    n++;
  }
}
