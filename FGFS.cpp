#include <bits/stdc++.h>
using namespace std;

struct Customer
{
    int s, e, p;
    Customer(int a, int b, int c) { s = a, e = b, p = c; }
    Customer();
};

bool cmp(Customer A, Customer B)
{
    if (A.p != B.p)
        return A.p < B.p;
    return A.e < B.e;
}

int main()
{
    int T, N, K;
    int s, f, p, i, j, ans;
    vector<Customer> V;

    scanf("%d", &T);

    while (T--)
    {
        scanf("%d %d", &N, &K);

        V.clear();
        for (i = 0; i < N; i++)
        {
            scanf("%d %d %d", &s, &f, &p);
            V.push_back(Customer(s, f, p));
        }

        sort(begin(V), end(V), cmp);
        j = 0;
        ans = N > 0;
        for (i = 0; i < N; i++)
        {
            if (V[i].p != V[j].p)
            {
                j = i, ans++;
                continue;
            }
            if (V[i].s >= V[j].e)
            {
                j = i, ans++;
                continue;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}