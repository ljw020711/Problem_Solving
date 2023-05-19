#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  stack<int> S;
  
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

      S.push(x);
    }
    else if(cmd == "pop")
    {
      if(S.empty())
      {
        cout << -1 << '\n';
      }
      else
      {
        cout << S.top() << "\n";
        S.pop();
      }
    }
    else if(cmd == "size")
    {
      cout << S.size() << "\n";
    }
    else if(cmd == "empty")
    {
      cout << S.empty() << "\n";
    }
    else if(cmd == "top")
    {
      if(S.empty())
      {
        cout << -1 << '\n';
      }
      else
      {
        cout << S.top() << "\n";
      }
    }
  }
}
