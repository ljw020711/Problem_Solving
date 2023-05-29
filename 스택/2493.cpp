#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int num;
  cin >> num;

  stack<int> s;
  stack<int> index;
  s.push(100000001);
  index.push(0);

  for(int i = 1; i <= num; i++)
  {
    int tower;
    cin >> tower;
    
    while(s.top() < tower)
    {
      s.pop();
      index.pop();
    }
    
    s.push(tower);
    cout << index.top() << ' ';
    index.push(i);
  }
}
