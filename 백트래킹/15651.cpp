#include <iostream>
using namespace std;

int num, len;
int seq[7];
int available[8];

void func(int n)
{
  if(n == len)
  {
    for(int i = 0; i < len; i++)
    {
      cout << seq[i] << ' ';
    }

    cout << '\n';
    return;
  }

  for(int j = 1; j <= num; j++)
  {
    seq[n] = j;
    func(n + 1);
  }
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num >> len;

  func(0);
}
