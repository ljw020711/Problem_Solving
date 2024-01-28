#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int play();

int row, col, horizontal;
int board[32][12];
int curr_board[32][12];
vector<pair<int, int>> extras;
vector<int> curr_branches;
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  //INPUT
  cin >> col >> horizontal >> row;
  for(int h = 0; h < horizontal; h++)
  {
    int x, y;
    cin >> x >> y;

    board[x - 1][y - 1] = 1;
  }

  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col - 1; c++)
    {
      if(board[r][c] || board[r][c - 1] || board[r][c + 1])
      {
        continue;
      }

      extras.push_back({r, c});
    }
  }

  //추가할 가로선의 개수 선택 (0 ~ 3개)
  int add = 3;
  if(extras.size() < 3)
  {
    add = extras.size();
  }

  for(int i = 0; i <= add; i++)
  {
    for(int j = 0; j < extras.size() - i; j++)
    {
      curr_branches.push_back(0);
    }
    for(int j = 0; j < i; j++)
    {
      curr_branches.push_back(1);
    }

    do
    {
      for(int r = 0; r < row; r++)
      {
        for(int c = 0; c < col - 1; c++)
        {
          curr_board[r][c] = board[r][c];
        }
      }

      for(int k = 0; k < curr_branches.size(); k++)
      {
        if(curr_branches[k])
        {
          curr_board[extras[k].first][extras[k].second] = 1;
        }
      }

      if(play())
      {
        cout << i;
        return 0;
      }
      
    }while(next_permutation(curr_branches.begin(), curr_branches.end()));

    curr_branches.clear();
  }

  cout << -1;
}

int play()
{
  for(int v = 0; v < col; v++)
  {
    int curr = v;

    for(int j = 0; j <= row; j++)
    {
      if(curr < col - 1 && curr_board[j][curr])
      {
        curr++;
      }
      else if(curr > 0 && curr_board[j][curr - 1])
      {
        curr--;
      }
    }

    if(curr != v)
    {
      return 0;
    }
  }
  
  return 1;
}

/*
문제 자체는 그렇게까지 안어려웠나...?
하지만 시간 초과에서 정신 나가버릴 뻔 했던 문제
시간 초과가 났던 이유는 크게 두가지
(1) vector + next_permutation을 하는 과정에서 겹치는 가로선까지 포함해서 진행함.
    -> 굳이 모든 경우에 수를 해보지 않고, 들어갈 수 있는 가로선 위치만 x, y로 따로 뽑아, 해당 수만큼의 next_permutation만 진행해야함.
(2) BFS로 사다리 타기를 진행할 경우 쓸데 없는 시간 복잡도가 늘어남. 간단하게 이중 for문으로 O(n^2)으로 끝낼 수 있음.

추가적으로,
(3) 지도를 필히 초기화 해야함. 초기화는 초기 입력값 지도를 계속해서 이중 for문으로 옮겨주는 것이 필요.
(4) 사용한 벡터 또한 초기화 필요
*/

/*
모범 답안을 보고 배운 것
(1) next_permutation이 아니라 3중 for문으로 진행 시, 지도를 초기화할 필요가 없음. 백트래킹처럼 해당 되는 위치를 true로 하고 
    사다리 타기 진행 후, 다시 해당 가로선의 값을 false로 해주면 됨.
*/
