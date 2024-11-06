#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int n;
        cin >> n;
        unordered_set<int> s;
        s.insert(0);
        int a = 0, ans = 0;
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            a ^= t;
            if (s.count(a))
            {
                ans++;
                a = 0;
                s.clear();
                s.insert(0);
            }
            else
            {
                s.insert(a);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
