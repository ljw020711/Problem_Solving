#include <iostream>
using namespace std;

int tc, num;
long long D[105];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;

  D[1] = D[2] = D[3] = 1;
  D[4] = D[5] = 2;
  for(int i = 6; i <= 100; i++)
  {
    D[i] = D[i - 5] + D[i - 1];
  }
  
  while(tc--)
  {
    cin >> num;

    cout << D[num] << '\n';
  }
}

/*
  한 변을 구성하는 다른 변들을 천천히 작성해보면 쉽게 규칙이 보이는 문제... 지만 검색해보고 알게됨.
  아직 DP는 잘 못푸는듯함.

  더 쉬운 점화식으로는 D[n] = D[n - 2] + D[n -3]이 있다. 
*/
