#include <iostream>
#include <string>
using namespace std;

const int MAX_K = 10;
const int MAX = 3 * (1 << MAX_K) + 1;
char ans[MAX * 2 - 1][MAX];

void star(int x, int y)
{
  for(int c = 0; c < 3; c++)
  { 
    for(int r = 3 - c - 1; r < 3; r++)
    {
      if(c == 1 && r == 2)
      {
        continue;
      }
      
      ans[x + r][y + c] = '*';
    }

    for(int r = 3; r < c + 3; r++)
    {
      ans[x + r][y + c] = '*';
    }
  }
}


void split(int x, int y, int n)
{
  if(n == 3)
  {
    star(x, y);
    return;
  }
  else
  {
    split(x + n / 2, y, n / 2);          // up
    split(x, y + n / 2, n / 2);          // left
    split(x + n, y + n / 2, n / 2);      //right
  }
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  split(0, 0, num);

  for(int c = 0; c < num; c++)
  {
    for(int r = 0; r < 2 * num - 1; r++)
    {
      if(ans[r][c] == '*')
      {
        cout << '*';
      }
      else
      {
        cout << ' ';
      }
    }

    cout << '\n';
  }
}
