#include <iostream>
#include <stack>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int inputs;
  cin >> inputs;

  for(int i = 0; i < inputs; i++)
  {
    string ps;
    cin >> ps;

    int error = 0;
    stack<char> brackets;
    for(int j = 0; j < ps.length(); j++)
    {
      if(ps[j] == '(')
      {
        brackets.push(ps[j]);
      }
      else
      {
        if(brackets.empty())
        {
          error = 1;
          break;
        }
        else
        {
          brackets.pop();
        }
      }
    }

    if(error || !brackets.empty())
    {
      cout << "NO\n";
    }
    else
    {
      cout << "YES\n";
    }
  }
}
