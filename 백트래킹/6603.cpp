#include <iostream>
#include <cstring>
using namespace std;

int num;
int numbers[13];
int used[13];
int ans[6];

void func(int n,int idx)
{
  if(n == 6)
  {
    for(int i = 0; i < 6; i++)
    {
      cout << ans[i] << ' ';
    }

    cout << '\n';
    return;
  }

  int start = 0;
  if(n != 0)
  {
    start = idx + 1;
  }
  
  for(int j = start; j < num; j++)
  {
    if(used[j] == 0)
    {
      used[j] = 1;
      ans[n] = numbers[j];
      func(n + 1, j);

      used[j] = 0;
    }
  }
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1)
  {
    cin >> num;

    if(num == 0)
    {
      break;  
    }
    
    for(int i = 0; i < num; i++)
    {
      cin >> numbers[i];
    }

    func(0, 0);
    cout << '\n';
  }
}
