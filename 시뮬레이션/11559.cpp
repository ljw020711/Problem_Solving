#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char field[12][6];
int visit[12][6];

queue<pair<int, int>> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<pair<int, int>> puyos;
int poped;
int find_adjacent()
{
  int count = 0;
  
  while(!q.empty())
  {
    pair<int, int> curr = q.front();
    q.pop();
    count++;
    
    int x = curr.first;
    int y = curr.second;
    int color = field[x][y];
    puyos.push_back({x, y});

    for(int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx >= 0 && nx < 12 && ny >= 0 && ny < 6)
      {
        if(field[nx][ny] == color && visit[nx][ny] == 0)
        {
          q.push({nx, ny});
          visit[nx][ny] = 1;
        }
      }
    }
  }

  return count;
}

void pop()
{
  for(int i = 0; i < puyos.size(); i++)
  {
    int x = puyos[i].first;
    int y = puyos[i].second;

    field[x][y] = '.';
  }
}

void push_down()
{
  for(int x = 10; x >= 0; x--)
  {
    for(int y = 0; y < 6; y++)
    {
      int tmp_x = x;
      while(tmp_x <= 10 && field[tmp_x][y] != '.' && field[tmp_x + 1][y] == '.')
      {
        char tmp = field[tmp_x][y];
        field[tmp_x][y] = field[tmp_x + 1][y];
        field[tmp_x + 1][y] = tmp;

        tmp_x++;
      }
    }
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  //input
  for(int x = 0; x < 12; x++)
  {
    for(int y = 0; y < 6; y++)
    {
      cin >> field[x][y];
    }
  }

  //solve
  int combo = 0;
  do
  {
    poped = 0;
    for(int x = 11; x >= 0; x--)
    {
      for(int y = 0; y < 6; y++)
      {
        if(visit[x][y] == 0 && field[x][y] != '.')
        {
          q.push({x, y});
          visit[x][y] = 1;

          if(find_adjacent() >= 4)
          {
            pop();
            poped = 1;
          }

          puyos.erase(puyos.begin(), puyos.end());
        }
      }
    }
    
    if(poped)
    {
      push_down();
      combo++;
    }

    memset(visit, 0, sizeof(visit));
  }while(poped);

  cout << combo;
}
