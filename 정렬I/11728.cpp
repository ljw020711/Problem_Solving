#include <iostream>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int size1, size2;
  cin >> size1 >> size2;

  int A[size1];
  int B[size2];
  int C[size1 + size2];

  for(int i = 0; i < size1; i++)
  {
    cin >> A[i];
  }

  for(int i = 0; i < size2; i++)
  {
    cin >> B[i];
  }

  int idx1 = 0;
  int idx2 = 0;
  for(int j = 0; j < size1 + size2; j++)
  {
    if(idx1 == size1)
    {
      C[j] = B[idx2];
      idx2++;
    }
    else if(idx2 == size2)
    {
      C[j] = A[idx1];
      idx1++;
    }
    else if(A[idx1] > B[idx2])
    {
      C[j] = B[idx2];
      idx2++;
    }
    else
    {
      C[j] = A[idx1];
      idx1++;
    }
  }

  for(int j = 0; j < size1 + size2; j++)
  {
    cout << C[j] << ' ';
  }
}
