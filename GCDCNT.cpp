#include<bits/stdc++.h>
using namespace std;

const int MAXN = 50000;
const int MAXA = 100000;

int N, Q;
int A[MAXN + 1];
vector<int> tree[4 * MAXN];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = {A[start]};
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node]=(tree[2 * node].begin(), tree[2 * node].end())+ (tree[2 * node + 1].begin(), tree[2 * node + 1].end());
              
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        tree[node] = {val};
    }
    else
    {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node].clear();
        tree[node]=(tree[2 * node].begin(), tree[2 * node].end())+(tree[2 * node + 1].begin(), tree[2 * node + 1].end());
              
    }
}

int query(int node, int start, int end, int L, int R, int G)
{
    if (start > R || end < L)
        return 0;
    if (start >= L && end <= R)
    {
        return (tree[node].begin(), tree[node].end(), [G](int x)
                        { return __gcd(G, x) == 1; });
    }
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, L, R, G) + query(2 * node + 1, mid + 1, end, L, R, G);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    build(1, 1, N);

    cin >> Q;
    while (Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int X, Y;
            cin >> X >> Y;
            update(1, 1, N, X, Y);
        }
        else if (type == 2)
        {
            int L, R, G;
            cin >> L >> R >> G;
            cout << query(1, 1, N, L, R, G) << '\n';
        }
    }

    return 0;
}
