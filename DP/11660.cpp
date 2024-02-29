#include <iostream>
using namespace std;

int len, num, curr;
int D[1030][1030];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> len >> num;
  
  for(int i = 0; i < len; i++)
  {
    for(int j = 0; j < len; j++)
    {
      cin >> curr;

      if(i == 0 && j == 0)
      {
        D[i][j] = curr;
      }
      else if(i == 0 && j != 0)
      {
        D[i][j] = D[i][j - 1] + curr;
      }
      else if(i != 0 && j == 0)
      {
        D[i][j] = D[i - 1][j] + curr;
      }
      else
      {
        D[i][j] = D[i - 1][j] + D[i][j - 1] + curr - D[i - 1][j - 1];
      }
    }
  }

  while(num--)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x1 -= 1;
    y1 -= 1;
    x2 -= 1;
    y2 -= 1;
  
    int result = D[x2][y2];
    if(x1 != 0)
    {
      result -= D[x1 - 1][y2];
    }
    if(y1 != 0)
    {
      result -= D[x2][y1 - 1];
    }

    if(x1 != 0 && y1 != 0)
    {
       result += D[x1 - 1][y1 - 1];
    }
    
    cout << result << '\n';

  }
}

/*
  초반에 헷갈렸지만 답을 잘 떠올린 문제.
  포인트는 0,0부터의 합을 다 구한 후, 필요한 구간에 따라 빼기
*/
