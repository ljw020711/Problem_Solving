#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str1, str2;
  int alphabets[26] = {0,};
  cin >> str1 >> str2;

  for (int i = 0; i < str1.length(); i++) 
  {
    alphabets[str1[i] - 'a']++;
  }
  
  for (int i = 0; i < str2.length(); i++) 
  {
    alphabets[str2[i] - 'a']--;
  }

  int result = 0;
  for(int j = 0; j < 26; j++)
  {
    if(alphabets[j] != 0)
    {
      result += abs(alphabets[j]);
    }
  }

  cout << result;
}
