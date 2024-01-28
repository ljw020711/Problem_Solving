#include <iostream>
#include <vector>
using namespace std;

tuple<int, int, int> draw(int x, int y, int dir, int gen);

int grid[102][102];
int curves;

vector<int> directions;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> curves;
  for(int c = 0; c < curves; c++)
  {
    int x, y, dir, gen;
    cin >> x >> y >> dir >> gen;

    //시작점 그리기
    directions.push_back(dir);
    grid[y][x] = 1;

    //주어진 세대의 드래곤 커브 구현
    for(int g = 0; g <= gen; g++)
    {
      int start = 0;
      if(g != 0)
      {
        start = 1 << (g - 1);
      }
      
      //주어진 방향 벡터들을 따라 새로운 점 추가
      for(int i = start; i < directions.size(); i++)
      {      
        x += dx[directions[i]];
        y += dy[directions[i]];

        grid[y][x] = 1;
      }
      //다음 세대의 방향 벡터 추가
      for(int i = directions.size() - 1; i >= 0; i--)
      {
        directions.push_back((directions[i] + 1) % 4);
      }
    }

    directions.clear();
  }

  int squares = 0;
  for(int r = 0; r < 100; r++)
  {
    for(int c = 0; c < 100; c++)
    {
      if(grid[r][c])
      {
        if(grid[r][c + 1] && grid[r + 1][c] && grid[r + 1][c + 1])
        {
          squares++;
        }
      }
    }
  }

  cout << squares;
}


/*
구현 자체는 매우 쉬운 문제였다. 체감 상 실버 3 ~ 4?
다만 아이디어를 떠올리는 게 매우 어려웠다. (답지 보고 알았다.)
새로 추가되는 curve들은 기존 커브를 거꾸로 순회하면서, 시계 방향으로 90도씩 모두 꺾어야 하는 것이 문제 해결의 포인트.
*/
