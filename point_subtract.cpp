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

// point subtract
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
        return cpoint(this->x + b.x, this->y + b.y, this->z + b.z);
    }

    cpoint operator-(cpoint b)
    {
        return cpoint(this->x - b.x, this->y - b.y, this->z - b.z);
    }

    cpoint operator*(ll val)
    {
        return cpoint(this->x * val, this->y * val, this->z * val);
    }

    cpoint operator/(ll val)
    {
        return cpoint(this->x / val, this->y / val, this->z / val);
    }

    // 2
    cpoint &operator+=(cpoint b)
    {
        *this = *this + b;
        return *this;
    }

    cpoint &operator-=(cpoint b)
    {
        *this = *this - b;
        return *this;
    }

    cpoint &operator*=(ll val)
    {
        *this = *this * val;
        return *this;
    }

    cpoint &operator/=(ll val)
    {
        *this = *this / val;
        return *this;
    }

    cpoint operator==(cpoint b)
    {
        if (this->x == b.x and this->y == b.y and this->z == b.z)
            return true;
        else
            return false;
    }

    cpoint operator=(cpoint b)
    {
        this->x = b.x;
        this->y = b.y;
        this->z = b.z;

        return *this;
    }

    bool operator<(cpoint b)
    {
        if (this->x == b.x)
            return this->y < b.y;
        else
            return this->x < b.x;
    }
};

ll dot(cpoint a, cpoint b)
{

    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

cpoint cross(cpoint a, cpoint b)
{
    return cpoint(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

// 3
double angle(cpoint a, cpoint b)
{
    return acos(dot(a, a) / sqrt(dot(a, a) * dot(b, b)));
}

void solve()
{

    int x0, y0, z0, x1, y1, z1;
    cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;

    cpoint a(x0, y0, z0), b(x1, y1, z1);

    /*cpoint c = a - b;

    cout << (a - b).x << " " << (a - b).y << endl;
    cout << c.x << " " << c.y << endl;
    */

    /*

            //2
    a += b;

    cout << (a).x << " " << (a).y << endl;
    */

    // 3
    cout << angle(a, b) << endl;
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