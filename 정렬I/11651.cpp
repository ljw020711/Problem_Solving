#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> coordinate;
vector<pair<int, int>> tmp;

void merge(int st, int en)
{
  int mid = (st + en) / 2;

  int a_idx = st;
  int b_idx = mid;

  for(int i = st; i < en; i++)
  {
    int x_a = coordinate[a_idx].first;
    int y_a = coordinate[a_idx].second;
    int x_b = coordinate[b_idx].first;
    int y_b = coordinate[b_idx].second;

    if(a_idx == mid)
    {
      tmp.push_back({x_b, y_b});
      b_idx++;
    }
    else if(b_idx == en)
    {
      tmp.push_back({x_a, y_a});
      a_idx++;
    }
    else if(y_a < y_b || y_a == y_b && x_a <= x_b)
    {
      tmp.push_back({x_a, y_a});
      a_idx++;
    }
    else
    {
      tmp.push_back({x_b, y_b});
      b_idx++;
    }
  }

  for(int i = st; i < en; i++)
  {
    coordinate[i] = tmp[i - st];
  }

  tmp.clear();
}

void mergesort(int st, int en)
{
  if(en - st == 1)
  {
    return;
  }

  int mid = (st + en) / 2;
  mergesort(st, mid);
  mergesort(mid, en);
  merge(st, en);
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;

    coordinate.push_back({x, y});
  }

  mergesort(0, n);

  for(int i = 0; i < n; i++)
  {
    cout << coordinate[i].first << ' ' << coordinate[i].second << '\n';
  }
}
