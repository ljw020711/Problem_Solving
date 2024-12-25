#include <iostream>
#include <algorithm>
using namespace std;

int ropes[100005];
int num_ropes;

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_ropes;
    for(int i = 0; i < num_ropes; i++)
    {
        cin >> ropes[i];
    }

    sort(ropes, ropes + num_ropes, cmp);

    int n_current = 1; //Num of ropes using
    int max_weight = -1; //Max weight up to now
    int weight = 0;
    for(int i = 0; i < num_ropes; i++)
    {
        weight = ropes[i] * n_current;

        if(weight > max_weight)
        {
            max_weight = weight;
        }

        n_current++;
    }

    cout << max_weight;
}
