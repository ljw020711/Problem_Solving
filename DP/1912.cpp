#include <iostream>
#include <climits>
using namespace std;

int N;
int arr[100005];
int d[100005];
int main() 
{
  cin >> N;
  for(int i = 1; i <= N; i++)
  {
    cin >> arr[i];
  }

  int max = d[1] = arr[1];
  for(int i = 2; i <= N; i++)
  {
    d[i] = d[i - 1] + arr[i];
    
    if(d[i - 1] < 0)
    {
      d[i] = arr[i];
    }

    if(d[i] > max)
    {
      max = d[i];
    }
  }

  cout << max;
}

/*
조금만 더 생각했으면 풀 수 있었을 것 같은 문제
하지만 막상 계속 풀었으면 생각 못해냈을 것 같은 문제
점화식을 생각하려 하지말고, 천천히 해당 값들을 적어나가 봤으면 규칙이 쉽게 보인다.

D[i] = i번째 원소를 포함하는 연속합 중 최댓값
이렇게 두고 보면, D[i]는 이전 연속합이 양수이면 다음값을 그냥 더하기만 하면되고 (왜냐면 현재 원소는 무조건 들어가야 하기 때문)
이전 연속합이 음수라면, 새로운 연속합을 만들어 나가면 된다. 

이렇게 보니 테이블을 잡는 것이 좀 어려워 보인다.
DP 연습이 많이 필요해 보임
*/
