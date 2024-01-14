#include <iostream>
#include <queue>
using namespace std;

int map_len;
/*
  0: road
  1: apple
*/
int map[102][102];
int num_apple, apple_x, apple_y;

int num_dir;
int second;
char dir;
queue<pair<int, int>> turn_direction;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> dummy;
pair<int, int> head, tail;
int visit[102][102];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> map_len;
  cin >> num_apple;
  for(int apple = 0; apple < num_apple; apple++)
  {
    cin >> apple_x >> apple_y;
    map[apple_x - 1][apple_y - 1] = 1;
  }

  cin >> num_dir;
  for(int direction = 0; direction < num_dir; direction++)
  {
    cin >> second >> dir;
    turn_direction.push({second, dir});
  }

  queue<pair<int ,int>> snake;
  dummy.push({0, 0});
  snake.push({0, 0});
  visit[0][0] = 1;
  int curr_dir = 0; 
  
  int x, y;
  int sec = 0;
  while(1)
  {
    sec++;
    
    x = dummy.front().first;
    y = dummy.front().second;
    dummy.pop();
      
    x = x + dx[curr_dir];
    y = y + dy[curr_dir];

    if(x < 0 || x >= map_len || y < 0 || y >= map_len)  //Wall crash
    {
      cout << sec;
      return 0;
    }
      
    if(map[x][y] == 1)  //ate apple
    {
      if(visit[x][y] == 1) //Crash itself
      {
        cout << sec;
        return 0;
      }

      dummy.push({x, y});
      snake.push({x, y});
      map[x][y] = 0;
      visit[x][y] = 1;
    }
    else
    { 
      if(visit[x][y] == 1)
      {
        cout << sec;
        return 0;
      }

      pair<int, int> tail = snake.front();
      snake.pop();
      visit[tail.first][tail.second] = 0;
      
      dummy.push({x, y});
      snake.push({x, y});
      visit[x][y] = 1;
    }

    if(sec == turn_direction.front().first)
    {
      char turn = turn_direction.front().second;
      turn_direction.pop();
      if(turn == 'D')
      {
        curr_dir = (curr_dir + 1) % 4;
      }
      else
      {
        curr_dir = (curr_dir + 3) % 4;
      }
    }
  }

  cout << sec;
}
