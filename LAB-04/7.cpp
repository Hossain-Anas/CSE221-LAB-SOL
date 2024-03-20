#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input7.txt", "r", stdin);
        freopen("output7.txt", "w", stdout);
    #endif
}

void dfs(vector<vector<int>> &adj, vector<int> &depth, int s, int parent = -1)
{
    for(int u : adj[s])
    {
        if(u != parent)
        {
            depth[u] = depth[s] + 1;
            dfs(adj, depth, u, s);
        }
    }
}

int main()
{
    init_code();

    int m, n;
    cin>>m;
    n = m-1;

    vector<vector<int>> adj(m+1);

    for(int i=0; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(m+1, 0);

    dfs(adj, depth, 1);

    int max_depth = INT_MIN;
    int one_end = -1;

    for(int i = 1; i<=m; i++)
    {
        if(depth[i] > max_depth)
        {
            max_depth = depth[i];
            one_end = i;
        }
    }

    depth.assign(m+1 , 0);
    dfs(adj, depth, one_end);

    max_depth = INT_MIN;
    int another_end = -1;

    for(int i = 1; i<=m; i++)
    {
        if(depth[i]>max_depth)
        {
            max_depth = depth[i];
            another_end = i;
        }
    }

    cout<<one_end<<" "<<another_end<<endl;

    return 0;
}