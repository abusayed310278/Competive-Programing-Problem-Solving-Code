#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i)
        {
            v[i] = {a[i], b[i]};
        }

        sort(v.begin(), v.end());

        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            int start = v[i].first;
            int end = v[i].second;

            for (int j = start; j < end; ++j)
            {
                int count = 0;
                for (int k = 0; k < n; ++k)
                {
                    if (v[k].first <= j && v[k].second > j)
                    {
                        ++count;
                    }
                }
                ans = max(ans, count);
            }
        }

        cout << ans << endl;
    }

    return 0;
}