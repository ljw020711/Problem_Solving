#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int num;
  cin >> num;

  for(int i = 1; i <= num; i++)
  {
    for(int lstr = 0; lstr < i; lstr++)
    {
      cout << '*';
    }
    for(int spc = 2 * num; spc > 2 * i; spc--)
    {
      cout << ' ';
    }
    for(int rstr = 0; rstr < i; rstr++)
    {
      cout << '*';
    }
    cout << '\n';
  }

  num -= 1;
  for(int i = 1; i <= num; i++)
  {
    for(int lstr = num; lstr >= i; lstr--)
    {
      cout << '*';
    }
    for(int spc = 0; spc < 2 * i; spc++)
    {
      cout << ' ';
    }
    for(int rstr = num; rstr >= i; rstr--)
    {
      cout << '*';
    }
    cout << '\n';
  }
}
