#include <iostream>
using namespace std;

int work_day;
int D[1500005], t[1500005], p[1500005];
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
    
  }

  cout << max(D[work_day], D[work_day + 1]);
}

/*
퇴사1이랑 똑같은 문제, 그냥 배열 크기만 변경. 크기만 변했는데 왜 난이도가 올라갔지?
그리고 배열 크기가 100만 단위인데 그냥 만들어지는 것도 신기.
*/
