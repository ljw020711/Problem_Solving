#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool check(int present[], int before[], int len)
{
  for(int i = 0; i < len; i++)
  {
    if(present[i] != before[i])
    {
      return 0;
    }
  }

  return 1;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num, len;
  cin >> num >> len;

  int list[num];
  memset(list, 0, sizeof(list));

  for(int i = len; i < num; i++)
  {
    list[i] = 1;
  }
 
  do
  {
    for(int i = 0; i < num; i++)
    {
      if(list[i] == 0)
      {
        cout << i + 1 << ' ';
      }
    }
    cout << '\n';
    
  }while(next_permutation(list, list + num));
}
