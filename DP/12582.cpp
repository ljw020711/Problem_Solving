#include <iostream>
#include <vector>
using namespace std;

int N;
int D[1000005];
int progress[1000005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  D[1] = 0;
  progress[1] = 0;
  
  for(int i = 2; i <= N; i++)
  {
    D[i] = D[i - 1] + 1;
    progress[i] = i - 1;

    if(i % 2 == 0)
    {
      if(D[i/2] + 1 < D[i])
      {
        D[i] = D[i/2] + 1;
        progress[i] = i / 2;
      }
    }

    if(i % 3 == 0)
    {
      if(D[i/3] + 1 < D[i])
      {
        D[i] = D[i/3] + 1;
        progress[i] = i / 3;
      }
    }
  }

  cout << D[N] << '\n';
  
  int j = N;

  while(j > 0)
  {
    cout << j << ' ';

    j = progress[j];  
  }
}

/*
그냥 풀리는 줄 알고 대충 풀었다가 흠칫했던 문제...

배열을 하나 더 만들거나, 이차원 배열로 만들어서, 바로 전 단계의 숫자를 기억하고 있으면 쉽게 풀리는 문제!
그래도 쉽게 
*/
