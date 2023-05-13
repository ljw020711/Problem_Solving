#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  int cards[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10, 11, 12, 13, 14, 15, 16, 17, 18 , 19 , 20};    //1~20까지의 카드(기본)
  int start, end, diff;
  
  for(int i = 0; i < 10; i++)
  {
    cin >> start >> end;
    diff = end - start + 1;
    start -= 1;
    
    reverse(begin(cards) + start, begin(cards) + start + diff);
  }

  for(int j = 0; j < 20; j++)
  {
    cout << cards[j] << ' ';
  }
}
