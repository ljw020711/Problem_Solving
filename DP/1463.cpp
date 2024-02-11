#include <iostream>
using namespace std;

int num;
int all_cases[1000001];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  all_cases[1] = 0;

  for(int i = 2; i <= num; i++)
  {
    all_cases[i] = all_cases[i - 1] + 1;
    
    if(i % 3  == 0)
    {
      all_cases[i] = min(all_cases[i], all_cases[i / 3] + 1);
    }
    if(i % 2 == 0)
    {
      all_cases[i] = min(all_cases[i], all_cases[i / 2] + 1);
    }
  }

  cout << all_cases[num];
}

/*
기억해야할 스킬 :
1) i - 1을 미리 넣어두고, 새로운 값들에 대해서 차례대로 min을 해주면 된다.
*/
