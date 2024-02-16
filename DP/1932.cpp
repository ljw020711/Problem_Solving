#include <iostream>
using namespace std;

int height;
long long D[505][505];
int tri[505][505];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> height;
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j <= i; j++)
    {
      cin >> tri[i][j];
    }
  }

  D[0][0] = tri[0][0];
  for(int i = 1; i < height; i++)
  {
    for(int j = 0; j <= i; j++)
    {
      if(j == 0)
      {
        D[i][j] = D[i - 1][j] + tri[i][j];
      }
      else if(j == i)
      {
        D[i][j] = D[i - 1][j - 1] + tri[i][j];
      }
      else
      {
        D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + tri[i][j];
      }
    }
  }

  long long max_path = D[height - 1][0];
  for(int j = 1; j < height; j++)
  {
    max_path = max(max_path, D[height - 1][j]);
  }
  cout << max_path;
}
