#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int num, max_num;
vector<pair<int, int>> inputs;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
  return a.second > b.second;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num >> max_num;

  int tmp_num;
  int exist = 0;
  for(int i = 0; i < num; i++)
  {
    cin >> tmp_num;
    
    for(int j = 0; j < inputs.size(); j++)
    {
      if(inputs[j].first == tmp_num)
      {
        inputs[j].second++;
        exist = 1;
      }
    }

    if(!exist)
    {
      inputs.push_back({tmp_num, 1});
    }

    exist = 0;
  }

  stable_sort(inputs.begin(), inputs.end(), cmp);

  for(auto e : inputs)
  {
    while(e.second--)
    {
      cout << e.first << ' ';
    }
  }
}



/*
가장 오래 걸린 실버5 문제가 아닐까 싶다.. 내 수준을 깨닫게 해준 문제. 정렬 문제좀 열심히 풀어봐야겠다

1) 일단 c, c++에서 배열의 최대 크기가 있다는 것을 알게 됨. stack area가 한정 되어있기 때문에 최대 크기가 10^5까지밖에 선언이 되지 않는다.
이것 때문에 counting sort로는 접근이 어려웠던 것!, vector로 구현하면 됐을지도 모르지만... 벡터로 한다면 굳이 모든 숫자에 대해 초기값을 잡을
이유가 없어보임.

2) vector는 생각보다 많이 간편하다... 입력값을 바로바로 수정할 수도 있다.
3) 이건 바로 생각해낸 부분이지만.. cmp함수로 주고받을 때 꼭 주소값으로 넘기는게 메모리 측면에서 유리하다..
*/
