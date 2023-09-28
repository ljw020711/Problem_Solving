#include <iostream>
#include <string>
using namespace std;

char ans[6561][6561];


void paint_white(int x, int y, int n)
{
  for(int r = 0; r < n; r++)
  {
    for(int c = 0; c < n; c++)
    {
      ans[x + r][y + c] = ' ';
    }
  }
}


void star(int x, int y, int n)
{
  if(n == 1)
  {
    ans[x][y] = '*';
    return;
  }
  else
  {
    int next = n / 3;

    for(int r = 0; r < 3; r++)
    {
      for(int c = 0; c < 3; c++)
      {
        if(r == 1 && c == 1)
        {
          paint_white(x + r * next, y + c * next, next);
        }
        else
        {
          star(x + r * next, y + c * next, next);
        }
      }
    }
  }
  return;
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  star(0, 0, num);

  for(int r = 0; r < num; r++)
  {
    for(int c = 0; c < num; c++)
    {
      cout << ans[r][c];
    }
    cout << '\n';
  }
}
