#include <iostream>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  int tc_num; 
  int a, b;
  cin >> tc_num;
  
  for(int i = 0; i < tc_num; i++)
  {
    cin >> a >> b;
    cout << a + b << '\n';
  }
}
