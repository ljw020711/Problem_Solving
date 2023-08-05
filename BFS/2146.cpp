#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int map[101][101];
int islands[101][101];

int find_islands(int N)
{
  queue<pair<int, int>> island;
  int visit[N][N];
  memset(visit, 0, sizeof(visit));

  int island_num = 1;
  for(int r = 0; r < N; r++)
  {
    for(int c = 0; c < N; c++)
    {
      if(map[r][c] == 1 && visit[r][c] == 0)
      {
        island.push({r, c});
        visit[r][c] = 1;
        islands[r][c] = island_num;

        while(!island.empty())
        {
          pair<int, int> cur = island.front();
          island.pop();

          for(int i = 0; i < 4; i++)
          {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx >= 0 && nx < N && ny >=0 && ny < N)
            {
              if(visit[nx][ny] == 0 && map[nx][ny] == 1)
              {
                visit[nx][ny] = 1;
                island.push({nx, ny});
                islands[nx][ny] = island_num;
              }
            }
          }
        }

        island_num++;
      }
    }
  }

  return 0;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N;
  cin >> N;
  
  for(int r = 0; r < N; r++)
  {
    for(int c = 0; c < N; c++)
    {
      cin >> map[r][c];
    }
  }

  find_islands(N);
  
  queue<pair<int, int>> Q;
  int branch[N][N];
  memset(branch, 0, sizeof(branch));
  
  for(int r = 0; r < N; r++)
  {
    for(int c = 0; c < N; c++)
    {
      if(map[r][c] == 1 && branch[r][c] == 0)
      {
        Q.push({r, c});
        branch[r][c] = -1;
      }
    }
  }

  int r1, r2, c1, c2, nf, bf;
  int least = 10001;
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
        if(map[nx][ny] == 0 && islands[nx][ny] == 0 && branch[nx][ny] == 0)
        {
          islands[nx][ny] = islands[cur.first][cur.second];
          
          if(branch[cur.first][cur.second] < 0)
          {
            branch[nx][ny] = branch[cur.first][cur.second] + 2;
          }
          else
          {
            branch[nx][ny] = branch[cur.first][cur.second] + 1;
          }

          Q.push({nx, ny});
        }
        else if(map[nx][ny] == 0 && islands[nx][ny] != islands[cur.first][cur.second] && branch[nx][ny] > 0)
        {
          int ans = branch[cur.first][cur.second] + branch[nx][ny];
          if(branch[cur.first][cur.second] < 0)
          {
            ans = branch[nx][ny];
          }

          if(ans < least)
          {
            least = ans;
            r1 = nx;
            c1 = ny;
            r2 = cur.first;
            c2 = cur.second;
          }
        }
      }
    }
  }
  
  cout << least;
}
