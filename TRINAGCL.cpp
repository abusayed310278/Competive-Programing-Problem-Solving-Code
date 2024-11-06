// TRIANGCL
// Triangle Classification
// Author: Kanstantsin Sokal
// Complexity: O(1)
// Expected Verdict: AC

#include <bits/stdc++.h>

using namespace std;

long long square(long long x)
{
    return x * x;
}

void order(long long &a, long long &b, long long &c)
{
    if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    if (a > b)
    {
        swap(a, b);
    }
}

string get_side_classification(long long a, long long b, long long c)
{
    order(a, b, c);

    if (a == b || b == c)
    {
        return "Isosceles";
    }
    else
    {
        return "Scalene";
    }
}

string get_angle_classification(long long a, long long b, long long c)
{
    order(a, b, c);

    if (a + b > c)
    {
        return "acute";
    }
    else if (a + b == c)
    {
        return "right";
    }
    else
    {
        return "obtuse";
    }
}

void solve(int subtask_id)
{
    long long x1, y1;
    cin >> x1 >> y1;
    long long x2, y2;
    cin >> x2 >> y2;
    long long x3, y3;
    cin >> x3 >> y3;

    long long a = square(x1 - x2) + square(y1 - y2);
    long long b = square(x1 - x3) + square(y1 - y3);
    long long c = square(x2 - x3) + square(y2 - y3);

    if (subtask_id == 1)
    {
        cout << get_side_classification(a, b, c) << " triangle\n";
    }
    else if (subtask_id == 2)
    {
        cout << get_side_classification(a, b, c) << " " << get_angle_classification(a, b, c) << " triangle\n";
    }
    else
    {
        exit(-1);
    }
}

int main()
{
    int subtask_id;
    scanf("%d", &subtask_id);
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++)
    {
        solve(subtask_id);
    }

    return 0;
}