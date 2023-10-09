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
  
  int before[len];
  memset(before, 0, sizeof(before));

  int present[len];
  do
  {
    for(int i = 0; i < len; i++)
    {
      present[i] = list[i];
    }
    
    if(!check(present, before, len))
    {
      for(int j = 0; j < len; j++)
      {
        cout << present[j] << ' ';
      }
      
      cout << '\n';
    }

    for(int k = 0; k < len; k++)
    {
      before[k] = present[k];
    }
    
  }while(next_permutation(list, list + num));
}
