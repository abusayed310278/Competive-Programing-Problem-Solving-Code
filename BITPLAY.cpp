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

int bs(vector<int> &v, int ele)
{

    int lo = 0, hi = v.size() - 1;

    while (hi - lo > 1)
    {

        int mid = (lo + hi) / 2;
        if (v[mid] < ele)
            lo = mid + 1;
        else //v[mid]>=ele
            hi = mid;
    }

    if (v[lo] == ele)
        return lo;
    else if (v[hi] == ele)
        return hi;
    else
        return -1;
}


int lower_bound(vector<int> &v, int ele)
{

    int lo = 0, hi = v.size() - 1;

    while (hi - lo > 1)
    {

        int mid = (lo + hi) / 2;
        if (v[mid] < ele)
            lo = mid + 1;
        else ////v[mid]>=ele
            hi = mid;
    }

    if (v[lo] >= ele)
        return lo;
    else if (v[hi] >= ele)
        return hi;
    else
        return -1;
}

int upper_bound(vector<int> &v, int ele)
{

    int lo = 0, hi = v.size() - 1;

    while (hi - lo > 1)
    {

        int mid = (lo + hi) / 2;
        if (v[mid] <= ele)
            lo = mid + 1;
        else ////v[mid]>ele
            hi = mid;
    }

    if (v[lo] > ele)
        return lo;
    else if (v[hi] > ele)
        return hi;
    else
        return -1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ele;
    cin >> ele;
    // cout << "Bs: " << bs(v, ele) << endl;
    // cout << "lower_bound: " << lower_bound(v, ele) << endl;
    cout << "upper_bound: " << upper_bound(v, ele) << endl;

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}