#include <iostream>
#include <algorithm>
using namespace std;

int num, max_weight;
pair<int, int> items[105];
int D[100005][105];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num >> max_weight;
  for(int i = 1; i <= num; i++)
  {
    int weight, value;
    cin >> weight >> value;
    
    items[i] = {weight, value};
  }

  for(int k = 1; k <= max_weight; k++)
  {
    for(int j = 1; j <= num; j++)
    {
      D[k][j] = D[k][j - 1];
      
      if(items[j].first <= k)
      {
        D[k][j] = max(D[k][j], D[k - items[j].first][j - 1] + items[j].second);
      }
    }
  }

  cout << D[max_weight][num];
}

/*
  분명 전공시간에 배웠는데 잘 모르겠던 문제.
  무조건 알아야하는 알고리즘 중 하나.

  이번에는 그래도 잘 이해한 것 같으니 꼭 외웠으면 좋겠다.

  포인트는 가방을 채우는 경우를 잘 이해하는 것
  case 1: 가방의 크기가 변하지 않는 상황에서, 새로운 j번째 물건을 가방에 추가하지 않는 경우.
  (기존 것을 빼고 새로운 물건을 넣는것이 손해인 경우)
  case 2: k - wj, j - 1상태인 가방 (k - wj, j - 1 상태에서 최댓값을 가지는 가방)에 현재 j번째 물건을 추가하는 경우.
*/
