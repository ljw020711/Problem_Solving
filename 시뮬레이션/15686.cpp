#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num, max_chicken;
int town[52][52];
vector<pair<int, int>> chicken_seller;
vector<int> chicken_seller_status;
vector<pair<int, int>> house;

int find_shortest_pathlen()
{
  int city_chicklen = 0;

  //choose a house
  for(int h = 0; h < house.size(); h++)
  {
    int chicken_len = 200;

    for(int c = 0; c < chicken_seller.size(); c++)
    {
      if(chicken_seller_status[c] == 1)
      {
        continue;
      }

      int len = abs(house[h].first - chicken_seller[c].first) + abs(house[h].second - chicken_seller[c].second);

      if(len < chicken_len)
      {
        chicken_len = len;
      }
    }

    city_chicklen += chicken_len;
  }

  return city_chicklen;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  //input
  cin >> num >> max_chicken;
  for(int r = 0; r < num; r++)
  {
    for(int c = 0; c < num; c++)
    {
      cin >> town[r][c];

      if(town[r][c] == 1)
      {
        house.push_back({r, c});
      }
      else if(town[r][c] == 2)
      {
        chicken_seller.push_back({r, c});
      }
    }
  }

  //choose not closing chicken seller, nCmax_chicken
  for(int i = 0; i < chicken_seller.size(); i++)
  {
    if(i < max_chicken)
    {
      chicken_seller_status.push_back(0);
    }
    else
    {
      chicken_seller_status.push_back(1);
    }
  }

  int shortest = 2500 * 100;
  do
  {
    //calculate distance
    int curr_shortest = find_shortest_pathlen();

    if(shortest > curr_shortest)
    {
      shortest = curr_shortest;
    }
  }while(next_permutation(chicken_seller_status.begin(), chicken_seller_status.end()));


  cout << shortest;
}
