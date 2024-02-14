#include <iostream>
using namespace std;

int N, M;
int num[100005];
int D[100005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++)
  {
    cin >> num[i];
  }

  D[1] = num[1];
  for(int i = 2; i <= N; i++)
  {
    D[i] = D[i - 1] + num[i];
  }
  
  while(M--)
  {
    int start, end;
    cin >> start >> end;

    cout << D[end] - D[start - 1] << '\n';
  }
}

/*
갑자기 난이도가 확 쉬워진듯한 느낌.. 내가 뭘 놓치고 있나..?
*/
