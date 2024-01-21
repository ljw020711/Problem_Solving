#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
using namespace std;

int tilt(int dir);
int move_marble(int marb, int dir);

int row, col;
char board[12][12];
int current[12][12];

pair<int, int> out;
vector<tuple<char, int, int>> init;
vector<tuple<char, int, int>> curr;
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

      if(board[r][c] == 'R' || board[r][c] == 'B')
      {
        init.push_back({board[r][c], r, c});
      }
      else if(board[r][c] == 'O')
      {
        out = {r, c};
      }
    }
  }

  int dir = 0;
  int least = 11;
  for(int i = 0; i < (1 << (2 * 10)); i++)
  {
    long long tmp = i;
    
    memset(current, 0, sizeof(current));
    for(int m = 0; m < 2; m++)
    {
      curr.push_back({get<0>(init[m]), get<1>(init[m]), get<2>(init[m])});
      current[get<1>(init[m])][get<2>(init[m])] = get<0>(init[m]);
    }

    for(int j = 1; j <= 10; j++)
    {
      dir = tmp % 4;
      tmp /= 4;

      char result = tilt(dir);
      if(result == 'R' || result == 'B' || result == 'c')
      {
        if(result == 'R' && least > j)
        {
          least = j;
        }
        break;
      }
    }

    curr.clear();
  }
  
  if(least == 11)
  {
    cout << -1;
    return 0;
  }
  cout << least;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int status[2];
queue<tuple<char, int, int>> slides;
int tilt(int dir)
{
  memset(status, 0, sizeof(status));

  int result[2] = {0, 0};
  for(int i = 0; i < 2; i++)
  {
    result[i] = move_marble(i, dir);

    //출구에서 충돌
    if(result[0] == -1 || result[1] == -1)
    {
      return 'c';
    }
  }

  //출구에 도달하였을때
  if(result[0] != 0)
  {
    return result[0];
  }
  else if(result[1] != 0)
  {
    return result[1];
  }

  //평범한 종료
  return -1;
}


int move_marble(int marb, int dir)
{
  //현재 움직일 구슬을 선택
  int start_color = get<0>(curr[marb]);
  int start_x = get<1>(curr[marb]);
  int start_y = get<2>(curr[marb]);

  int changed_x, changed_y;
  slides.push({start_color, start_x, start_y});

  while(!slides.empty())
  {
    int color, x, y;
    tie(color, x, y) = slides.front();
    slides.pop();

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx >= 0 && nx < row && ny >= 0 && ny < col)
    {
      //구슬끼리 충돌하고, 부딪힌 구슬을 움직이지 않은 상황
      if(current[nx][ny] != 0 && status[(marb + 1) % 2] == 0)
      {
        //앞선 구슬을 먼저 이동
        move_marble((marb + 1) % 2, dir);

        //현재 구슬을 마저 이동
        //앞에서 사라졌는지 확인
        if(current[nx][ny] == 0)
        {
          //cout << "Yewsl";
          slides.push({color, nx, ny});
          changed_x = nx;
          changed_y = ny;
          
          current[nx][ny] = color;
          current[x][y] = 0;
        }
      }

      //구슬끼리 충돌하고 충돌한 지점이 출구인 상황 => 실패
      if(current[nx][ny] != 0 && board[nx][ny] == 'O')
      {
        return -1;
      }

      //평범한 이동
      else if(current[nx][ny] == 0 && board[nx][ny] != '#')
      {
        //출구 아님
        if(board[nx][ny] != 'O')
        {
          slides.push({color, nx, ny});
          changed_x = nx;
          changed_y = ny;
        }
        
        current[nx][ny] = color;
        current[x][y] = 0;
      }
      
      if(board[nx][ny] == '#' || current[nx][ny] != 0)
      {
        changed_x = x;
        changed_y = y;
      }
    }
  }

  status[marb] = 1;
  curr[marb] = {start_color, changed_x, changed_y};
  return current[out.first][out.second];
}

/*
이전에 실패했다가 다시 풀게된 문제.
주요 포인트는 n(4^10)의 Back Tracking과 BFS의 활용.
각 구슬을 이동시키는 것은 어렵지 않았으나,
구슬끼리 접촉이 있었을 때를 처리하는 것이 많이 까다로웠음
구슬 중 하나만 출구에 도달하는 경우.
두 구슬 다 출구에 도달하는 경우.
두 구슬이 길 중간에서 부딪히는 경우.
두 구슬이 벽 바로 옆에서 부딪히는 경우.
각 케이스에 맞는 구슬의 x, y좌표 변화를 작성해주는 것이 풀이 포인트가 될듯.
어느 케이스에 nx, ny를 넣고, 어느 케이스에 x, y를 넣는가를 판단하는 것이 어려웠음.
*/
