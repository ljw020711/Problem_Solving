#include <iostream>
#include <stack>
using namespace std;

int main() 
{
  string pipes;
  cin >> pipes;

  stack<int> piece;
  int total = 0;
  char pre_entry;
  for(int i = 0; i < pipes.length(); i++)
  { 
    if(pipes[i] == '(')
    {
      piece.push('(');
    }
    else
    {
      if(pre_entry == '(')
      {
        piece.pop();
        total += piece.size();
      }
      else
      {
        total++;
        piece.pop();
      }
    }

    pre_entry = pipes[i];
  }

  cout << total;
}
