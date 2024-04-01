#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
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
}



int main()
{
    init_code();
    
    cin>>n>>m;

    parent.resize(n+1);
    sz.resize(n+1);

    vector<vector<long long int>> edges;

    for(int i=0; i<m; i++)
    {
        int u,v;
        long long int w;
        cin>>u>>v>>w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    // for(auto it: edges)
    // {
    //     cout<<it[1]<<" "<<it[2]<<" "<<it[0]<<endl;
    // }

    for(int i=1; i<=n; i++)
    {
        make(i);
    }

    long long int cost = 0;

    for(auto it : edges)
    {
        int u = it[1];
        int v = it[2];
        long long int w = it[0];

        if(find(u) == find(v)) continue;

        Union(u,v);

        cost+=w;
    }

    cout<<cost;
}

