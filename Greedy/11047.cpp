#include <iostream>
using namespace std;

int num_coins, target_money;
int coins[12];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num_coins >> target_money;

  for(int i = 0; i < num_coins; i++)
  {
    cin >> coins[i];
  }

  int idx = num_coins - 1;
  int total_num = 0;
  while(target_money > 0)
  {
    while(coins[idx] > target_money)
    {
      idx--;
    }

    target_money -= coins[idx];
    total_num++;
  }
  
  cout << total_num;
}
