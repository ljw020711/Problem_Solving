#include <iostream>
#include <string>
using namespace std;

string secret_code;
long long D[5005];

int make_num(int tenth, int unit)
{
  return (secret_code[tenth] - '0') * 10 + (secret_code[unit] - '0');
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> secret_code;

  int code_len = secret_code.length();
  if(secret_code[code_len - 1] - '0')
  {
    D[1] = 1;
  }
  
  D[2] = D[1];
  int last_2_digit = make_num(code_len - 2, code_len - 1);
  if(last_2_digit > 0 && last_2_digit <= 26)
  {
    D[2] += 1; 
  }

  for(int i = 3; i <= code_len; i++)
  {
    char current = secret_code[code_len - i];
    if(current - '0' == 0)
    {
      
      continue;
    }
    
    if((secret_code[code_len - i + 1] - '0') != 0)
    {
      D[i] += D[i - 1] % 1000000;
    }

    int digits = make_num(code_len - i, code_len - i + 1);
    if(digits > 0 && digits <= 26 && secret_code[code_len - i + 2])
    {
      D[i] += D[i - 2] % 1000000;
    }
    
    D[i] %= 1000000;
  }

  
  cout << D[code_len];
}
