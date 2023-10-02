#include <iostream>
using namespace std;

int num, len;
int seq[8];
int available[9];

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

  int start;
  if(n == 0)
  {
    start = 1;
  }
  else
  {
    start = seq[n - 1];
  }
  
  for(int j = start; j <= num; j++)
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
