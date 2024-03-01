#include <iostream>
#include <algorithm>
using namespace std;

int num;
int stik[2][100005];
int D[2][100005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  while(num--)
  {
    int stickers;
    cin >> stickers;

    for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j < stickers; j++)
      {
        cin >> stik[i][j];
      }
    }

    int next[2] = {0, 1};
    D[0][0] = stik[next[0]][0];
    D[1][0] = stik[next[1]][0];

    swap(next[0], next[1]);
    D[0][1] = D[1][0] + stik[0][1];
    D[1][1] = D[0][0] + stik[1][1];

    for(int j = 2; j < stickers; j++)
    {
      D[0][j] = max(D[1][j - 1], D[1][j - 2]) + stik[0][j];
      D[1][j] = max(D[0][j - 1], D[0][j - 2]) + stik[1][j];
    }
    
    cout << max(D[0][stickers - 1], D[1][stickers - 1]) << '\n';
  }
}

/*
실버1이었지만, 좀 많이 어려웠던 문제...

점화식 자체는 얼추 찾았지만, 정확하게 찾지는 못했던 문제.
그리고 dp를 진행할 때, 굳이 지그재그인 값을 저장하려고 하지 않아도 됐었음.
오히려 지그재그 움직이는 것을 그대로 구현하면, 값 찾기가 훨씬 수월했던 문제.
*/
