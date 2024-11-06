#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
#define ll long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    priority_queue<int> mou_queue;  // Max heap for mou
    multiset<int> tomu_set;         // Min sorted set for tomu

    int mou = 0, tomu = 0;

    // Read input and assign to mou and tomu
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) {
            mou += x;         // Add to mou's total
            mou_queue.push(x); // Track elements of mou
        } else {
            tomu += x;        // Add to tomu's total
            tomu_set.insert(x); // Track elements of tomu
        }
    }

    // If no swaps are allowed (k == 0)
    if (k == 0) {
        if (tomu > mou) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    // Swapping logic (attempt to swap `k` times)
    while (k-- && !mou_queue.empty() && !tomu_set.empty()) {
        auto max_mou = mou_queue.top(); // Largest element of mou
        auto min_tomu = *tomu_set.begin(); // Smallest element of tomu

        // If swapping doesn't benefit, stop early
        if (max_mou <= min_tomu) break;

        // Swap elements
        mou_queue.pop();             // Remove max from mou queue
        tomu_set.erase(tomu_set.begin()); // Remove min from tomu set

        // Adjust totals
        mou = mou - max_mou + min_tomu;
        tomu = tomu - min_tomu + max_mou;

        // Reinsert the swapped elements
        mou_queue.push(min_tomu);
        tomu_set.insert(max_mou);
    }

    // After possible swaps, check if tomu > mou
    if (tomu > mou) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
