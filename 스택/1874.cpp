#include <iostream>
#include <stack>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  stack<int> S;
  int cnt = 1;

  string ans;
  
  for(int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    
    for(int j = cnt; j <= num; j++)
    {
      S.push(j);
      ans += "+\n";
      cnt = num + 1;
    }
    if(S.top() == num)
    {
      S.pop();
      ans += "-\n";
    }
    else
    {
      ans = "NO";
      break;
    }
  }

  cout << ans;
}
