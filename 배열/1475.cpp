#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int sets[10] = {
      0,
  };

  int num;
  cin >> num;

  while (num > 0) {
    if (num % 10 == 9 || num % 10 == 6) {
      sets[6]++;
    } else {
      sets[num % 10]++;
    }
    num /= 10;
  }
  /*
  for (int i = 0; i < 10; i++) {
    cout << sets[i];
  }
  */

  int max = sets[0];
  for(int i = 1; i < 10; i++)
  {
    if(max < sets[i])
    {
      if(i == 6)
      {
        if(sets[i] % 2 != 0)
        {
          if((sets[i] / 2) + 1 > max)
          {
            max = (sets[i] / 2) + 1;
          }
        }
        else
        {
          if((sets[i] / 2) > max)
          {
            max = sets[i] / 2;
          }
        }
      }
      else
      {
        max = sets[i];
      }
    }
  }

  cout << max;
}
