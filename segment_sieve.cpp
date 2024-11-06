#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

#define N 100000
int sieveArr[N + 1] = {0};
vector<int> primes;

void sieve()
{

    for (ll i = 2; i <= N; i++)
    {
        // i is prime
        if (sieveArr[i]==0)
        {
            primes.push_back(i); // prime number include
            for (ll j = i * i; j <= N; j += i)
            {
                sieveArr[j] = 1; // make not prime
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> m >> n;
    // firstly all are prime
    vector<int> segment(n - m + 1, 0);

    for (auto p : primes)
    {
        // stop when p^2
        if (p * p > n)
            break;

        // otherwise we need to find the nearest starting point
        int start = (m / p) * p;

        // special case
        if (p >= m and p <= n)
        {
            start = 2 * p;//start as next multiple of p
        }

        // marked as non prime from starting
        for (int j = start; j <= n; j += p)
        {
            if (j < m) //out of negative bound 
                continue;

            segment[j - m] = 1; //marked as non prime
        }
    }

    // primes stored as 0 in the segment
    for (int j = m; j <= n; j++)
    {
        if (segment[j - m]==0 and j != 1)
        {
            cout << j << endl;
        }
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}


/*

3
2 10
200 250
90 100


*/