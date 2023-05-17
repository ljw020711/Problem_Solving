#include <iostream>
#include <list>;
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  string input;
  cin >> input;

  list<char> L;
  for(int i = 0; i < input.length(); i++)
  {
    L.push_back(input[i]);
  }

  list<char>::iterator cursor = L.end();
  
  
  int num_commands;
  char command;
  char new_letter;
  cin >> num_commands;
  for(int j = 0; j < num_commands; j++)
  {
    cin >> command;
    if(command == 'L')
    {
      if(cursor != L.begin())
      {
        cursor--;
      }
    }
    else if(command == 'D')
    {
      if(cursor != L.end())
      {
        cursor++;
      }
    }
    else if(command == 'B')
    {
      if(cursor != L.begin())
      {
        cursor--;
        list<char>::iterator target = cursor;
        cursor--;
        L.erase(target);
        cursor++;
      }
    }
    else if(command == 'P')
    {
      cin >> new_letter;
      L.insert(cursor, new_letter);
    }
  }

  for(list<char>::iterator c = L.begin(); c != L.end(); c++)
  {
    cout << *c;
  }
}
