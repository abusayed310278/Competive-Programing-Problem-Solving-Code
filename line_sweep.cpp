#include <bits/stdc++.h>
using namespace std;
#define PI 3.1416

class Cpoint
{
public:
    long long x, y, z;
    Cpoint(long long tmp_x = 0, long long tmp_y = 0, long long tmp_z = 0)
    {
        x = tmp_x;
        y = tmp_y;
        z = tmp_z;
    }

    Cpoint operator+(Cpoint b)
    {
        return Cpoint(this->x + b.x, this->y + b.y); // or Cpoint(*this.x)
    }

    Cpoint operator-(Cpoint b)
    {
        return Cpoint(this->x - b.x, this->y - b.y); // or Cpoint(*this.x)
    }

    Cpoint operator*(long long val)
    {
        return Cpoint(this->x * val, this->y * val, this->z * val);
    }
    Cpoint operator/(long long val)
    {
        return Cpoint(this->x / val, this->y / val, this->z / val);
    }

    Cpoint operator=(Cpoint b)
    {
        this->x = b.x;
        this->y = b.y;
        this->z = b.z;
        return *this;
    }

    Cpoint &operator+=(Cpoint b)
    {
        *this = *this + b;
        return *this;
    }
    Cpoint &operator-=(Cpoint b)
    {
        *this = *this - b;
        return *this;
    }
    Cpoint &operator*=(long long val)
    {
        *this = (*this) * val;
        return *this;
    }
    Cpoint &operator/=(long long val)
    {
        *this = (*this) / val;
        return *this;
    }
    bool operator==(Cpoint b)
    {
        if (this->x == b.x && this->y == b.y && this->z == b.z)
            return true;
        else
            return false;
    }

    bool operator<(Cpoint b)
    {
        if (this->x == b.x)
            return this->y < b.y;
        else
            return this->x < b.x;
    }
};

long long dot(Cpoint a, Cpoint b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Cpoint cross(Cpoint a, Cpoint b)
{
    return Cpoint(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); // Cpoint means vector return kobe
}

double ang(Cpoint a, Cpoint b)
{
    return acos(dot(a, b) / sqrt(dot(a, a) * dot(b, b)));
}

double rad_to_deg(double val)
{
    return val * 180 / PI;
}

double deg_to_rad(double val)
{
    return val * PI / 180;
}

long long signed_area_of_parallelogram(Cpoint a, Cpoint b, Cpoint c)
{
    return cross(b - a, c - b).z;
}

double area_of_traiangle(Cpoint a, Cpoint b, Cpoint c)
{
    return abs(signed_area_of_parallelogram(a, b, c) / 2.0);
}

int direction(Cpoint a, Cpoint b, Cpoint c)
{
    long long t = signed_area_of_parallelogram(a, b, c);

    if (t < 0)
        return -1; // clockwise
    else if (t > 0)
        return 1; // anti-clockwise
    else
        return 0; // coleaner
}

double area_of_polygon(Cpoint a[], int n)
{
    double area = 0;

    for (int i = 0; i < n; i++)
    {
        area -= (a[(i + 1) % n].x - a[i].x) * (a[(i + 1) % n].y + a[i].y);
    }
    area /= 2;
    return abs(area);
}

bool check_point_in_polygon(Cpoint a[], int n, Cpoint p)
{
    int l = 1, r = n - 2;
    while (l < r)
    {
        int x = (l + r) / 2; // where x is mid

        if (direction(a[0], a[x + 1], p) == 1)
            l = x + 1;
        else if (direction(a[0], a[x], p) == -1)
            r = x - 1;
        else
            l = r = x;
    }

    if (area_of_traiangle(a[0], a[l], a[l + 1]) == area_of_traiangle(a[0], a[l], p) + area_of_traiangle(a[l], a[l + 1], p) + area_of_traiangle(a[l + 1], a[0], p))
        return true;
    else
        return false;
}

/*

here given this point counter clock wise a and b


*/

vector<Cpoint> minkowski_sum(vector<Cpoint> a, vector<Cpoint> b)
{

    int n = a.size(), m = b.size();

    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].x < a[l].x or (a[i].x == a[l].x && a[i].y < a[l].y))
        {
            l = i;
        }
    }

    int r = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i].x < b[r].x or (b[i].x == b[r].x && b[i].y < a[r].y))
        {
            r = i;
        }
    }

    // final output vector
    vector<Cpoint> v;
    for (int i = 0; i < n + m; i++)
    {
        v.push_back(a[l] + b[r]);
        if (cross(a[(l + 1) % n] - a[l], b[(r + 1) % m] - b[r]).z >= 0)
            l = (l + 1) % n;
        else
            r = (r + 1) % n;
    }
    return v;
}

// angular sweep
int max_points_in_circle(vector<Cpoint> v, double r)
{

    int n = v.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {

        vector<pair<double, pair<bool, int>>> ang_enex_ind;

        int cur = 1;

        for (int j = 0; j < n; j++)
        {

            if (i == j)
                continue;
            else
            {

                double d = sqrt((double)dot(v[j] - v[i], v[j] - v[i]));
                if (d > (2 * r))
                    continue;

                double ang1 = atan(((double)(v[j] - v[i]).y) / ((double)(v[j] - v[i]).x));
                if ((v[j] - v[i]).x < 0)
                    ang1 += PI;

                double ang2 = acos(d / (2 * r));

                double angen = (8 * PI + ang1 - ang2);
                angen -= 2 * PI * floor(angen / (2 * PI)); // c++  does not have modulus thats why we use this way

                double angex = (8 * PI + ang1 + ang2);
                angex -= 2 * PI * floor(angex / (2 * PI)); // c++  does not have modulus thats why we use this way

                if (angen > angex)
                    cur++;

                ang_enex_ind.push_back({angen, {false, j}}); // points entry
                ang_enex_ind.push_back({angex, {true, j}});  // points exits
            }
        }

        sort(ang_enex_ind.begin(), ang_enex_ind.end());

        for (auto it : ang_enex_ind)
        {

            ans = max(ans, cur);
            if (it.second.first == false)
                cur++;
            else
                cur--;

            ans = max(ans, cur);
        }
    }

    return ans;
}

// line sweep
class ds
{

public:
    set<Cpoint> st;
    priority_queue<Cpoint> hp;
    long long d;

    bool ins(Cpoint a)
    {
        hp.push(Cpoint(-a.x, a.y));
        st.insert(Cpoint(a.y, a.x));

        return true;
    }

    void del(Cpoint a)
    {

        while ((-hp.top().x) < a.x - d)
        {
            auto it = st.find(Cpoint(hp.top().y, -hp.top().x));
            st.erase(it);
            hp.pop();
            return;
        }
    }

    vector<Cpoint> query(Cpoint a)
    {

        auto it = st.lower_bound(Cpoint(a.y - d, 0));
        auto end = st.upper_bound(Cpoint(a.y + d, a.x));

        vector<Cpoint> ans;
        while (it != end)
        {
            ans.push_back(Cpoint( (*it).y, (*it).x));
        }

        return ans;
    }
};

// line sweep

int main()
{
    int n, r;
    cin >> n >> r;
    vector<Cpoint> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }

    cout << max_points_in_circle(a, r) << endl;

    return 0;
}

/*






*/