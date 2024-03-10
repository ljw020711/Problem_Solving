#include <iostream>
using namespace std;

int work_day;
int D[20], t[20], p[20];
//D[i] = i일에 들고 있는 돈의 최대치

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> work_day;
  for(int i = 1; i <= work_day; i++)
  {
    cin >> t[i] >> p[i];
  }

  for(int i = 1; i <= work_day; i++)
  {
    D[i] = max(D[i - 1], D[i]);

    if(t[i] + i - 1 <= work_day)
    {
      D[t[i] + i] = max(D[t[i] + i], D[i] + p[i]);
    }

    /*
    for(int e = 1; e <= work_day + 1; e++)
    {
      cout << D[e] << ' ';
    }
    cout << '\n';
    */
  }

  cout << max(D[work_day], D[work_day + 1]);
}

/*
  어려웠던 문제.
  Bottom-up 풀이의 핵심은 D[i]를 i일에 들고 있는 돈의 최대치를 계산하는 것.
  일을 한 날이 아니라, 일이 끝난 다음날에 돈을 추가해야함

  추가로, 이전 날에 한 일의 보상보다, 중간에 시작하는 일의 보상이 더 큰 경우에(같은 날에 일이 끝나면) 다음날의 돈의 최대치가 바뀌여야 하므로,
  해당 일의 기존 값과, 이후의 잡혀있는 일의 보상 중 큰 값을 넣어야 한다. 
  추가로, 만약 이전에 끝나는 일을 하는 것이 더 큰 돈을 주는 경우, 일을 하지 않을 경우를 고려해, 이전값과 현재 값중 큰 값을 가지게 한다.
*/
