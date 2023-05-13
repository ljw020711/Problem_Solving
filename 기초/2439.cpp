#include <iostream>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  int num; 
  cin >> num;
  
  for(int i = 1; i <= num; i++)
  {
    for(int j = num - i; j > 0; j--)
    {
      cout << ' ';
    }
    
    for(int k = 0; k < i; k++)
    {
      cout << '*';
    }
    cout << '\n';
  }
}
