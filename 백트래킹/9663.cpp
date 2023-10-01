#include <iostream>
#include <cstring>
using namespace std;

int num, cases;
int board[15][15];
bool avail_col[15];
bool avail_ld[30];
bool avail_rd[30];

void func(int x)
{
  if(x == num)
  {
    cases++;

    return;
  }

  for(int y = 0; y < num; y++)
  {
    if(avail_col[y] == 0 && avail_ld[x + y] == 0 && avail_rd[num - (x - y) - 1] == 0)
    {
      avail_col[y] = 1;
      avail_ld[x + y] = 1;
      avail_rd[num - (x - y) - 1] = 1;
      board[x][y] = 1;
      func(x + 1);

      avail_col[y] = 0;
      avail_ld[x + y] = 0;
      avail_rd[num - (x - y) - 1] = 0;
      board[x][y] = 0;
    }
  }
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  func(0);
  
  cout << cases;
}
