#include<bits/stdc++.h>
using namespace std;

int cmp(pair<int, int>&p1, pair<int, int>&p2) {

    if(p1.first==p2.first){
        return p1.second < p2.second;
    }

    return p1.second > p2.second;
}

int main() {

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    int n; cin >> n;
    vector<pair<int, int>>v;
    while (n--) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);
    n = v.size();
    for (int i = 0; i < n; i++) {

        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}