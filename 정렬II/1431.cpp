#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num;
string serial[52];

bool cmp(const string &a, const string &b)
{
  if(a.length() != b.length())
  {
    return a.length() < b.length();
  }

  int a_sum = 0;
  int b_sum = 0;
  for(char e : a)
  {
    if(e >= 'A' && e <= 'Z')
    {
      continue;
    }

    a_sum += e - '0';
  }

  for(char f : b)
  {
    if(f >= 'A' && f <= 'Z')
    {
      continue;
    }

    b_sum += f - '0';
  }

  if(a_sum != b_sum)
  {
    return a_sum < b_sum;
  }

  for(int i = 0; i < a.length(); i++)
  {
    if(a[i] == b[i])
    {
      continue;
    }

    return a[i] < b[i];
  }

  return 0;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  for(int i = 0; i < num; i++)
  {
    cin >> serial[i];
  }

  sort(serial, serial + num, cmp);

  for(int i = 0; i < num; i++)
  {
    cout << serial[i] << '\n';
  }
}
