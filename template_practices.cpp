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

class cpoint
{

public:
    int x, y, z, val;
    cpoint(int x = 0, int y = 0, int z = 0)
    {
        this->x = x, this->y = y, this->z = z;
    }

    cpoint operator+(cpoint b)
    {
        return cpoint(this->x + b.x, this->y + b.y);
    }

    cpoint operator-(cpoint b)
    {
        return cpoint(this->x - b.x, this->y - b.y);
    }
    cpoint &operator*=(int val)
    {
        (*this) *= val;
        return (*this);
    }
};

void solve()
{
    int x0, y0, val;
    cin >> x0 >> y0 >> val;

    

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