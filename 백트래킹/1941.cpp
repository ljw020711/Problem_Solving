#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

string students[5];
int visit[5][5];
int members[5][5];

int num;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1 ,0};

void bfs(queue<pair<int, int>> Q)
{  
  int dasom = 0;
  int adjacent = 0;
  
  while(!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    adjacent++;
    if(students[cur.first][cur.second] == 'S')
    {
      dasom++;
    }

    for(int i = 0; i < 4; i++)
    {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
      {
        if(visit[nx][ny] == 0 && members[nx][ny] == 1)
        {
          Q.push({nx, ny});
          visit[nx][ny] = 1;
        }
      }
    }
  }

  if(adjacent == 7 && dasom >= 4)
  {
    num++;
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; i++)
  {
    cin >> students[i];
  }

  int seats[25];
  memset(seats, 0, sizeof(seats));
  for(int j = 7; j < 25; j++)
  {
    seats[j] = 1;
  }
  
  do
  {
    queue<pair<int, int>> Q;

    memset(visit, 0, sizeof(visit));
    memset(members, 0, sizeof(members));

    for(int k = 0; k < 25; k++)
    {
      if(seats[k] == 0)
      {
        members[k / 5][k % 5] = 1;

        if(Q.empty())
        {
          Q.push({k / 5, k % 5});
          visit[k / 5][k % 5] = 1;
        }
      }
    }
    
    bfs(Q);
    
  }while(next_permutation(seats, seats + 25));

  cout << num;
}
