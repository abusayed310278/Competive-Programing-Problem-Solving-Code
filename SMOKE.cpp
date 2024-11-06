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
        int x, y;
        cin >> x >> y;

        int smoke = 0;
        while (n >= 100)
        {
            int busSmoke = x;
            int carSmoke = 25 * y;
            smoke += min(busSmoke, carSmoke);
            n -= 100;
        }

        if (n > 0)
        {
            int cars = ceil(n / 4.0);
            int carSmoke = cars * y;
            int busSmoke = x;
            smoke += min(busSmoke, carSmoke);
        }

        cout << smoke << endl;
    }
    return 0;
}