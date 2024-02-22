#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1005];
int d[1005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  int max_num = d[1] = a[1];
  for(int i = 2; i <= n; i++)
  { 
    for(int j = 1; j < i; j++)
    {
      if(a[j] >= a[i])
      {
        continue;
      }

      d[i] = max(d[i], d[j]);
    }
    
    d[i] += a[i];

    if(max_num < d[i])
    {
      max_num = d[i];
    }
  }

  cout << max_num;
}

/*
(1) DP라고 꼭 시간 복잡도가 O(n)에 끝날 것이라고 단정 짓지 말 것. 입력이 적어서 O(n^2)도 실행가능했음.
(2) i번째 원소보다 작은 값 중 가장 큰 값에 현재 값을 더해야함. 가장 가까운 원소의 합이 가장 큰 값이 아닐 수도 있음.
