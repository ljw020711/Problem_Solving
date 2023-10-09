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
  for(int i = 0; i < num; i++)
  {
    cin >> list[i];
  }
  sort(list, list + num);

  int list2[num];
  memset(list2, 0, sizeof(list2));
  for(int i = len; i < num; i++)
  {
    list2[i] = 1;
  }
  
  do
  {
    for(int i = 0; i < num; i++)
    {
      if(list2[i] == 0)
      {
        cout << list[i] << ' ';
      }
    }
    
    cout << '\n';
  }while(next_permutation(list2, list2 + num));
}
