#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int move(int dir, int x, int y);

int num, incline;
int map[102][102];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  //INPUT
  cin >> num >> incline;
  for(int r = 0; r < num; r++)
  {
    for(int c = 0; c < num; c++)
    {
      cin >> map[r][c];
    }
  }
  
  //FIND ROAD
  int passable = 0;
  for(int r = 0; r < num; r++)
  {
    if(move(0, r, 0))
    {
      passable++;
    }
  }
  
  for(int c = 0; c < num; c++)
  {
    if(move(1, 0, c))
    {
      passable++;
    }
  }

  cout << passable;
}

int dx[] = {0, 1};
int dy[] = {1, 0};
int move(int dir, int s_x, int s_y)
{
  queue<pair<int, int>> walk;
  int visit[num][num];
  memset(visit, 0, sizeof(visit));
  
  walk.push({s_x, s_y});
  visit[s_x][s_y] = 1;
  int trace = 1;

  while(!walk.empty())
  {
    int x = walk.front().first;
    int y = walk.front().second;
    int curr_height = map[x][y];
    walk.pop();

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < num && ny < num)
    {
      //다음 높이가 같은 경우 -> move
      if(map[nx][ny] == curr_height)
      {
        walk.push({nx, ny});
        visit[nx][ny] = visit[x][y] + 1;
        trace++;
      }

      //다음 높이가 높아지는 경우(높이 차 1)
      else if(map[nx][ny] - curr_height == 1)
      {
        //지나온 길의 길이와 경사로의 길이 비교
        if(trace >= incline)
        {
          walk.push({nx, ny});
          visit[nx][ny] = visit[x][y] + 1;
          trace = 1;
        }
      }

      //다음 높이가 낮아지는 경우(높이 차 1)
      else if(map[nx][ny] - curr_height == -1)
      {
        int fail = 0;
        int tmp_x = nx;
        int tmp_y = ny;
        int tmp_curr_height = map[nx][ny];
        
        //일단 진행, 앞으로 지나갈 길의 trace 세기
        for(int tr = 1; tr < incline; tr++)
        {
          tmp_x += dx[dir];
          tmp_y += dy[dir];

          //경사로를 설치할 길이 남아있지 않은 경우
          if(tmp_x >= num || tmp_y >= num)
          {
            fail = 1;
            break;
          }
          //길이 중간에 높아지거나 낮아져, 경사로를 설치할 수 없는 경우
          if(map[tmp_x][tmp_y] < tmp_curr_height || map[tmp_x][tmp_y] > tmp_curr_height)
          {
            fail = 1;
            break;
          }

          tmp_curr_height = map[tmp_x][tmp_y];
        }

        //아래로 내려가는 경사로 설치가 가능한 경우
        if(!fail)
        {
          walk.push({nx, ny});
          visit[nx][ny] = visit[x][y] + 1;
          trace = 1 - incline;
        }
      }
    }
  }

  if(dir == 0)
  {
    if(visit[s_x][num - 1] != 0)
    {
      return 1;
    }
  }

  else if(dir == 1)
  {
    if(visit[num - 1][s_y] != 0)
      {
        return 1;
      }
  }

  return 0;
}

/*
전반적으로 크게 어렵지는 않았던 문제
내려가는 경사로를 설치하는 것에서 조금 헷갈리는 부분이 있었음
(1) 내려가는 경사로의 가능 여부 계산에서 높낮이 변화를 찾아야 하는데, 이때 새로운 x, y값(tmp)의 높이와 비교해야 했음
(2) 가능 여부 파악 후, trace를 초기화 할 때, 높아지는 경우는 trace가 1로(도착한 곳이 새로운 출발지점이므로), 낮아지는 경우는
도착한 곳이 경사로의 끝이므로 0으로 초기화 해야함. + 낮아지는 경우는 가능 여부 파악 후에 bfs를 가는 것이므로, trace의 초기값을 
1 - 경사로의 길이로 해야 마지막 지점에서 trace가 0으로 할당됨.
*/
