#include <iostream>
using namespace std;

int N;
int D[1005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  D[1] = 1;
  D[2] = 3;
  for(int i = 3; i <= N; i++)
  {
    D[i] = (D[i - 1] + 2 * D[i - 2]) % 10007;
  }

  cout << D[N];
}
