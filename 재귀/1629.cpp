#include <iostream>
using namespace std;

int abmodc(long long a, long long b, long long c)
{
  if(b == 1)
  {
    return a % c;
  }
  else
  {
    long long tmp = abmodc(a, b / 2, c);
    long long ans = tmp * tmp % c;

    if(b % 2 != 0)
    {
      ans = ans * (a % c) % c; 
    }

    return ans;
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long val, a, b, c;
  cin >> a >> b >> c;

  cout << abmodc(a, b, c);
}#include <iostream>
using namespace std;

int abmodc(long long a, long long b, long long c)
{
  if(b == 1)
  {
    return a % c;
  }
  else
  {
    long long tmp = abmodc(a, b / 2, c);
    long long ans = tmp * tmp % c;

    if(b % 2 != 0)
    {
      ans = ans * (a % c) % c; 
    }

    return ans;
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long val, a, b, c;
  cin >> a >> b >> c;

  cout << abmodc(a, b, c);
}
