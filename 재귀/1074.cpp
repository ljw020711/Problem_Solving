#include <iostream>
using namespace std;

int find_loc(int num, int row, int col)
{
  if(num == 0)
  {
    return 0;
  }
  else
  {
    int half = 1 << (num - 1);
    int add = half * half;

    if(row < half && col < half)
      return find_loc(num - 1, row, col);
    
    if(row < half && col >= half)
      return find_loc(num - 1, row, col - half) + add;
    
    if(row >= half && col < half)
      return find_loc(num - 1, row - half, col) + add * 2;
    
    if(row >= half && col >= half)
      return find_loc(num - 1, row - half, col - half) + add * 3;
  }
}


int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num, row, col;
  cin >> num >> row >> col;

  cout << find_loc(num, row, col);
}
