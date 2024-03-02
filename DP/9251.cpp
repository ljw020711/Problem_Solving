#include <iostream>
using namespace std;

string A, B;
int D[1005][1005];
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;
  
  for(int i = 1; i <= A.size(); i++)
  {
    for(int j = 1; j <= B.size(); j++)
    { 
      if(A[i - 1] == B[j - 1])
      {
        D[i][j] = D[i - 1][j - 1] + 1;
      }
      else
      {
        D[i][j] = max(D[i - 1][j], D[i][j - 1]);
      }
    }
  }


  cout << D[A.size()][B.size()];
}

/*
  이것도 수업시간에 배운 문제.
  배운 문제는 다시 틀리면 안될듯.

  문제의 포인트는 새로운 글자가 추가 될 때마다, lcs가 늘어나는지를 확인하는 문제.
  알파벳이 중복으로 나오는 것을 확인하기 위해 동일한 글자가 나오면 "둘 다 없는 상황"에서의 lcs에서 1을 더한다.
  따라서 해당 알파벳이 중복이라 이미 lcs에 포함되어있었다면, 둘 다 없는 상황으로 가게 되면 이전 중복값을 무시하고, 새로 lcs를 만드는것과 
  마찬가지인 효과를 보여준다. 
*/
