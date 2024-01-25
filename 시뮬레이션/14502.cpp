#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int row, col;
int lab[10][10];
vector<pair<int, int>> virus_loc;

vector<int> wall;
int walls[10][10];

queue<pair<int, int>> virus;
int curr_map[10][10];
int visit[10][10];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void spread()
{
  while(!virus.empty())
  {
    pair<int, int> curr = virus.front();
    virus.pop();

    for(int i = 0; i < 4; i++)
    {
      int nx = curr.first + dx[i];
      int ny = curr.second + dy[i];

      if(nx >= 0 && nx < row && ny >= 0 && ny < col)
      {
        if(visit[nx][ny] == 0 && curr_map[nx][ny] == 0)
        {
          virus.push({nx, ny});
          visit[nx][ny] += visit[curr.first][curr.second] + 1;
        }
      }
    }
  }

  return;
}


int largest_visit[10][10];
int largest_map[10][10];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> row >> col;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> lab[r][c];

      if(lab[r][c] == 2)
      {
        virus_loc.push_back({r, c});
      }
    }
  }

  for(int w = 0; w < row * col - 3; w++)
  {
    wall.push_back(0);
  }
  for(int w = 0; w < 3; w++)
  {
    wall.push_back(1);
  }

  int largest_area = -1;
  do
  {
    int error = 0;
    for(int i = 0; i < row * col; i++)
    {
      walls[i / col][i % col] = wall[i];

      if((lab[i / col][i % col] == 1 || lab[i / col][i % col] == 2) && wall[i] == 1)
      {
        error = 1;
      }
    }

    if(error)
    {
      continue;
    }

    for(int x = 0; x < row; x++)
    {
      for(int y = 0; y < col; y++)
      {
        if(lab[x][y] == 1 || walls[x][y] == 1)
        {
          curr_map[x][y] = 1;
        }
        else
        {
          curr_map[x][y] = 0;
        }
      }
    }

    memset(visit, 0, sizeof(visit));
    for(int l = 0; l < virus_loc.size(); l++)
    {
      virus.push({virus_loc[l].first, virus_loc[l].second});
      visit[virus_loc[l].first][virus_loc[l].second] = 1;
    }
    
    spread();

    int safe_area = 0;
    for(int m = 0; m < row; m++)
    {
      for(int n = 0; n < col; n++)
      {
        if(visit[m][n] == 0 && curr_map[m][n] == 0)
        {
          safe_area++;
        }
      }
    }

    if(largest_area < safe_area)
    {
      largest_area = safe_area;

      for(int m = 0; m < row; m++)
      {
        for(int n = 0; n < col; n++)
        {
          largest_map[m][n] = curr_map[m][n];
          largest_visit[m][n] = visit[m][n];
        }
      }
    }
  }while(next_permutation(wall.begin(), wall.end()));

  cout << largest_area;
}
