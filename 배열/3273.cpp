#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int nums[1000001];
  memset(nums, 0, sizeof(nums));
  
  int num;
  cin >> num;

  int arr[num];
  for(int i = 0; i < num; i++)
  {
    cin >> arr[i];
  }
  
  int x;
  cin >> x;
  
  int rslt = 0;
  for(int j = 0; j < num; j++)
  {
    if(x - arr[j] > 0 && x - arr[j] <= 1000000)
    {
      if((nums[x - arr[j]] == 1))
      {
        rslt++;
      }
      else
      {
        nums[arr[j]]++;
      }
    }
  }
  
  cout << rslt;
}
