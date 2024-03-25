#include <iostream>
#include <algorithm>
using namespace std;

int glasses;
int D[10005][3];
int wine[10005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> glasses;
  for(int i = 1; i <= glasses; i++)
  {
    cin >> wine[i];
  }

  D[1][1] = wine[1];

  D[2][0] = max({D[1][0], D[1][1], D[1][2]});
  D[2][1] = wine[2];
  D[2][2] = wine[1] + wine[2];
  
  for(int i = 3; i <= glasses; i++)
  {
    D[i][0] = max({D[i - 1][0], D[i - 1][1], D[i - 1][2]});
    D[i][1] = max({D[i - 2][1], D[i - 2][2], D[i - 1][0]}) + wine[i];
    D[i][2] = D[i - 1][1] + wine[i];
  }

  int max_wine = -1;
  for(int i = 1; i <= glasses; i++)
  {
    for(int j = 0; j <= 2; j++)
    {
      max_wine = max(max_wine, D[i][j]);
    }
  }

  cout << max_wine;
}

/*
연속에 제한이 있는 문제는 가능한 연속을 이차원배열로 설정해주면 쉽게 풀리는 듯하다.
이번 문제도 
0: 해당 순서의 와인을 안먹는 경우, 
1: 해당 순서의 와인을 연속하지 않고 먹는 경우, 
2: 연속해서 현재 와인을 먹는 경우.
이렇게 세 케이스로 나누어 매 케이스를 차례대로 넣어주면 되는 문제.
*/
