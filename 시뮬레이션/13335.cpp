#include <iostream>
#include <queue>
using namespace std;

int truck_num, bridge_len, bridge_load;
int bridge[102];
queue<int> truck;

int bridge_empty()
{
  for(int i = 0; i < bridge_len; i++)
  {
    if(bridge[i] != 0)
    {
      return 0;
    }
  }

  return 1;
}

int bridge_sum()
{
  int sum = 0;
  
  for(int i = 0; i < bridge_len; i++)
  {
    sum += bridge[i];
  }

  return sum;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  //Input
  cin >> truck_num >> bridge_len >> bridge_load;
  for(int i = 0; i < truck_num; i++)
  {
    int trk;
    cin >> trk;
    truck.push(trk);
  }
  
  int count = 0;
  while(!bridge_empty() || !truck.empty())
  {
    for(int i = bridge_len - 2; i >= 0; i--)
    {
      bridge[i + 1] = bridge[i];
    }
    bridge[0] = 0;
    
    if(!truck.empty() && bridge_sum() + truck.front() <= bridge_load)
    {
      int curr = truck.front();
      truck.pop();
      bridge[0] = curr;
    }
    
    count++;
  }
  
  cout << count;
}
