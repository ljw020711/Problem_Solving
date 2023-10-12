#include <iostream>
using namespace std;

int eggs;
int dur[8];
int weight[8];
int broken[8];

int num = 0;
int max_num = 0;
void func(int n) 
{
  if(n == eggs) 
  {
    if(max_num < num) 
    {
      max_num = num;
    }
    return;
  }
    
  if(broken[n] == 1 || num == eggs - 1) 
  {
    func(n + 1);
    return;
  }
    
  for(int i = 0; i < eggs; i++) 
  {     
    if(n == i || broken[i] == 1) 
    {
      continue;
    }
        
    dur[n] -= weight[i];
    dur[i] -= weight[n];
        
    if(dur[n] <= 0) 
    {
      num++;
      broken[n] = 1;
    }
        
    if(dur[i] <= 0)
    {
      num++;
      broken[i] = 1;
    }
      
    func(n + 1);

    if(dur[n] <= 0) 
    {
      num--;
      broken[n] = 0;
    }
        
    if(dur[i] <= 0) 
    {
      num--;
      broken[i] = 0;
    }
    
    dur[n] += weight[i];
    dur[i] += weight[n];
  }
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> eggs;
  for(int i = 0; i < eggs; i++) 
  {
    cin >> dur[i] >> weight[i];
  }
    
  func(0);
    
  cout << max_num;
}
