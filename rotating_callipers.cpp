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

// convex hull javris march but  not optimize

vector<Cpoint> convex_hull(vector<Cpoint> a)
{

    int n = a.size();

    int strt = 0;

    for (int i = 1; i < n; i++)
    {

        if ((a[i].x < a[strt].x) or (a[i].x == a[strt].x and a[i].y < a[strt].y))
        {
            strt = i; // find leftmost and bottommost ptn
        }
    }

    vector<Cpoint> ans;
    ans.push_back(a[strt]);

    while (true)
    {

        int pt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == ans.back())
                continue;

            if ((direction(ans.back(), a[pt], a[i]) == -1) or
                (direction(ans.back(), a[pt], a[i]) == 0 and
                 dot(a[i] - ans.back(), a[i] - ans.back()) > dot(a[pt] - ans.back(), a[pt] - ans.back())))
            {
                pt = i;
            }
        }

        if (a[pt] == ans.front())
            break;
        else
            ans.push_back(a[pt]);
    }

    return ans;
}

static Cpoint polar_angle_point;
bool comp(Cpoint a, Cpoint b)
{

    if (direction(polar_angle_point, a, b) == 1)
        return true;
    else if (direction(polar_angle_point, a, b) == -1)
        return false;
    else
        return dot(polar_angle_point - a, polar_angle_point - a) < dot(polar_angle_point - b, polar_angle_point - b);
}

// convex hull graham scan
vector<Cpoint> convex_hull_graham_scan(vector<Cpoint> a)
{

    int n = a.size();
    if (n <= 2)
        return a;

    for (int i = 1; i < n; i++)
    {

        if ((a[i].x < a[0].x) or (a[i].x == a[0].x and a[i].y < a[0].y))
        {
            swap(a[0], a[i]); // find leftmost and bottommost ptn
        }
    }

    polar_angle_point = a[0];
    sort(a.begin() + 1, a.end(), comp);

    vector<Cpoint> ans;
    ans.push_back(a[0]);
    ans.push_back(a[1]);

    for (int i = 2; i < n; i++)
    {

        // stack uses  similar as vector
        while (direction(ans[((int)ans.size()) - 2], ans[((int)ans.size()) - 1], a[i]) != -1)
            ans.pop_back();

        ans.push_back(a[i]);
    }

    return ans;
}

// rotation calipers
double diameter_of_convex_polygon(vector<Cpoint> v)
{

    int n = v.size();

    int pt1 = 0, pt2 = 1;

    while (cross(v[(pt1 + 1) % n] - v[pt1], v[(pt2 + 1) % n] - v[pt2]).z > 0)
    {
        pt2++;
        pt2 %= n;
    }

    long long ans = dot(v[pt2] - v[pt1], v[pt2] - v[pt1]);
    
    int st1 = pt1;
    int st2 = pt2;

    do
    {

        if (cross(v[(pt1 + 1) % n] - v[pt1], v[(pt2 + 1) % n] - v[pt2]).z > 0)
        {
            pt2++;
            pt2 %= n;
        }
        else
        {
            pt1++;
            pt1 %= n;
        }

        ans = max(ans, dot(v[pt2] - v[pt1], v[pt2] - v[pt1]));

    } while (st1 != pt1 || st2 != pt2);

    return sqrt((double)ans);
    
}

int main()
{
    int n;
    cin >> n;
    vector<Cpoint> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }

    a= convex_hull_graham_scan(a);

    cout << diameter_of_convex_polygon(a) << endl;

    return 0;
}

/*

4
0 0
1 0
1 1
0 1


3
0 0
2 0
1 1

*/