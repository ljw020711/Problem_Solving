#include <iostream>
#include <cstring>
using namespace std;

int total, len;
int ans[8];
int available[9];

void func(int n)
{
  if(n == len)
  {
    for(int j = 0; j < len; j++)
    {
      cout << ans[j] << ' ';
    }

    cout << '\n';
    return;
  }

  int start;
  if(n == 0)
  {
    start = 1;
  }
  else
  {
    start = ans[n - 1];
  }
  
  for(int i = start; i <= total; i++)
  {
    if(available[i] == 0)
    {
      ans[n] = i;
      available[i] = 1;

      func(n + 1);

      available[i] = 0;
    }
  }
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> total >> len;
  func(0);
}
