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
