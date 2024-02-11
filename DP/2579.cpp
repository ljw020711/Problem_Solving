#include <iostream>
using namespace std;

int stairs;
int points[302];
int D[302][2];

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> stairs;
  for(int i = 1; i <= stairs; i++)
  {
    cin >> points[i];
  }
  
  D[1][0] = D[1][1] = points[1];
  for(int i = 2; i <= stairs; i++)
  {
    D[i][0] = max(D[i - 2][1] + points[i], D[i - 2][0] + points[i]);
    D[i][1] = D[i - 1][0] + points[i];
  }

  cout << max(D[stairs][0], D[stairs][1]);
}

/*
구현은 쉬웠지만, 이미 연속해서 오른 계단인지, 아닌지 판별을 위해 2차원 배열로 잡는 아이디어를 떠올리지 못했다.
이것만 생각해낸다면 쉽게 풀리는 문제.
*/
