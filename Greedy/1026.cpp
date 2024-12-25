#include <iostream>
#include <algorithm>
using namespace std;

int num = 0;
int A[55], B[55];

int cmp(int a, int b)
{
  return a > b;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  for(int i = 0; i < num; i++)
  {
    cin >> A[i];
  }

  for(int j = 0; j < num; j++)
  {
    cin >> B[j];
  }

  sort(A, A + num);
  sort(B, B + num, cmp);

  int sum = 0;
  for(int k = 0; k < num; k++)
  {
    sum += A[k] * B[k];
  }

  cout << sum;
}
