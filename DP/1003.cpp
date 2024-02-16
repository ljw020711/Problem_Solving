#include <iostream>
#include <vector>
using namespace std;

int cases;
int D[45];
vector<pair<int, int>> nums;
int main() 
{
  cin >> cases;
  
  D[0] = 0;
  D[1] = 1;

  nums.push_back({1, 0});
  nums.push_back({0, 1});

  for(int i = 2; i <= 40; i++)
  {
    D[i] = D[i - 1] + D[i - 2];
    nums.push_back({nums[i - 1].first + nums[i - 2].first, nums[i - 1].second + nums[i - 2].second});
  }
  
  while(cases--)
  {
    int n;
    cin >> n;

    cout << nums[n].first << ' ' << nums[n].second << '\n';
  }
}
