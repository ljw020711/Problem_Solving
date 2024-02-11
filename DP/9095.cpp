#include <iostream>
using namespace std;

int cases, num;
int numbers[12];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> cases;
  
  numbers[1] = 1;
  numbers[2] = 2;
  numbers[3] = 4;
    
  for(int i = 4; i <= 11; i++)
  {
    numbers[i] = numbers[i - 1] + numbers[i - 2] + numbers[i - 3];
  }

  while(cases--)
  {
    cin >> num;
    
    cout << numbers[num] << '\n';
  }
}

/*
음.. 왜 기존 아래 코드로 하면 안되는 지 모르겠다. 크게 문제 없어보이는데 자꾸 틀렸습니다가 출력됨..
#include <iostream>
using namespace std;

int cases, num;
int numbers[12];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> cases;
  
  numbers[1] = 1;
  numbers[2] = 2;
  numbers[3] = 4;

  int start = 4;

  while(cases--)
  {
    cin >> num;

    if(num > 3)
    {
      for(int i = start; i <= num; i++)
      {
        numbers[i] = numbers[i - 1] + numbers[i - 2] + numbers[i - 3];
      }
    }
    
    cout << numbers[num] << '\n';

    start = num + 1;
  }
}

위 코드가 틀린 이유룰 알았다...;;
매우 어이없이 틀려버렸다

위 코드는 start를 num + 1로 설정하기 떄문에
첫 케이스가 다음 케이스 보다 1 작은 값이 아니라면, 그 사이에 있는 값들은 제 값으로 입력되지 않는다!


추가적으로 이 문제를 접근하는 방법을 잘못 알고 있었음(위 코드가 틀린 이유는 아님):
-1, -2, -3한 값에 대해서만 case들을 더해주면 됨!
*/
