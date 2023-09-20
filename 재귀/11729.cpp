#include <iostream>
using namespace std;

int move_p(int from, int to, int plates)
{
  if(plates == 1)
  {
    cout << from << ' ' << to << '\n';
  }
  else
  {
    move_p(from, 6 - from - to, plates - 1); 
    cout << from << ' ' << to << '\n';
    move_p(6 - from - to, to, plates - 1);
  }

  return 0;
}


int main() 
{
  int plates;
  cin >> plates;

  cout << (1 << plates) - 1 << '\n';
  move_p(1, 3, plates);
}
