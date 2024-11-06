#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool x = true;
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i += 2)
            {
                if (s[i] != '0' || s[i + 1] != '1')
                {
                    x = false;
                    break;
                }
            }

            if (x)
            {
                cout << n / 2 << endl;
                continue;
            }
        }

        int zero = count(begin(s), end(s), '0'), one = count(begin(s), end(s), '1');

        if (one == zero)
            cout << one - 1 << endl;
        else
            cout << min(one, zero) << endl;
    }
}