#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{

    int n = 1e5 + 1;

    vector<int> prime(n, 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i < n; i++)
    {
        if (!prime[i])
            continue;
        for (int j = i * i; j < n; j += i)
        {
            prime[j] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        prime[i] += prime[i - 1];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        if (prime[m] % 2 == 0)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
        }
    }

    return 0;
}