#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int num, len;
int numbers[8];
int ans[8];

void func(int n, int available[], int idx)
{
  if(n == len)
  {
    for(int i = 0; i < len; i++)
    {
      cout << ans[i] << ' ';
    }
    cout << '\n';

    return;
  }

  int start = idx;
  if(n != 0)
  {
    start++;
  }
  
  for(int j = start; j < num; j++)
  {
    if(available[j] == 0)
    {
      available[j] = 1;
      ans[n] = numbers[j];
      func(n + 1, available, j);

      available[j] = 0;
    }
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num >> len;
  for(int i = 0; i < num; i++)
  {
    cin >> numbers[i];
  }

  sort(numbers, numbers + num);

  int available[num];
  memset(available, 0, sizeof(available));
  func(0, available, 0);
}
