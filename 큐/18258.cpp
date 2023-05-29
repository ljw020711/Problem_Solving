#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  queue<int> Q;
  for (int i = 0; i < num; i++) {
    string op;
    cin >> op;

    if (op == "push") {
      int n;
      cin >> n;

      Q.push(n);
    } else if (op == "pop") {
      if (Q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << Q.front() << '\n';
        Q.pop();
      }
    } else if (op == "size") {
      cout << Q.size() << '\n';
    } else if (op == "empty") {
      cout << Q.empty() << '\n';
    } else if (op == "front") {
      if (Q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << Q.front() << '\n';
      }
    } else if (op == "back") {
      if (Q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << Q.back() << '\n';
      }
    }
  }
}
