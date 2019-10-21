#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
const int N = 1e6 + 5005;
lli parent[N];
lli size[N];
lli n, m, c;
void make(lli v)
{
    parent[v] = v;
    size[v] = 1;
}
lli find(lli v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void union_set(lli a, lli b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
lli index(lli x, lli y)
{
    return x * m + y;
}
int main()
{

    cin >> n >> m >> c;
    lli a[n + 2][m + 2];
    memset(a, -1, sizeof(a));
    for(lli i=1;i<=n;i++){
    for(lli j=1;j<=m;j++)
    {
        cin >> a[i][j];
        make(index(i, j));
    }
    }
    for(lli i=1;i<=n;i++)
    {
            for(lli j=1;j<=m;j++)
            {
            if (a[i][j] == a[i - 1][j])
                union_set(index(i, j), index(i - 1, j));
        }
    }
   for(lli i=1;i<=n;i++)
    {
            for(lli j=1;j<=m;j++)

        {
            if (a[i][j - 1] == a[i][j])
                union_set(index(i, j - 1), index(i, j));
        }
    }
    lli maxx = -1,clr =-1;
    for(lli i=1;i<=n;i++)
    {
        for(lli j=1;j<=m;j++)
        {
            lli x = find(index(i, j));
            if (size[x] > maxx)
            {
                maxx = size[x];
                clr = a[i][j];

            }
        }
    }
   cout<<maxx<<" "<<clr<<endl;
    return 0;
}



