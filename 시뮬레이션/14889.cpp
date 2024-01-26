#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int num;
int status[22][22];
int sum[2];
vector<int> teams;
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  for(int r = 0; r < num; r++)
  {
    for(int c = 0; c < num; c++)
    {
      cin >> status[r][c];
    }
  }

  for(int i = 0; i < num / 2; i++)
  {
    teams.push_back(0);
  }
  for(int i = 0; i < num / 2; i++)
  {
    teams.push_back(1);
  }

  int least_diff = INT_MAX;
  do
  {
    for(int i = 0; i < num; i++)
    {
      int curr_team = teams[i];
      for(int j = 0; j < num; j++)
      {
        if(curr_team == teams[j])
        {
          sum[curr_team] += status[i][j];
        }
      }
    }
    
    int diff = abs(sum[0] - sum[1]);
    if(diff < least_diff)
    {
      least_diff = diff;
    }

    memset(sum, 0, sizeof(sum));
  }while(next_permutation(teams.begin(), teams.end()));

  cout << least_diff;
}

/*
실버1 중에서도 쉬운 문제.
팀을 나누는 법을 잠시 고민했지만, next_permutation으로 0, 1을 나눈 후
같은 team을 공유하는 배열값끼리의 sum을 비교하면 되는 문제
sum값을 초기화하지 않아서 오류가 났었음
*/
