#include <iostream>
#include <vector>
using namespace std;

int n;
int age[100001];
string name[100001];

int tmp_age[100001];
string tmp_name[100001];

void merge(int st, int en)
{
  int mid = (st + en) / 2;
  
  int a_idx = st;
  int b_idx = mid;

  for(int i = st; i < en; i++)
  {
    if(a_idx == mid)
    {
      tmp_age[i] = age[b_idx];
      tmp_name[i] = name[b_idx];
      b_idx++;
    }
    else if(b_idx == en)
    {
      tmp_age[i] = age[a_idx];
      tmp_name[i] = name[a_idx];
      a_idx++;
    }
    else if(age[a_idx] <= age[b_idx])
    {
      tmp_age[i] = age[a_idx];
      tmp_name[i] = name[a_idx];
      a_idx++;
    }
    else
    {
      tmp_age[i] = age[b_idx];
      tmp_name[i] = name[b_idx];
      b_idx++;
    }
  }

  for(int i = st; i < en; i++)
  {
    age[i] = tmp_age[i];
    name[i] = tmp_name[i];
  }
}

void mergesort(int st, int en)
{
  if(en - st == 1)
  {
    return;
  }

  int mid = (st + en) / 2;
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
    cin >> age[i] >> name[i];
  }

  mergesort(0, n);

  for(int i = 0; i < n; i++)
  {
    cout << age[i] << ' ' << name[i] << '\n';
  }
}
