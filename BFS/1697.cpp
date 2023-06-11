#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define mx 100001

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  
  int map[mx];
  memset(map, 0, sizeof(map));
  int subin, sister;
  cin >> subin >> sister;

  queue<int> Q;
  int visit[mx];
  memset(visit, 0, sizeof(visit));
  Q.push(subin);
  visit[subin] = 1;

  int dx[] = {1, -1};
  while(!Q.empty())
  {
    int cur = Q.front();
    Q.pop();

    for(int i = 0; i < 2; i++)
    {
      int nx = cur + dx[i];
      int nx2 = 2 * cur;

      if(nx >= 0 && nx < mx)
      {
        if(visit[nx] == 0 || visit[nx] > visit[cur] + 1)
        {
          Q.push(nx);
          visit[nx] = visit[cur] + 1;
        }
      }

      if(nx2 >= 0 && nx2 < mx)
      {
        if(visit[nx2] == 0 || visit[nx2] > visit[cur] + 1)
        {
          Q.push(nx2);
          visit[nx2] = visit[cur] + 1;
        }
      }
    }
  }

  cout << visit[sister] - 1;
}
