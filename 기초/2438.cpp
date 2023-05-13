#include <iostream>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  
  int num;
  cin >> num;
  
  for(int i = 0; i < num; i++)
  {
    for(int j = 0; j <= i; j ++)
    {
      cout << '*';
    }
    cout << '\n';
  }
}
