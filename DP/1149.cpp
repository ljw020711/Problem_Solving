#include <iostream>
using namespace std;

int houses;
int cost[1002][3];
int D[1002][3];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> houses;
  for(int i = 0; i < houses; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      cin >> cost[i][j];
    }
  }

  D[0][0] = cost[0][0];
  D[0][1] = cost[0][1];
  D[0][2] = cost[0][2];
  for(int i = 1; i < houses; i++)
  {
    D[i][0] = min(D[i - 1][1], D[i - 1][2]) + cost[i][0];
    D[i][1] = min(D[i - 1][0], D[i - 1][2]) + cost[i][1];
    D[i][2] = min(D[i - 1][0], D[i - 1][1]) + cost[i][2];
  }
  
  cout << min(min(D[houses - 1][0], D[houses - 1][1]), D[houses - 1][2]);
}

/*
계단 문제랑 비슷하게 접근하며 되는 문제. 다만 나는 그걸 못해서 강의를 봤지만.
색상 3개에 대한 2차원 배열을 만들어서
각 k번째가 R, G, B 중 한 색상일 때, min(k - 1, 나머지 색상 둘)해서 더 작은 값에 현재 값을 추가하면 되는 문제.
*/
