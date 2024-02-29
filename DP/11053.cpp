#include <iostream>
using namespace std;

int len;
int array[1005];
int D[1005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> len;
  for(int i = 1; i <= len; i++)
  {
    cin >> array[i];
  }

  int max_len = 1;
  D[1] = 1;
  for(int i = 2; i <= len; i++)
  {
    int j = i - 1;

    D[i] = 1;
    while(j > 0)
    {
      if(array[i] > array[j])
      {
        D[i] = max(D[i], D[j] + 1);
      }
      
      j--;
    }

    if(D[i] > max_len)
    {
      max_len = D[i];
    }
  }

  cout << max_len;
}

/*
안어려웠는데 비슷한 풀이를 보고나서야 쉽게 풀린 문제.
복습이 필요함.

저번 문제랑 비슷하게 바로 전 수를 처리하는 부분에서 틀림
*/
