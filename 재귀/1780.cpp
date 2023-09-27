#include <iostream>
using namespace std;

int paper[2200][2200];
int minus_one = 0;
int zero = 0;
int one = 0;

int check(int x, int y, int n)
{
  int base = paper[x][y];

  for(int r = 0; r < n; r++)
  {
    for(int c = 0; c < n; c++)
    {
      if(base != paper[x + r][y + c])
      {
        return 0;
      }
    }
  }

  return 1;
}

int split(int x, int y, int n)
{
  if(check(x, y, n))
  {
    if(paper[x][y] == -1)
    {
      minus_one++;
    }
    else if(paper[x][y] == 0)
    {
      zero++;
    }
    else if(paper[x][y] == 1)
    {
      one++;
    }

    return 0;
  }

  int next = n / 3;
  for(int r = 0; r < 3; r++)
  {
    for(int c = 0; c < 3; c++)
    {
      split(x + r * next, y + c * next, next);
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
      cin >> paper[r][c];
    }
  }

  split(0, 0, N);

  cout << minus_one << '\n';
  cout << zero << '\n';
  cout << one << '\n';
}
