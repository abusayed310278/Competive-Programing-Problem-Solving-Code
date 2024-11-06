#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> minFreq(26, INT_MAX);

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        vector<int> freq(26, 0);
        for (char c : str)
        {
            freq[c - 'a']++;
        }

        for (int j = 0; j < 26; ++j)
        {
            minFreq[j] = min(minFreq[j], freq[j]);
        }
    }

    string res = "";
    for (int i = 0; i < 26; ++i)
    {
        if (minFreq[i] > 0)
        {
            res += string(minFreq[i], 'a' + i);
        }
    }

    if (res.empty())
    {
        cout << "no such string" << endl;
    }
    else
    {
        cout << res << endl;
    }

    return 0;
}
