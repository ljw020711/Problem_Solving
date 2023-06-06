#include <iostream>
#include <stack>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n_word;
  cin >> n_word;

  int ans = 0;
  for(int i = 0; i < n_word; i++)
  {
    string word;
    cin >> word;

    stack<char> alpha;
    for(int j = 0; j < word.length(); j++)
    {
      if(alpha.empty() || alpha.top() != word[j])
      {
        alpha.push(word[j]);
      }
      else
      {
        alpha.pop();
      }
    }

    if(alpha.empty())
    {
      ans++;
    }
  }

  cout << ans;
}
