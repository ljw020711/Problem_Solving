#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int connected();
int set();

int row, col;
int board[502][502];
int figure[4][4];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> row >> col;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      cin >> board[r][c];
    }
  }

  vector<int> pre_figure(12, 0);
  for(int i = 0; i < 4; i++)
  {
    pre_figure.push_back(1);
  }

  int max_sum = -1;
  
  do
  {
    for(int idx = 0; idx < 16; idx++)
    {
      figure[idx / 4][idx % 4] = pre_figure[idx];
    }

    int sum = 0;
    if(connected())
    {
      sum = set();

      if(sum > max_sum)
      {
        max_sum = sum;
      }
    }
  }while(next_permutation(pre_figure.begin(), pre_figure.end()));

  cout << max_sum;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> check;
int visit[4][4];
int connected()
{ 
  int count;
  for(int r = 0; r < 4; r++)
  {
    for(int c = 0; c < 4; c++)
    {
      memset(visit, 0, sizeof(visit));
      
      if(figure[r][c] == 1 && visit[r][c] == 0)
      {
        count = 0;
        check.push({r, c});
        visit[r][c] = 1;


        while(!check.empty())
        {
          int x = check.front().first;
          int y = check.front().second;
          check.pop();
          count++;

          for(int i = 0; i < 4; i++)
          {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4)
            {
              if(visit[nx][ny] == 0 && figure[nx][ny] == 1)
              {
                check.push({nx, ny});
                visit[nx][ny] = 1;
              }
            }
          }
        }
      }
    }
  }
  
  if(count == 4)
  {
    return 1;
  }
  
  return 0;
}

vector<pair<int, int>> fig_coordinate;
int set()
{ 
  for(int x = 0; x < 4; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      if(figure[x][y] == 1)
      {
        fig_coordinate.push_back({x, y});
      }
    }
  }
  
  int max_total = -1;
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      int total = 0;

      for(int i = 0; i < 4; i++)
      {
        int nx = fig_coordinate[i].first + r;
        int ny = fig_coordinate[i].second + c;

        if(nx >= 0 && nx < row && ny >= 0 && ny < col)
        {
          total += board[nx][ny];
        }
      }
      
      if(total > max_total)
      {
        max_total = total;
      }
    }
  }
  for(int l = 0; l < 4; l++)
  {
    fig_coordinate.clear();
  }
  
  return max_total;
}

/* 오답노트:
1. 문제 잘 읽기. 문제의 조건을 잘못 읽어서 접근법이 잘못됨
2. 주어진 도형을 모두 만들어 둘 필요 없음. next_permutation과 1차원 배열을 2차원으로 바꾸는 공식 중요
3. BFS시 무조건 nx, ny의 visit을 변경. 이후 pop시에 변경하면 같은 곳이 두번 queue에 푸쉬 됨.
*/
