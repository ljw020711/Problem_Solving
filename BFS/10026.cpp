#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int N;
  cin >> N;

  char canvas[N][N];
  int visit[N][N];
  memset(visit, 0, sizeof(visit));
  for(int r = 0; r < N; r++)
  {
    string pic_line;
    cin >> pic_line;

    for(int c = 0; c < N; c++)
    {
      canvas[r][c] = pic_line[c];
    }
  }
  
  queue<pair<int, int>> Q;
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  int count = 0;
  for(int r = 0; r < N; r++)
  {
    for(int c = 0; c < N; c++)
    {
      if(visit[r][c] == 0)
      {
        Q.push({r, c});
        visit[r][c] = 1;
        count++;
        
        while(!Q.empty())
        {
          pair<int, int> cur = Q.front();
          Q.pop();
          
          for(int i = 0; i < 4; i++)
          {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
              if(canvas[nx][ny] == canvas[cur.first][cur.second] && visit[nx][ny] == 0)
              {
                Q.push({nx, ny});
                visit[nx][ny] = 1;
              }
            }
          }
        }
      }
    }
  }

  cout << count << ' ';

  for(int r = 0; r < N; r++)
  {
    for(int c = 0; c < N; c++)
    {
      if(canvas[r][c] == 'G')
      {
        canvas[r][c] = 'R';
      }
      visit[r][c] = 0;
    }
  }
  
  count = 0;
  for(int r = 0; r < N; r++)
  {
    for(int c = 0; c < N; c++)
    {
      if(visit[r][c] == 0)
      {
        Q.push({r, c});
        visit[r][c] = 1;
        count++;
        
        while(!Q.empty())
        {
          pair<int, int> cur = Q.front();
          Q.pop();

          for(int i = 0; i < 4; i++)
          {
            int nx = cur.first + dx[i];
            int ny = cur.second +dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
              if(canvas[nx][ny] == canvas[cur.first][cur.second] && visit[nx][ny] == 0)
              {
                Q.push({nx, ny});
                visit[nx][ny] = 1;
              }
            }
          }
        }
      }
    }
  }

  cout << count;
}
