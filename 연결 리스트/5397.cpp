#include <iostream>
#include <list>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  
  int tc_num;
  cin >> tc_num;
  
  for(int i = 0; i < tc_num; i++)
  {
    string input;
    cin >> input;
    list<char> L;
    list<char>::iterator cursor = L.end();

    for(int j = 0; j < input.length(); j++)
    {
      if(input[j] == '<')
      {
        if(cursor != L.begin())
        {
          cursor--;
        }
      }
      else if(input[j] == '>')
      {
        if(cursor != L.end())
        {
          cursor++;
        }
      }
      else if(input[j] == '-')
      {
        if(cursor != L.begin())
        {
          cursor--;
          cursor = L.erase(cursor);
        }
      }
      else
      {
        L.insert(cursor, input[j]);
      }
    }
    
    for(list<char>::iterator t = L.begin(); t != L.end(); t++)
    {
      cout << *t;
    }
    cout << '\n';
  }
}
