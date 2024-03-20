#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
}

void bfs(vector<vector<int>> adj, int s, vector<bool> &visited)
{
    queue<int> q;
    q.push(s);

    visited[s] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        for(int v: adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
        }
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

    bfs(adj, 1, visited);

}