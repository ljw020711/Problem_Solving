#include <iostream>
#include <stack>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  string input;
  cin >> input;

  stack<char> BK;
  int multi = 1;
  int sum = 0;
  int error = 0;
  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] == '(')
    {
      multi *= 2;
      BK.push(input[i]);
    }
    else if(input[i] == '[')
    {
      multi *= 3;
      BK.push(input[i]);
    }
    else if(input[i] == ')')
    {
      if(BK.empty() || BK.top() != '(')
      {
        error = 1;
        break;
      }
      else
      {
        if(input[i-1] != ')' && input[i-1] != ']')
        {
         sum += multi; 
        }
        multi /= 2;
        BK.pop();
      }
    }
    else
    {
      if(BK.empty() || BK.top() != '[')
      {
        error = 1;
        break;
      }
      else
      {
        if(input[i-1] != ']' && input[i-1] != ')')
        {
         sum += multi; 
        }
        multi /= 3;
        BK.pop();
     }
    }
  }
  if(error || !BK.empty())
  {
    cout << 0;
  }
  else
  {
    cout << sum;
  }
}
