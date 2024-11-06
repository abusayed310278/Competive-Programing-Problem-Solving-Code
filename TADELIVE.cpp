#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, X, Y;
    cin >> n >> X >> Y;

    vector<int> A(n), B(n), D(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
        D[i] = abs(A[i] - B[i]);
    }

    // Create an array of indices to sort by D[i] in decreasing order
    vector<int> indices(n);
    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }

    for (auto x : indices)
        cout << x << " ";
    cout << "\n";

    sort(indices.begin(), indices.end(), [&](int i, int j)
         { return D[i] > D[j]; });

    for (auto x : indices)
        cout << x << " ";

    int andyOrders = 0, bobOrders = 0;
    int totalTipMoney = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = indices[i];
        if (A[idx] > B[idx])
        {
            if (andyOrders + 1 <= X)
            {
                andyOrders++;
                totalTipMoney += A[idx];
            }
            else
            {
                bobOrders++;
                totalTipMoney += B[idx];
            }
        }
        else
        {
            if (bobOrders + 1 <= Y)
            {
                bobOrders++;
                totalTipMoney += B[idx];
            }
            else
            {
                andyOrders++;
                totalTipMoney += A[idx];
            }
        }
    }

    // cout << totalTipMoney << endl;

    return 0;
}
