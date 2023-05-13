#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int num;
  cin >> num;

  for(int i = 1; i <= num; i++)
  {
    for(int lspc = num; lspc > i; lspc--)
    {
      cout << ' ';
    }
    for(int lstr = 0; lstr < i; lstr++)
    {
      cout << '*';
    }
    for(int rstr = 1; rstr < i; rstr++)
    {
      cout << '*';
    }
    cout << '\n';
  }

  num -= 1;
  for(int j = 1; j <= num; j++)
  {
    for(int lspc = 0; lspc < j; lspc++)
    {
      cout << ' ';
    }
    for(int lstr = num; lstr >= j; lstr--)
    {
      cout << '*';
    }
    for(int rstr = num; rstr > j; rstr--)
    {
      cout << '*';
    }
    cout << '\n';
  }
}
