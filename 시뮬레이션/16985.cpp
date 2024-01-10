#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int maze[5][5][5];                    //Maze that is used in the current BFS
int dir[5];                           //Directions of each plate in the current maze
int plate_order[] = {0, 1, 2, 3, 4};  //Order of the plates in the current maze
int plate_inputs[5][5][5];            //Inputs for the whole program
int r_plate[5][5];                     //Rotated plate(if needed)
int visit[5][5][5];

void make_maze();
void rotate(int plate_num, int dir);
int find_wayout();

int dir_tmp[5];
int plate_tmp[5];
int visit_tmp[5][5][5];

int main() 
{
  //Input
  for(int h = 0; h < 5; h++)
  {
    for(int w = 0; w < 5; w++)
    {
      for(int d = 0; d < 5; d++)
      {
        cin >> plate_inputs[h][w][d];
      }
    }
  }

  int least_distance = 130;
  do
  {
    for(int i = 0; i < (1 << 2 * 5); i++)
    {
      int tmp = i;
      
      for(int j = 0; j < 5; j++)
      {
        dir[j] = tmp % 4;
        tmp /= 4;
      }

      make_maze();
      
      int dis = find_wayout();
      if(dis != -1 && dis < least_distance)
      {
        least_distance = dis;
      }
      
      memset(visit, 0, sizeof(visit));
    }
  }while(next_permutation(plate_order, plate_order + 5));

  if(least_distance == 130)
  {
    least_distance = -1;
  }
  
  cout << least_distance;
}

void make_maze()
{
  for(int h = 0; h < 5; h++)
  {
    if(dir[h] != 0)
    {
      rotate(plate_order[h], dir[h]);

      for(int w = 0; w < 5; w++)
      {
        for(int d = 0; d < 5; d++)
        {
          maze[h][w][d] = r_plate[w][d];
        }
      }
    }
    else
    {
      for(int w = 0; w < 5; w++)
      {
        for(int d = 0; d < 5; d++)
        {
          maze[h][w][d] = plate_inputs[plate_order[h]][w][d];
        }
      }
    }
  }
}

void rotate(int plate_num, int dir)
{
  if(dir == 1)
  {
    for(int r = 0; r < 5; r++)
    {
      for(int c = 0; c < 5; c++)
      {
        r_plate[r][c] = plate_inputs[plate_num][5 - 1 - c][r];
      }
    }
  }
  else if(dir == 2)
  {
    for(int r = 0; r < 5; r++)
    {
      for(int c = 0; c < 5; c++)
      {
        r_plate[r][c] = plate_inputs[plate_num][5 - 1 - r][5 - 1 - c];
      }
    }
  }
  else if(dir == 3)
  {
    for(int r = 0; r < 5; r++)
    {
      for(int c = 0; c < 5; c++)
      {
        r_plate[r][c] = plate_inputs[plate_num][c][5 - 1 - r];
      }
    }
  }
}

int dz[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};

int find_wayout()
{
  if(maze[0][0][0] == 0)
  {
    return -1;
  }
  queue<tuple<int, int, int>> maze_runner;
  maze_runner.push({0, 0, 0});
  visit[0][0][0] = 1;

  while(!maze_runner.empty())
  {
    int z, x, y;
    tie(z, x, y) = maze_runner.front();
    maze_runner.pop();

    for(int i = 0; i < 6; i++)
    {
      int nz = z + dz[i];
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nz >= 0 && nz < 5 && nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
      {
        if(visit[nz][nx][ny] == 0 && maze[nz][nx][ny] == 1)
        {
          maze_runner.push({nz, nx, ny});
          visit[nz][nx][ny] += visit[z][x][y] + 1;
        }
      }
    }
  }

  if(visit[4][4][4] != 0)
  {
    return visit[4][4][4] - 1;
  }

  return -1;
}
