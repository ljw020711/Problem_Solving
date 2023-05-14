#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
  int nums[10];
  memset(nums, 0, sizeof(nums));
  int a, b, c;
  
  cin >> a >> b >> c;
  
  int result = a * b * c;

  while(result > 0)
  {
    nums[result % 10]++;
    result /= 10;
  }

  for(int i = 0; i < 10; i++ )
  {
    cout << nums[i] << '\n';
  }
}
