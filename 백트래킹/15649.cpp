#include <iostream>
using namespace std;


int num, len;
int sequence[8];
bool available[9];

void func(int n)
{
  if(n == len)
  {
    for(int m = 0; m < len; m++)
    {
      cout << sequence[m] << ' ';
    }

    cout << '\n';
    return;
  }

  for(int i = 1; i <= num; i++)
  {
    if(available[i] == false)
    {
      sequence[n] = i;
      available[i] = true;
      func(n + 1);

      available[i] = false;
    }
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num >> len;
  func(0);
}
