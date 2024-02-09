#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int num;
long cards[100001];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  for(int i = 0; i < num; i++)
  {
    cin >> cards[i];
  }
  sort(cards, cards + num);

  int count = 0;
  int max_count = 0;
  long min_value = LONG_MIN;

  for(int i = 0; i < num; i++)
  {
    if(count == 0 || cards[i - 1] == cards[i])
    {
      count++;
    }

    else
    {
      if(max_count < count)
      {
        max_count = count;
        min_value = cards[i - 1];
        
      }

      count = 1;
    }
  }

  if(count > max_count)
  {
    min_value = cards[num - 1];
  }
  cout << min_value;
}

/*
접근법 생각이 좀 까다로웠나..?
사실 많이 쉬운 편에 속하는 문제.

정렬을 하면 같은 숫자끼리 순회하면서 count하면 되는 문제.
다만 제일 큰 숫자가 제일 많다면 루프 내에서는 바뀌지 않음.
따라서 출력 직전에 한 번 더 확인해야함!
*/
