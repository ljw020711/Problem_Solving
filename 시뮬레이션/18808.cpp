#include <iostream>
#include <cstring>
using namespace std;

int row, col;
int stickers;
int laptop[42][42];

int stik_row, stik_col;
int stik[10][10];

int curr_stik = 0;
int attachable(int x, int y)
{
  for(int r = 0; r < stik_row; r++)
  {
    for(int c = 0; c < stik_col; c++)
    {
      if(stik[r][c] == 1 && laptop[x + r][y + c] != 0)
      {
        return 0;  //FALSE
      }
    }
  }

  return 1; //TURE
}

int attach()
{
  //check whether sticker can be placed or not
  for(int x = 0; x < row - stik_row + 1; x++)
  {
    for(int y = 0; y < col - stik_col + 1; y++)
    {
      if(attachable(x, y))
      {
        //stick
        for(int r = 0; r < stik_row; r++)
        {
          for(int c = 0; c < stik_col; c++)
          {
            if(stik[r][c] == 1)
            {
              laptop[x + r][y + c] = stik[r][c] + curr_stik;
            }
          }
        }

        return 1;
      }
    }
  }

  return 0;
}

void rotate()
{
  int temp[10][10];
  for(int r = 0; r < stik_row; r++)
  {
    for(int c = 0; c < stik_col; c++)
    {
      temp[c][stik_row - 1 - r] = stik[r][c];
    }
  }

  int tmp = stik_row;
  stik_row = stik_col;
  stik_col = tmp;

  memset(stik, 0, sizeof(stik));
  for(int r = 0; r < stik_row; r++)
  {
    for(int c = 0; c < stik_col; c++)
    {
      stik[r][c] = temp[r][c];
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> row >> col >> stickers;
  for(int i = 0; i < stickers; i++)
  {
    cin >> stik_row >> stik_col;
    curr_stik = i;
    
    //input sticker
    for(int sr = 0; sr < stik_row; sr++)
    {
      for(int sc = 0; sc < stik_col; sc++)
      {
        cin >> stik[sr][sc];
      }
    }

    for(int dir = 0; dir < 4; dir++)
    {
      if(attach())
      {
        break;
      }
      
      rotate();
    }
  }

  int count = 0;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      if(laptop[r][c] != 0)
      {
        count++;
      }
    }
  }
  cout << count << '\n';  
}
