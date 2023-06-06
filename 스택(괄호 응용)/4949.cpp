#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  
  string sntns;
  int error = 0;
  while(1)
  {
    getline(cin, sntns);
    if(sntns == ".")
    {
      break;
    }
    
    error = 0;
    stack<char> brackets;
    
    int i = 0;
    while(sntns[i] != '.')
    {
      if(sntns[i] == '(' || sntns[i] == '[')
      {
        brackets.push(sntns[i]);
      }
      else if(sntns[i] == ')' || sntns[i] == ']')
      {
        if(brackets.empty() || ((sntns[i] == ')') && (brackets.top() != '(')) || ((sntns[i] == ']') && (brackets.top() != '[')))
        {
          cout << "no" << '\n';
          error = 1;
          break;
        }
        else
        {
          brackets.pop();
        }
      }
      i++;
    }
    if(!error)
    {
      if(brackets.empty())
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
}
