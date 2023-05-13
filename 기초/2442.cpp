#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int num;
  cin >> num;

  for(int i = 0; i < num; i++)
  {
    for(int lspc = num; lspc > i; lspc--)
    {
      cout << ' ';
    }
    for(int lstr = 0; lstr <= i; lstr++)
    {
      cout << '*';
    }
    for(int rstr = 1; rstr <= i; rstr++)
    {
      cout << '*';
    }
    cout << '\n';
  }
}
