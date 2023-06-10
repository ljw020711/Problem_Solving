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

  int paper[row][col];
  int visit[row][col];
  memset(visit, 0, sizeof(visit));
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> paper[r][c];
    }
  }
  
  int max = 0;
  int count = 0;
  int dx[] = {1,0,-1,0};
  int dy[] = {0,1,0,-1};
  queue<pair<int, int>> Q;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      int size = 0;
      
      if(paper[r][c] == 1 && visit[r][c] == 0)
      {
        visit[r][c] = 1;
        Q.push({r, c});
        count++;
        
        while(!Q.empty())
        {
          pair<int, int> cur = Q.front();
          Q.pop();
          size++;
          
          for(int i = 0; i < 4; i++)
          {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx >= 0 && nx < row && ny >= 0 && ny < col)
            {
              if(visit[nx][ny] == 0 && paper[nx][ny] == 1)
              {
                visit[nx][ny] = 1;
                Q.push({nx, ny});
              }
            }
          }
        }
      }

      if(size > max)
      {
        max = size;
      }
    }
  }

  cout << count << '\n' << max << '\n';
}
