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

//point add
class cpoint
{

public:
    ll x, y, z;
    cpoint(ll temp_x = 0, ll temp_y = 0, ll temp_z = 0)
    {
        this->x = temp_x;
        this->y = temp_y;
        this->z = temp_z;
    }

    cpoint operator+(cpoint b)
    {
        return cpoint(this->x + b.x, this->y + b.y);
    }
};

void solve()
{

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    cpoint a(x0, y0), b(x1, y1);
    cpoint c=a+b;

    // cout << (a + b).x << " " << (a + b).y << endl;
    cout << c.x << " " << c.y << endl;



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