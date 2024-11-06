#include <iostream>
#include <algorithm>

using namespace std;

int n, min_ka, min_kb, tn;
string s;

int main(int argc, const char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin >> tn;
    while (tn--)
    {
        cin >> n;
        int min_ka = 1000000000;
        int min_kb = 1000000000;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            int ka = 0, kb = 0;
            for (int j = 0; j < s.length(); j++)
                if (s[j] == 'a')
                    ++ka;
                else
                    ++kb;
            min_ka = min(min_ka, ka);
            min_kb = min(min_kb, kb);
        }
        cout << min(min_ka, min_kb) << endl;
    }
    return 0;
}