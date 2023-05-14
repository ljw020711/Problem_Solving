#include <iostream>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  int nums[n];
  for(int i = 0; i < n; i++)
  {
    cin >> nums[i]; 
  }

  int num_find;
  cin >> num_find;

  int result = 0;
  for(int j = 0; j < n; j++)
  {
    if(nums[j] == num_find)
    {
       result++; 
    }
  }
  cout << result;
}
