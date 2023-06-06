#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int tc_num;
  cin >> tc_num;

  while(tc_num--)
  {
    string op;
    cin >> op;
    
    int arr_size;
    cin >> arr_size;
    
    string array;
    cin >> array;
    
    deque<int> DQ;
    int k = 0;
    int error = 0;

    int input = 0;
    int cur = 0;
    for(int i = 1; i < array.length(); i++)
    {
      if((array[i] == ',' || array[i] == ']') && input)
      {
        DQ.push_back(cur);
        cur = 0;
      }
      else
      {
        input = 1;
        cur = 10 * cur + (array[i] - '0');
      }
    }
    
    int rev = 0;
    for(char c : op)
    {
      if(c == 'R')
      {
        rev = !rev;
      }
      else if(c == 'D')
      {
        if(!DQ.empty())
        {
          if(rev)
          {
            DQ.pop_back();
          }
          else
          {
            DQ.pop_front();
          }
        }
        else
        {
          cout << "error" << '\n';
          error = 1;
          break;
        }
      }
    }

    if(!error)
    {
      if(rev)
      {
        reverse(DQ.begin(), DQ.end());
      }

      cout << '[';
      if(!DQ.empty())
      {
        for(int m = 0; m < DQ.size() - 1; m++)
        {
          cout << DQ[m] << ',';
        }
        cout << DQ.back(); 
      }
      cout << ']' << '\n';
    }
  }
}
