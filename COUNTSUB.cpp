#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        unordered_map<int, int> freq;
        long long ans = n * (n + 1) / 2;
        
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
            ans -= freq[a[i]];
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
