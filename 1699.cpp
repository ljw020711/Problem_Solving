#include <iostream>
using namespace std;

int num;
int D[100005];
int main() 
{
  cin >> num;

  D[0] = 0;
  D[1] = 1;

  int sq = 1;
  for(int i = 1; i <= num; i++)
  {
    sq = 1;
    D[i] = D[i - (sq * sq)] + 1;
    
    while(sq * sq <= i)
    {
      D[i] = min(D[i], D[i - (sq * sq)] + 1);

      sq++;
    }
  }

  cout << D[num];
}


/*
  기본적으로 아래 꼴을 따르지만, 
  D[i] = D[i - sq^2] + 1;

  꼭 i와 가까운 제곱 수로 구성되었을 때 최소가 되지는 않음.
  따라서 i >= sq^2인 모든 sq에 대해서 min값을 저장. 
*/
