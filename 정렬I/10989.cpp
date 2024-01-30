#counting sort
#include <iostream>
using namespace std;

int n;
int arr[10001];

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> n;

  for(int i = 0; i < n; i++)
  {
    cin >> num;
    arr[num]++;
  } 

  for(int i = 0; i < 10001; i++)
  {
    while(arr[i])
    {
      cout << i << '\n';
      arr[i]--;
    }
  }
}

/*
브론즈 1이라 만만하게 봤다가 결국 답지를 본 문제....
N이 크길래 Merge sort -> 메모리 초과가 나길래 Quick sort -> 또 메모리 초과가 나길래 Bubble sort..
결국 답은 모든 값의 경우의 수 0 ~ 10000에 대한 배열을 만들어서, 해당 값이 입력된 만큼 순서대로 다시 출력하는 것이었다
-> 이걸 counting sort라고 부르는 듯?
*/
