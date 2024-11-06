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


//O(logn)
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

// check point in polygon
/*
this algorithm does not work with concave(theta >180) but work with convex 

this algorithm works with counter clockwise if the points  are given in counter clockwise fashion

*/

int main()
{

    Cpoint a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i].x >> a[i].y;
    }

    cout << check_point_in_polygon(a, 4, a[4]) << endl;

    return 0;
}

/*

let's take 5 points and last point will be checking here
0 0
3 0
4 5
0 2
1 1


0 0
3 0
4 5
0 2
5 5


*/