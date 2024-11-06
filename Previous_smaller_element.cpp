#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

void findPreviousSmallerElements(const vector<int> &arr)
{
    stack<int> s;
    for (int num : arr)
    {
        while (!s.empty() && s.top() >= num)
        {
            s.pop();
        }
        if (s.empty())
            cout << "-1 ";
        else
            cout << s.top() << " ";
        s.push(num);
    }
    cout << endl;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        findPreviousSmallerElements(arr);
    }
    return 0;
}