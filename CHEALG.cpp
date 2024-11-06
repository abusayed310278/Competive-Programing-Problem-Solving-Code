#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int c = 1;
        int s = 0;
        string temp = "";
        for (int i = 0; i < str.size() - 1; i++)
        {
            if (str[i] == str[i + 1])
                c++;
            else
            {
                temp = to_string(c);

                s = s + temp.size();
                s++;
                c = 1;
            }
        }
        temp = to_string(c);
        s = s + temp.size();
        s++;
        if (s < str.size())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    // your code goes here
    return 0;
}