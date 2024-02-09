#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num;
string element;
vector<long long> set;

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  for(int i = 0; i < num; i++)
  {
    cin >> element;
    reverse(element.begin(), element.end());

    set.push_back(stoll(element));
  }

  sort(set.begin(), set.end());
  for(int i = 0; i < num; i++)
  {
    cout << set[i] << '\n';
  }
}

/*
이렇게 쉬운 문제를 못풀고 답지를 봄..

reverse의 사용법과 문자를 뒤집고 난 후에 stoll로 바꾸면 되는 걸 알면 빨리 풀리는 문제
*/
