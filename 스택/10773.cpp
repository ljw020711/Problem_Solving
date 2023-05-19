#include <iostream>
#include <stack>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  stack<int> S;
  int num_cyc;
  cin >> num_cyc;

  int num;
  for(int i = 0; i < num_cyc; i++)
  {
    cin >> num;
    if(num == 0 && (S.empty() != 1))
    {
      S.pop();
    }
    else
    {
      S.push(num);
    }
  }

  int init_size = S.size();
  int sum = 0;
  for(int j = 0; j < init_size; j++)
  {
    sum += S.top();
    S.pop();
  }
  cout << sum;
}
