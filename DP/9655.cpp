#include <iostream>
using namespace std;

int D[2005];
int rocks;
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> rocks;

  D[0] = rocks;
  int i = 0;
  while(D[i] > 0)
  {
    int pick = 1;

    if(D[i] == 3 || D[i] == 1)
    {
      pick = D[i];
    }
    else if(D[i] - 3 == 4)
    {
      pick = 1;
    }

    D[i + 1] = D[i] - pick;
    i++;
  }

  if(i % 2 == 1)
  {
    cout << "SK";
  }
  else
  {
    cout << "CY";
  }
}

/*
1개 / 3개 밖에 못가져가기 때문에. 
4개를 남기는 플레이어가 승리하는 문제.
*/
