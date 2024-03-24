#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr_len;
int arr[1005];

int D[1005];
int pre[1005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> arr_len;
  for(int i = 1; i <= arr_len; i++)
  {
    cin >> arr[i];
  }

  int max_len = 1;
  int max_idx = 1;
  D[1] = 1;
  pre[1] = 0;
  for(int i = 2; i <= arr_len; i++)
  {
    for(int j = i - 1; j >= 1; j--)
    {
      if(arr[j] >= arr[i])
      {
        continue;
      }

      if(D[j] > D[i])
      {
        D[i] = D[j];
        pre[i] = j;
      }
    }

    D[i] += 1;

    if(D[i] > max_len)
    {
      max_len = D[i];
      max_idx = i;
    }
  }

  cout << max_len << '\n';

  int ans[max_len];
  for(int i = 0; i < max_len; i++)
  {
    ans[i] = arr[max_idx];
    max_idx = pre[max_idx];
  }

  for(int i = max_len - 1; i >= 0; i--)
  {
    cout << ans[i] << ' ';
  }
}

/*
증가하는 수열을 좀 풀어봐서 어렵지 않았던 문제.
이전에 풀었던 스킬을 재사용만 했으면 빠르게 풀었을듯.

이전 스킬을 까먹어서 오래 걸렸다. 복습을 잘해야할듯.
주요 스킬은
(1) 현재 수보다 작은 수일때의 DP에서 +1, 이때 앞에 있는 모든 경우를 다 해봐야 함. 직전이 꼭 가장 큰 경우라는 보장이 없기 때문
(2) 가장 큰 경우를 출력하는 것은 Pre라는 배열을 생성하여, 직전의 값의 인덱스만 저장. 차후 계속 역참조하여 출력.
*/
