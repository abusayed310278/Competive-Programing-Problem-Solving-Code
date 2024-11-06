#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;

int dx[4] = {-2, -2, 1, -1};
int dy[4] = {1, -1, -2, -2};

int give_grundy(int x, int y)
{
    if (mp.count({x, y}))
        return mp[{x, y}];
    set<int> st;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 && xx <= 15 && yy >= 1 && yy <= 15)
        {
            st.insert(give_grundy(xx, yy));
        }
    }
    int mex = 0;
    for (int i = 0;; i++)
    {
        if (st.find(i) == st.end())
        {
            mex = i;
            break;
        }
    }
    return mp[{x, y}] = mex;
}

int main()
{
    

    int t;
    cin >> t;
    while (t--)
    {
        int n, nimsum = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            nimsum ^= give_grundy(x, y);
        }
        if (nimsum)
        {
            cout << "First\n";
        }
        else
        {
            cout << "Second\n";
        }
    }

    return 0;
}


/*

2
3
5 4
5 8
8 2
6
7 1
7 2
7 3
7 4
7 4
7 4

*/