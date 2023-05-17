#include <iostream>
#include <list>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int nxt[5001] = {-1,};
  int pre[5001] = {-1,};
  int data[5001] = {-1,};
  
  int num, kill;
  cin >> num >> kill;

  for(int i = 1; i <= num; i++)
  {
    data[i] = i;
    if(i != num) nxt[i] = i + 1;
    else nxt[i] = 1;
    if(i != 1) pre[i] = i - 1;
    else pre[i] = num;
  }

  int cursor = 1;
  cout << '<';
  for(int j = 0; j < num - 1; j++)
  {
    for(int k = 1; k < kill; k++)
    {
      cursor = nxt[cursor];
    }

    cout << data[cursor] << ',' <<' ';
    nxt[pre[cursor]] = nxt[cursor];
    pre[nxt[cursor]] = pre[cursor];
    cursor = nxt[cursor];
  }

  
  cout << data[cursor] << '>';
}
