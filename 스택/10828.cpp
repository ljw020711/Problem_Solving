#include <iostream>
#include <string>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int stack[10005] = {0,};
  int pos = 0;

  int num;
  cin >> num;
  
  string cmd;
  for(int i = 0; i < num; i++)
  {
    cin >> cmd;

    if(cmd == "push")
    {
      int x;
      cin >> x;

      stack[pos] = x;
      pos++;
    }
    else if(cmd == "pop")
    {
      if(pos == 0)
      {
        cout << -1 << '\n';
      }
      else
      {
        pos--;
        cout << stack[pos] << "\n";
      }
    }
    else if(cmd == "size")
    {
      cout << pos << "\n";
    }
    else if(cmd == "empty")
    {
      if(pos == 0)
      {
        cout << 1 << '\n';
      }
      else
      {
        cout << 0 << '\n';
      }
    }
    else if(cmd == "top")
    {
      if(pos == 0)
      {
        cout << -1 << '\n';
      }
      else
      {
        cout << stack[pos - 1] << "\n";
      }
    }
  }
}
