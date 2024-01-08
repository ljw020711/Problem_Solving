#include <iostream>
using namespace std;

int row, col, curr_x, curr_y, moves;
int map[22][22];
//{North, Top, South, Bottom, West, East}
int dice[6];
int visit[22][22];

/*
0: East
1: West
2: North
3: South
*/
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void horizontal_push(int dir)
{
  int tmp_bottom = dice[3];
  if(dir == 0)  //East
  {
    dice[3] = dice[5]; //East -> Bottom
    dice[5] = dice[1]; //Top -> East
    dice[1] = dice[4]; //West -> Top
    dice[4] = tmp_bottom; //Bottom -> West
  }
  else if(dir == 1)  //West
  {
    dice[3] = dice[4]; //West -> Bottom
    dice[4] = dice[1]; //Top -> West
    dice[1] = dice[5]; //East -> Top
    dice[5] = tmp_bottom; //Bottom -> East
  }
}

void vertical_push(int dir)
{
  int tmp;
  
  if(dir == 2)  //North
    {
      tmp = dice[0];
      for(int i = 1; i <= 3; i++)
      {
        dice[i - 1] = dice[i];
      }
      dice[3] = tmp;
    }
    else if(dir == 3)
    {
      tmp = dice[3];
      for(int i = 2; i >= 0; i--)
      {
        dice[i + 1] = dice[i];
      }
      dice[0] = tmp;
    }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  //Inputs
  cin >> row >> col >> curr_x >> curr_y >> moves;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> map[r][c];
    }
  }

  //Move the dice
  int direction;
  for(int m = 0; m < moves; m++)
  {
    cin >> direction;
    direction -= 1;

    //New coordinate in the map
    int nx = curr_x + dx[direction];
    int ny = curr_y + dy[direction];

    if(nx >= 0 && nx < row && ny >= 0 && ny < col)
    {
      curr_x = nx;
      curr_y = ny;

      
      //West, East
      if(direction == 0 || direction == 1)
      {
        horizontal_push(direction);
      }

      //North, South
      else if(direction == 2 || direction == 3)
      {
        vertical_push(direction);
      }

      //Change Dice num || Map num
      if(map[nx][ny] == 0)
      {
        map[nx][ny] = dice[3];
      }
      else
      {
        dice[3] = map[nx][ny];
        map[nx][ny] = 0;
      }
      
      //Print Top number
      cout << dice[1] << '\n';
    }
  }
}
