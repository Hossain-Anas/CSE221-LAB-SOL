#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input5.txt", "r", stdin);
        freopen("output5.txt", "w", stdout);
    #endif
}

void bfs(vector<vector<int>> adj, int s, vector<bool> &visited, vector<int> &parent, vector<int> &level)
{
    queue<int> q;
    q.push(s);

    visited[s] = true;
    parent[s] = -1;
    level[s] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v: adj[u])
        {
            if(visited[v]) continue;
            level[v] = level[u] +1;
            parent[v] = u;
            visited[v] = true;
            q.push(v);
        }
    }
}


int main()
{
    init_code();
    int m,n,destination;
    cin>>m>>n>>destination;

    vector<vector<int>> adj(m+1);
    vector<bool> visited(m+1, false);

    for(int i=0; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(m+1, 0);
    vector<int> level(m+1, 0);

    bfs(adj, 1, visited, parent, level);

    cout<<"Time : "<<level[destination]<<endl;

    vector<int> path;
    int curr = destination;

    while(curr != -1)
    {
        path.push_back(curr);

        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout<<"Shortest Path: ";

    for(int i: path) cout<<i<<" ";

}