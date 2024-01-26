#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int num;
int numbers[11];
int operators[4];

vector<int> ops;
void operations(int op)
{
  for(int i = 0; i < operators[op]; i++)
  {
    ops.push_back(op);
  }
}

int main() 
{
  cin >> num;
  for(int i = 0; i < num; i++)
  {
    cin >> numbers[i];
  }

  for(int j = 0; j < 4; j++)
  {
    cin >> operators[j];
  }

  for(int op = 0; op < 4; op++)
  {
    operations(op);
  }

  long long max_val = INT_MIN;
  long long min_val = INT_MAX;
  
  do
  {
    long long sum = numbers[0];
    
    for(int i = 0; i < ops.size(); i++)
    {
      int curr_op = ops[i];

      if(curr_op == 0)
      {
        sum += numbers[i + 1];
      }
      else if(curr_op == 1)
      {
        sum -= numbers[i + 1];
      }
      else if(curr_op == 2)
      {
        sum *= numbers[i + 1];
      }
      else
      {
        sum /= numbers[i + 1];
      }
    }
    
    if(sum > max_val)
    {
      max_val = sum;
    }
    if(sum < min_val)
    {
      min_val = sum;
    }
  }while(next_permutation(ops.begin(), ops.end()));

  cout << max_val << '\n' << min_val;
}

/*
  실버1인만큼 많이 쉬웠던 문제.
  최댓값, 최솟값하는 법 꼭 기억하기, <climit> ->  INT_MAX, INT_MIN.
*/
