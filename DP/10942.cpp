#include <iostream>
using namespace std;

int len;
int nums[2005];

int questions;
int st, ed;

int D[2005][2005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> len;
  for(int i = 1; i <= len; i++)
  {
    cin >> nums[i];
  }

  for(int i = len; i >= 1; i--)
  {
    for(int j = i; j <= len; j++)
    {
      if(i == j)
      {
        D[i][j] = 1;
      }
      else
      {
        if(nums[i] == nums[j] && ((i + 1 > j - 1) || (D[i + 1][j - 1] == 1)))
        {
          D[i][j] = 1;
        }
        else
        {
          D[i][j] = 0;
        }
      }
    }
  }

  cin >> questions;
  while(questions--)
  {
    cin >> st >> ed;

    cout << D[st][ed] << '\n';
  }
}

/*
  힌트 하나 보고 내 힘으로 푼 DP!
  D[i][j] = i ~ j까지가 펠린드롬이면 1 아니면 0을 넣는다.

  if(nums[i] == nums[j] && (i + 1 > j - 1 || D[i + 1][j - 1] == 1))
  {
    D[i][j] = 1;
  }

  을 해주면 풀리는 문제!
  DP를 이차원배열로 생각하는 것이 포인트!
*/
