#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  string str;
  cin >> str;
  int alphabets[26];

  memset(alphabets, 0, sizeof(alphabets));

  for(int i = 0; i < str.length(); i++ )
  {
    alphabets[str[i] - 97] += 1;
  }

  for(int j = 0; j < 26; j++)
  {
    cout << alphabets[j] << ' ';
  }
}
