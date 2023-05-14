#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc_num;
  string origin, compare;
  int alphabets[26] = {0,};

  cin >> tc_num;
  int impossi = 0;
  for (int i = 0; i < tc_num; i++) {
    cin >> origin >> compare;

    for (int j = 0; j < origin.length(); j++) {
      alphabets[origin[j] - 'a']++;
      alphabets[compare[j] - 'a']--;
    }
    
    for (int k = 0; k < 26; k++) {
      if (alphabets[k] != 0) {
        impossi = 1;
      }
    }

    if (impossi == 1) {
      cout << "Impossible";
    } else {
      cout << "Possible";
    }
    cout << '\n';

    for (int l = 0; l < 26; l++) {
      alphabets[l] = 0;
    }
    impossi = 0;
  }
}
