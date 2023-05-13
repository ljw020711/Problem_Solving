#include <iostream>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int nums[9];

  for(int i = 0; i < 9; i++)
  {
    cin >> nums[i];
  }

  int max = nums[1];
  int max_idx = 1;

  for(int j = 0; j < 9; j++)
  {
    if(max < nums[j])
    {
      max = nums[j];
      max_idx = j;
    }
  }

  cout << max << '\n' << max_idx + 1;
}
