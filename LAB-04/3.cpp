#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif
}


void dfs(vector<vector<int>> adj, int u, vector<bool> &visited)
{
    visited[u] = true;

    cout<<u<<" ";

    for(int v : adj[u])
    {
        if(visited[v]) continue;
        dfs(adj, v, visited);
    }
}



int main()
{
    init_code();
    int m,n;
    cin>>m>>n;

    vector<vector<int>> adj(m+1);
    vector<bool> visited(m+1, false);

    for(int i=0; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(adj, 1, visited);

}