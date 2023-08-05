#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int line[100001];
int visit[100001];

int dx[] = {1, -1};

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int subin, sister;
  cin >> subin >> sister;

  queue<int> Q;
  Q.push(subin);
  visit[subin] = 1;

  while(!Q.empty())
  {
    int cur = Q.front();
    Q.pop();

    for(int i = 0; i < 2; i++)
    {
      int nx = cur + dx[i];

      if(nx >= 0 && nx <= 100000)
      {
        if(visit[nx] == 0 || visit[nx] > visit[cur])
        {
          visit[nx] = visit[cur] + 1;
          Q.push(nx);
        }
      }  
    }

    int nx = 2 * cur;

    if(nx >= 0 && nx <= 100000)
    {
      if(visit[nx] == 0 || visit[nx] > visit[cur])
      {
        visit[nx] = visit[cur];
        Q.push(nx);
      }
    }  
  }

  cout << visit[sister] - 1;
}
