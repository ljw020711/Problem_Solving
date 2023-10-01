#include <iostream>
using namespace std;

int seq[20];
int seq_n, sum;
int ans;

void func(int n, int cur)
{
  if(n == seq_n)
  {
    if(cur == sum)
    {
      ans++;
    }
    
    return;
  }

  func(n + 1, cur);
  func(n + 1, cur + seq[n]);
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cur = 0;
  cin >> seq_n >> sum;

  for(int i = 0; i < seq_n; i++)
  {
    cin >> seq[i];
  }

  func(0, cur);

  if(sum == 0)
  {
    ans -= 1;
  }
  cout << ans;
}
