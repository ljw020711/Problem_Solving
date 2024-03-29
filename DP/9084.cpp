#include <iostream>
#include <cstring>
using namespace std;

int t_case;
int coins;
int value[25];
int target_amount;
int D[10005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t_case;
  while(t_case--)
  {
    cin >> coins;
    for(int c = 0; c < coins; c++)
    {
      cin >> value[c];
    }

    cin >> target_amount;
    D[0] = 1;
    for(int c = 0; c < coins; c++)
    {
      for(int i = value[c]; i <= target_amount; i++)
      {
        D[i] += D[i - value[c]];
      }
    }

    cout << D[target_amount] << '\n';
    memset(D, 0, sizeof(D));
  }
}

/*
거의 다 푼 것 같았는데 못풀었던 문제.
D[i-1]에 1씩을 더하는 것이 아니라. 
큰 숫자를 메인으로 더해야 함.
따라서 1은 계속 하나만 더해지고, 거기에 2, 3, 4, 5 등을 더해야함. 
*/
