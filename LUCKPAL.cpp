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
const string lucky = "lucky";

string s;
string ansstr;
int ans;
void f(int x, int y, int c, string &temp)
{

    int i = 0, j = n - 1;
    while (i < j)
    {
        if (temp[i] == temp[j])
        {
            i++, j--;
            continue;
        }

        if (i >= x and i <= y)
            temp[j] = temp[i];
        else if (j >= x and j <= y)
            temp[i] = temp[j];
        else
            temp[i] = temp[j] = min(temp[i], temp[j]);

        c++, i++, j--;
        if (ans == c)
            anstr = min(ansstr, temp);
        else if (ans > c)
            ansstr = temp, ans = c;
    }
}

bool solve()
{
    // Write your solution code here
    cin >> s;
    int n = s.size();
    if (n < 9)
    {
        cout << "unlucky/n";
        return 0;
    }

    for (int i = 0; i < n - 4; i++)
    {
        string temp = s;
        for (int j = 0; j < 5; j++)
        {
            if (temp[i + j] != lucky[j])
                pre++;
            temp[i + j] = lucky[j];
        }
        f(i, i + 4, pre, temp);
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.length();
        ans = n + 1;
        anstr = "";
        if (solve())
            cout << ansstr << " " << ans << "\n";
    }

    return 0;
}