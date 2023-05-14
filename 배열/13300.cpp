#include <iostream>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int total, n_room;

  cin >> total >> n_room;

  int boys[6] = {0,};
  int girls[6] = {0,};

  int sex;
  int grade;
  for(int i = 0; i < total; i++)
  {
    cin >> sex >> grade;
    
    if(sex == 0)
    {
      girls[grade - 1]++;
    }
    else
    {
      boys[grade - 1]++;
    }
  }

  int rooms = 0;
  for(int j = 0; j < 6; j++)
  {
    if(girls[j] % n_room != 0)
    {
      rooms = rooms + (girls[j] / n_room) + 1;
    }
    else
    {
      rooms += (girls[j] / n_room);
    }
    if(boys[j] % n_room != 0)
    {
      rooms = rooms + (boys[j] / n_room) + 1;
    }
    else
    {
      rooms += (boys[j] / n_room);
    }
  }
  cout << rooms;
}
