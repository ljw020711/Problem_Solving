#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int num_meetings, start_h, end_h;
vector<pair<int, int>> meeting;

int cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_meetings;

    for(int i = 0; i < num_meetings; i++)
    {
        cin >> start_h >> end_h;
        meeting.push_back(make_pair(start_h, end_h));
    }

    sort(meeting.begin(), meeting.end(), cmp);

    int current = 0;
    int meets = 0;
    for(int i = 0; i < num_meetings; i++)
    {
        if(current > meeting[i].first)
        {
            continue;
        }

        current = meeting[i].second;
        meets++;
    }

    cout << meets;
}


/*
오랜만에 풀어서 그런지 헷갈리네...

문제의 포인트는 정렬을 잘하는 것. 
다른 경우에는 크게 상관있지는 않지만,

2
4 4
1 4와 같이 먼저 시작하고, 바로 끝나는 것이 있으면 먼저 시작하는 것을 선택해야하기에 
pair의 첫 원소를 두번째 정렬 조건에 넣어주어야한다...
*/