#include <iostream>
using namespace std;

int side;
int board[20][20];
int board_origin[20][20];

//{0: up, 1: right, 2: down, 3: left}
void move(int dir)
{
  if(dir == 0)
  {
    for(int x = 1; x < side; x++)
    {
      for(int y = 0; y < side; y++)
      {
        int tmp_x = x;

        while(tmp_x >= 1 && board[tmp_x - 1][y] == 0 && board[tmp_x][y] != 0)
        {
          int tmp = board[tmp_x][y];
          board[tmp_x][y] = board[tmp_x - 1][y];
          board[tmp_x - 1][y] = tmp;

          tmp_x--;
        }
      }
    }
    
    for(int x = 1; x < side; x++)
    {
      for(int y = 0; y < side; y++)
      {
        if(board[x][y] == board[x - 1][y])
        {
          board[x - 1][y] += board[x][y];
          board[x][y] = 0;
        }
      }
    }

    for(int x = 1; x < side; x++)
    {
      for(int y = 0; y < side; y++)
      {
        int tmp_x = x;

        while(tmp_x >= 1 && board[tmp_x - 1][y] == 0 && board[tmp_x][y] != 0)
        {
          int tmp = board[tmp_x][y];
          board[tmp_x][y] = board[tmp_x - 1][y];
          board[tmp_x - 1][y] = tmp;

          tmp_x--;
        }
      }
    }
  }
    
  else if(dir == 1)
  {
    for(int y = side - 2; y >= 0; y--)
    {
      for(int x = 0; x < side; x++)
      {
        int tmp_y = y;

        while(tmp_y <= side - 2 && board[x][tmp_y + 1] == 0 && board[x][tmp_y] != 0)
        {
          int tmp = board[x][tmp_y];
          board[x][tmp_y] = board[x][tmp_y + 1];
          board[x][tmp_y + 1] = tmp;

          tmp_y++;
        }
      }
    }
    
    for(int y = side - 2; y >= 0; y--)
    {
      for(int x = 0; x < side; x++)
      {
        if(board[x][y] == board[x][y + 1])
        {
          board[x][y + 1] += board[x][y];
          board[x][y] = 0;
        }
      }
    }

    for(int y = side - 2; y >= 0; y--)
    {
      for(int x = 0; x < side; x++)
      {
        int tmp_y = y;

        while(tmp_y <= side - 2 && board[x][tmp_y + 1] == 0 && board[x][tmp_y] != 0)
        {
          int tmp = board[x][tmp_y];
          board[x][tmp_y] = board[x][tmp_y + 1];
          board[x][tmp_y + 1] = tmp;

          tmp_y++;
        }
      }
    }
  }
  
  else if(dir == 2)
  {
    for(int x = side - 2; x >= 0; x--)
    {
      for(int y = 0; y < side; y++)
      {
        int tmp_x = x;

        while(tmp_x <= side - 2 && board[tmp_x + 1][y] == 0 && board[tmp_x][y] != 0)
        {
          int tmp = board[tmp_x][y];
          board[tmp_x][y] = board[tmp_x + 1][y];
          board[tmp_x + 1][y] = tmp;

          tmp_x++;
        }
      }
    }
    
    for(int x = side - 2; x >= 0; x--)
    {
      for(int y = 0; y < side; y++)
      {
        if(board[x][y] == board[x + 1][y])
        {
          board[x + 1][y] += board[x][y];
          board[x][y] = 0;
        }
      }
    }

    for(int x = side - 2; x >= 0; x--)
    {
      for(int y = 0; y < side; y++)
      {
        int tmp_x = x;

        while(tmp_x <= side - 2 && board[tmp_x + 1][y] == 0 && board[tmp_x][y] != 0)
        {
          int tmp = board[tmp_x][y];
          board[tmp_x][y] = board[tmp_x + 1][y];
          board[tmp_x + 1][y] = tmp;

          tmp_x++;
        }
      }
    }
  }

  else if(dir == 3)
  {
    for(int y = 1; y < side; y++)
    {
      for(int x = 0; x < side; x++)
      {
        int tmp_y = y;

        while(tmp_y >= 1 && board[x][tmp_y - 1] == 0 && board[x][tmp_y] != 0)
        {
          int tmp = board[x][tmp_y];
          board[x][tmp_y] = board[x][tmp_y - 1];
          board[x][tmp_y - 1] = tmp;

          tmp_y--;
        }
      }
    }
    
    for(int y = 1; y < side; y++)
    {
      for(int x = 0; x < side; x++)
      {
        if(board[x][y] == board[x][y - 1])
        {
          board[x][y - 1] += board[x][y];
          board[x][y] = 0;
        }
      }
    }

    for(int y = 1; y < side; y++)
    {
      for(int x = 0; x < side; x++)
      {
        int tmp_y = y;

        while(tmp_y >= 1 && board[x][tmp_y - 1] == 0 && board[x][tmp_y] != 0)
        {
          int tmp = board[x][tmp_y];
          board[x][tmp_y] = board[x][tmp_y - 1];
          board[x][tmp_y - 1] = tmp;

          tmp_y--;
        }
      }
    }
  }
}

int max_num = 0;

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> side;
  for(int x = 0; x < side; x++)
  {
    for(int y = 0; y < side; y++)
    {
      cin >> board[x][y];
    }
  }

  for(int x = 0; x < side; x++)
  {
    for(int y = 0; y < side; y++)
    {
      board_origin[x][y] = board[x][y];
    }
  }
  
  for(int i = 0; i < (1 << (2 * 5)); i++)
  {
    int trial = i;

    for(int x = 0; x < side; x++)
    {
      for(int y = 0; y < side; y++)
      {
        board[x][y] = board_origin[x][y];
      }
    }

    for(int j = 0; j < 5; j++)
    {
      int dir = trial % 5;
      trial /= 5;

      move(dir);

      for(int r = 0; r < side; r++)
      {
        for(int c = 0; c < side; c++)
        {
          if(board[r][c] > max_num)
          {
            max_num = board[r][c];
          }
        }
      }
    }
  }

  cout << max_num;
}
