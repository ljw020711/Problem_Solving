#include <iostream>
#include <stack>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int N;
  cin >> N;

  int inputs[N];
  for(int i = N - 1; i >= 0; i--)
  {
    cin >> inputs[i];
  }

  int ans[N];
  
  stack<int> s;
  s.push(0);
  for(int j = 1; j <= N; j++)
  {
    while(!s.empty() && s.top() <= inputs[j - 1])
    {
      s.pop();
    }
    if(s.empty())
    {
      ans[N - j] = -1;
    }
    else
    {
      ans[N - j] = s.top();
    }
    s.push(inputs[j - 1]);
  }

  for(int k = 0; k < N; k++)
  {
    cout << ans[k] << ' ';
  }
}
