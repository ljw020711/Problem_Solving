#include <iostream>
#include <algorithm>
using namespace std;

int num;
string words[20002];

bool cmp(string a, string b)
{
  if(a.length() != b.length())
  {
    return a.length() < b.length();
  }
  return a < b;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  for(int i = 0; i < num; i++)
  {
    cin >> words[i];
  }

  sort(words, words + num, cmp);

  string curr = "";
  for(int i = 0; i < num; i++)
  {
    if(curr != words[i])
    {
      cout << words[i] << '\n';
      curr = words[i];
    }
  }
}

/*
쉬운 문제.
다만 중복을 제거를 정렬 후에 하는 것이 더 효율적이라는 것을 눈치채는 것이 중요
*/
