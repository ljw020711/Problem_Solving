#include <iostream>
using namespace std;

int n;
long long numbers[105][15];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  for(int i = 1; i < 10; i++)
  {
    numbers[1][i] = 1;
  }

  for(int i = 1; i < n; i++)
  {
    for(int j = 0; j < 10; j++)
    {     
      if(j == 9)
      {
        numbers[i + 1][j - 1] += numbers[i][j];

        numbers[i + 1][j - 1] %= 1000000000;
      }
      else if(j == 0)
      {
        numbers[i + 1][j + 1] += numbers[i][j];

        numbers[i + 1][j + 1] %= 1000000000;
      }
      else
      {
        numbers[i + 1][j + 1] += numbers[i][j];
        numbers[i + 1][j - 1] += numbers[i][j];

        numbers[i + 1][j + 1] %= 1000000000;
        numbers[i + 1][j - 1] %= 1000000000;
      }

      numbers[i][j]--;
    }
  }

  long long sum = 0;
  for(int i = 0; i < 10; i++)
  {
    sum += numbers[n][i];
    sum %= 1000000000;
  }
  
  cout << sum;
}

/*
  그래도 답 안보고 푼 DP 문제
  포인트는 이전 계단수와 다음 계단수는 마지막 수 +- 1의 관계.

  이렇게 하면 100 * 9의 배열로 풀 수 있다.
  다만 주의할 점은 같은 숫자로 끝나는 계단수가 여러개기에 +- 1 해준 자리에 기존 자릿수만큼 더해줘야 한다.

  Ex) 2자릿수에서 2로 끝나는 계단 수가 2개라면, 그 다음 3자릿수에서 1, 3로 끝나는 계단수는 각각 2개씩 추가되어야한다.
*/
