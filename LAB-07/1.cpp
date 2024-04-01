#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
}

int n,m;
vector<int> parent;
vector<int> sz;

void make(int u)
{
    parent[u] = u;
    sz[u] = 1;
}

int find(int u)
{
    if(parent[u] == u) return u;

    return parent[u] = find(parent[u]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a != b)
    {
        if(sz[b] > sz[a])
        {
            swap(a,b);
        }

        parent[b] = a;
        sz[a] += sz[b];

    }

    cout<<sz[a]<<endl;
}




int main()
{
    init_code();

    
    cin>>n>>m;
    parent.resize(n+1);
    sz.resize(n+1);

    vector<pii> edges;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    for(int i=1; i<=n; i++)
    {
        make(i);
    }

    for(pii it : edges)
    {
        int u = it.first;
        int v = it.second;

        // if(find(u) == find(v)) continue;
        
        Union(u,v);
    }

}