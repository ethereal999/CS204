#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
typedef long long int lli;
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5005;
lli parent[N];
lli size[N];
lli n, m, k,x,y;
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

 int main(){cin >> n >> m;
    cin >> k;
    vector<pair<lli, lli>> mat[2];
    for(int i=0;i<k;i++)
    {
        cin >> x >> y;
        mat[0].push_back({x, y});
        mat[1].push_back({y, x});
        make(index(x, y));
    }
    sort(mat[0].begin(),mat[0].end());
    sort(mat[1].begin(),mat[1].end());
    for (int i = 0; i < k - 1; i++)
    {
        if ((mat[0][i].F == mat[0][i + 1].F && mat[0][i + 1].S == mat[0][i].S + 1 )||(mat[0][i].F == mat[0][i + 1].F + 1 && mat[0][i + 1].S == mat[0][i].S))
            union_set(index(mat[0][i].F, mat[0][i].S), index(mat[0][i + 1].F, mat[0][i + 1].S));
    }
    for (int i = 0; i < k - 1; i++)
    {
        if ((mat[1][i].F == mat[1][i + 1].F && mat[1][i + 1].S == mat[1][i].S + 1 )|| (mat[1][i].F == mat[1][i + 1].F + 1 && mat[1][i + 1].S == mat[1][i].S))
            union_set(index(mat[1][i].S, mat[1][i].F), index(mat[1][i + 1].S, mat[1][i + 1].F));
    }
     lli maxx = -1;
    for(int i=0;i<k;i++)
    {
        lli x = find(index(mat[0][i].F, mat[0][i].S));
        
        if (size[x] > maxx)
            maxx = size[x];
    }
    cout<<maxx;
    return 0;
}
