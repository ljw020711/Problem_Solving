#include <iostream>
using namespace std;

int n;
int arr[1000001];
int tmp[1000001];

void merge(int st, int en)
{
  int mid = (st + en) / 2;

  int a_idx = st;
  int b_idx = mid;

  for(int i = st; i < en; i++)
  {
    if(a_idx == mid)
    {
      tmp[i] = arr[b_idx++];
    }
    else if(b_idx == en)
    {
      tmp[i] = arr[a_idx++];
    }
    else if(arr[a_idx] <= arr[b_idx])
    {
      tmp[i] = arr[a_idx++];
    }
    else
    {
      tmp[i] = arr[b_idx++];
    }
  }

  for(int i = st; i < en; i++)
  {
    arr[i] = tmp[i];
  }
}

void mergesort(int st, int en)
{
  int mid = (st + en) / 2;

  if(en - st == 1)
  {
    return;
  }

  mergesort(st, mid);
  mergesort(mid, en);
  merge(st, en);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  mergesort(0, n);

  for(int i = 0; i < n; i++)
  {
    cout << arr[i] << '\n';
  }
}
