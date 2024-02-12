#include <iostream>
using namespace std;

int n;
int D[1002];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  D[1] = 1;
  D[2] = 2;

  for(int i = 3; i <= n; i++)
  {
    D[i] = (D[i - 1] + D[i - 2]) % 10007;
  }

  cout << D[n];
}

/*
풀이는 간단하지만 점화식 생각이 죽어도 안난다.
너무 어렵다 수학 공부 좀 열심히 할걸.. 

2 * i짜리의 직사각형을 채운다고 했을 떄, 시작하는 사각형이 세로인지, 가로인지를 정해두고,
남은 사각형을 뒤로 떠넘기면 되는 문제..
*/
