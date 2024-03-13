#include <iostream>
using namespace std;

int D[1005][35][3];
int sec, shifts;
int drops[1005];

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> sec >> shifts;
  for(int i = 1; i <= sec; i++)
  {
    cin >> drops[i];
  }

  for(int i = 1; i <= sec; i++)
  {
    if(drops[i] == 1)
    {
      D[i][0][1] = D[i - 1][0][1] + 1;
    }
    else
    {
      D[i][0][1] = D[i - 1][0][1];
    }
    
    for(int j = 1; j <= shifts; j++)
    {
      if(i < j)
      {
        break;
      }

      if(drops[i] == 1)
      {
        D[i][j][1] = max(D[i - 1][j - 1][2], D[i - 1][j][1]) + 1;
        D[i][j][2] = max(D[i - 1][j][2], D[i - 1][j - 1][1]);
      }
      else
      {
        D[i][j][1] = max(D[i - 1][j][1], D[i - 1][j - 1][2]);
        D[i][j][2] = max(D[i - 1][j - 1][1], D[i - 1][j][2]) + 1;
      }
    }
  }

  int max_plums = 0;
  for(int j = 0; j <= shifts; j++)
  {
    max_plums = max(max_plums, max(D[sec][j][1], D[sec][j][2]));
  }

  cout << max_plums;
}


/*
풀었던 DP 문제 중에 가장 어려웠던 문제.
D[i][j][k] = i번째 시간에 j번 움직여서 k번째 나무에 사람이 서있을 때 먹는 자두의 최댓값.
이렇게 잡고, k를 기준으로, 하나 전 값에서 max를 사용해 찾으면 쉽게 찾아지는 문제

다만 계속 의문이 드는 건 어차피 나무는 두 그루이기 때문에 k값은 상관이 없는 것 아닌가?
어차피 실제로는 i가 홀수/짝수인가에 따라 서있는 나무는 무조건적으로 정해지기에. 굳이 갈 수 없는 경우의 수를 세야 하는지 모르겠다. 

필요 없을 것 같긴한데 코드가 복잡해질 것 같아서 그냥 지금 구현법이 더 나은것 같기도..
*/
