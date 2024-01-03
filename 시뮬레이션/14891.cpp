#include <iostream>
#include <cstring>
using namespace std;

int gear_input;
int gear[4][8];
int gear_status[4];

//initialize
void turn(int g_num, int dir);

void influence(int g_num, int dir)
{ 
  if(g_num == 0)
  {
    if(gear[g_num][2] != gear[g_num + 1][6])
    {
      turn(g_num + 1, dir * -1);
    }
  }

  else if(g_num == 1 || g_num == 2)
  {
    if(gear[g_num][2] != gear[g_num + 1][6])
    {
      turn(g_num + 1, dir * -1);
    }
    if(gear[g_num][6] != gear[g_num - 1][2])
    {
      turn(g_num - 1, dir * -1);
    }
  }

  else if(g_num == 3)
  {
    if(gear[g_num][6] != gear[g_num - 1][2])
    {
      turn(g_num - 1, dir * -1);
    }
  }
}

void turn(int g_num, int dir)
{
  if(gear_status[g_num] == 1)
  {
    return;
  }
  
  gear_status[g_num] = 1;
  influence(g_num, dir);
  
  if(dir == 1)
  {
    int tmp = gear[g_num][7];
    for(int i = 6; i >= 0; i--)
    {
      gear[g_num][i + 1] = gear[g_num][i];
    }

    gear[g_num][0] = tmp;
  }
  else if(dir == -1)
  {
    int tmp = gear[g_num][0];
    for(int i = 1; i < 8; i++)
    {
      gear[g_num][i - 1] = gear[g_num][i];
    }

    gear[g_num][7] = tmp;
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  //input
  for(int g = 0; g < 4; g++)
  {
    cin >> gear_input;

    for(int i = 7; i >= 0; i--)
    {
      gear[g][i] = gear_input % 10;
      gear_input /= 10;
    }
  }

  int t_num, g_num, dir;
  cin >> t_num;
  while(t_num--)
  {
    cin >> g_num >> dir;

    turn(g_num - 1, dir);
    memset(gear_status, 0, sizeof(gear_status));

  }

  int sum = 0;
  for(int g = 0; g < 4; g++)
  {
    sum += (gear[g][0] << g);
  }

  cout << sum;
}
