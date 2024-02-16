#include <iostream>
#include <vector>
using namespace std;

int digit;
long long D[95][2];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> digit;
  D[1][0] = 1;
  D[1][1] = 1;

  for(int i = 2; i <= digit; i++)
  {
    D[i][0] = D[i - 1][0] + D[i - 1][1];
    D[i][1] = D[i - 1][0];
  }

  cout << D[digit][1];
}


/*
방법만 안다면 구현은 쉬운문제
다만 방법을 떠올리는게 매우 어렵다. 

1로 시작하는 값은 그 뒤에 무조건 0으로 시작하는 i - 1자릿수만큼 생긴다. 
0으로 시작하는 값은 그 뒤에 0, 1 모두 와도 된다.
따라서 0으로 시작하는 i자릿수와 1로 시작하는 i 자릿수를 각각 DP로 풀어 해당 자릿수의 1로 시작하는 개수만 출력하면 되는문제

***신기한 점은 이 문제는 피보나치 수열을 띠게 된다.
*/
