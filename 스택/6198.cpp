#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0);  cin.tie(0);

  int N;
  cin >> N;

  int towers[N];
  memset(towers, 0, sizeof(towers));
  for(int i = 0; i < N; i++)
  {
    cin >> towers[i];
  }

  stack<int> s;
  stack<int> index;
  s.push(1000000001);
  index.push(N + 1);
  
  long long num = 0;
  long sum = 0;
  
  for(int j = N; j >= 1; j--)
  {
    while(s.top() < towers[j - 1])
    {
      s.pop();
      index.pop();
    }
    num = index.top() - j - 1;
    sum += num;
    
    s.push(towers[j - 1]);
    index.push(j);
  }
  
  cout << sum;
}
