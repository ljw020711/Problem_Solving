#include <iostream>
#include <vector>
using namespace std;

int turn_a;
int into_b;

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> turn_a >> into_b;
  int num = 1;
  while(into_b > 0)
  {
    if(into_b == turn_a)
    {
      cout << num;
      return 0;
    }
    
    if(into_b % 2 == 0)
    {
      into_b /= 2;
      num++;
    }
    else if(into_b % 10 == 1)
    {
      into_b = (into_b - 1) / 10;
      num++;
    }
    else
    {
      cout << -1;
      return 0;
    }
  }

  cout << -1;
  return 0;
}

/*
DP이긴한데 Top-Down방식으로 푼 문제.
D[i} 테이블을 정해서 모든 케이스를 다 해보면서 올라가기엔 배열의 크기가 모자랐던 문제.
따라서 가능한 케이스만 접근하면 되는데.

아래서 위로 올라가려면 두 계산식 모두 시행해야함. 따라서 더 많은 케이스가 나오기도하고, 해당 경우들의 숫자를 계속 들고 있으면서
매번 계산을 두개씩 적용해줘야함.

위에서 아래로 접근하게 되면, 현재 수가 짝수/ 홀수인지에 따라 계산식 둘 중 하나만 적용하면 됨.
결국 한 가지 루트만 나오게 되고, 이 루트가 시작값과 동일해지는 순간이 있으면 횟수 출력,
없이 0이하로 도달하게 되면 -1을 출력하면 된다.

생각보다 간단하지만, 탑다운 방식의 풀이와 필요한 케이스만 접근하면 되는것을 생각하기가 어려웠다.
*/
