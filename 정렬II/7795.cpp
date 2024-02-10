#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cases, a_num, b_num;
int a[20002];
int b[20002];

bool cmp(int a, int b)
{
  return a > b;
}

int main() 
{
  cin >> cases;

  while(cases--)
  {
    //input
    cin >> a_num >> b_num;

    for(int i = 0; i < a_num; i++)
    {
      cin >> a[i]; 
    }
    
    for(int i = 0; i < b_num; i++)
    {
      cin >> b[i]; 
    }

    //sort
    sort(b, b + b_num, cmp);

    //compare
    int sum = 0;
    for(int i = 0; i < a_num; i++)
    { 
      int b_idx = b_num - 1;
      while(b_idx >= 0 && a[i] > b[b_idx])
      {
        b_idx--;
      }

      sum += b_num - b_idx - 1;
    }

    cout << sum << '\n';
  }
}

/*
쉬운 문제

한쪽을 정렬하게 되면, 더 큰 수를 만나는 순간부터는 계산해보지 않아도 되는 문제
1) 한쪽 배열만 정렬하면 됨
2) 내림차순으로 정렬하는 것이 오름차순보다 더 간결한 코드 작성이 가능.
*/
