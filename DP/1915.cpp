#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int board[1005][1005];
int D[1005][1005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  string num;
  for(int i = 0; i < n; i++)
  {
    cin >> num;
    
    for(int j = 0; j < m; j++)
    {
      board[i][j] = num[j] - '0';
    }
  }

  int max_size = 0;
  //initial value
  for(int i = 0; i < n; i++)
  {
    if(board[i][0])
    {
      D[i][0] = 1;

      max_size = max(max_size, D[i][0]);
    }
  }
  
  for(int j = 0; j < m; j++)
  {
    if(board[0][j])
    {
      D[0][j] = 1;

      max_size = max(max_size, D[0][j]);
    }
  }

  //DP
  for(int i = 1; i < n; i++)
  {
    for(int j = 1; j < m; j++)
    {
      if(board[i][j])
      {
        D[i][j] = 1;
        
        if(D[i - 1][j] && D[i][j - 1] && D[i - 1][j - 1])
        {
          D[i][j] = min({D[i - 1][j - 1], D[i - 1][j], D[i][j - 1]}) + 1;
        }

        max_size = max(max_size, D[i][j]);
      }
    }
  }

  
  cout << max_size * max_size;
}

/*
DP는 구현을 잘했음.
1 1  1 2  2 1  2 2
1 2, 1 1, 1 1, 2 3
인 규칙을 잘 따라가면 됨.
다만 입력값을 string으로 받아야 한다는 것을 깜박함.
+ string을 숫자로 바꾸고 싶으면 - '0'을 하면됨
*/
