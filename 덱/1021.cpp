#include <iostream>
#include <deque>
using namespace std;

int index(deque<int> tmp_dq, int target)
{
  for(int i = 0; i < tmp_dq.size(); i++)
  {
    if(target == tmp_dq[i])
    {
      return i;
    }
  }

  return -1;
}


int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int size, M;
  cin >> size >> M;

  deque<int> DQ;
  for(int i = 1; i <= size; i++)
  {
    DQ.push_back(i);
  }

  int total = 0;
  for(int j = 0; j < M; j++)
  {
    int num;
    cin >> num;

    int idx = index(DQ, num);
    while(DQ.front() != num)
    {
      if(idx < DQ.size() - idx)
      {
        DQ.push_back(DQ.front());
        DQ.pop_front();
      }
      else
      {
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }

      total++;
    }

    DQ.pop_front();
  }

  cout << total;
}
