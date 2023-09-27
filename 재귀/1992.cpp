#include <iostream>
#include <string>
using namespace std;

int paper[64][64];
int white = 0;
int blue = 0;
string tree;

int check(int x, int y, int n)
{
  int base = paper[x][y];

  for(int r = 0; r < n; r++)
  {
    for(int c = 0; c < n; c++)
    {
      if(base != paper[x + r][y + c])
      {
        return 0;
      }
    }
  }

  return 1;
}


int split(int x, int y, int n)
{ 
  if(check(x, y, n))
  {
    if(paper[x][y] == '0')
    {
      tree += '0';
    }
    else
    {
      tree += '1';
    }

    return 0;
  }

  int next = n / 2;
  tree += '(';
  
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      split(x + i * next, y + j * next, next);
    }
  }

  tree += ')';
  return 0;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  string line;
  for(int r = 0; r < num; r++)
  {
    cin >> line;
    
    for(int c = 0; c < num; c++)
    {
      paper[r][c] = line[c];
    }
  }

  split(0, 0, num);

  cout << tree;
}
