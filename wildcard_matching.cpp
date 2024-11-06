#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string s, p;
    int n, m;
    vector<vector<int>>dp;

    bool f(int i, int j) {

        if (i == n && j == m)return true;
        if (j == m)return false;
        if (dp[i][j] != -1)return dp[i][j];

        bool ans = false;

        if (i < n && s[i] == p[j]) {

            ans |= f(i + 1, j + 1);

        } else if (p[j] == '?') {

            if (i == n) {return false; } else {ans |= f(i + 1, j + 1);}
        }
        else if (p[j] == '*') {

            if (i < n) {ans |= f(i + 1, j); } ans |= f(i, j + 1);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string _s, string _p) {

        this->s = _s;
        this->p = _p;
        this->n = _s.size();
        this->m = _p.size();
        dp.resize(n+1, vector<int>(m+1, -1));

        return f(0, 0);
    }

};


int main()
{


    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    string s, p; cin >> s >> p;
    Solution ob;

    // cout << "s";
    cout << ob.isMatch(s, p)<<endl;

    return 0;
}