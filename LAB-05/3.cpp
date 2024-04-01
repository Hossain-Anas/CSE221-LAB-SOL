#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, int u)
{
    visited[u] = true;

    for(int v: adj[u])
    {
        if(visited[v]) continue;
        dfs(adj, visited, st, v);
    }

    st.push(u);
}

void scc_count(vector<vector<int>> &adj_rev, vector<vector<int>> &sccs, vector<bool> &visited, int &cnt, int u)
{
    visited[u] = true;
    sccs[cnt].push_back(u);

    for(int v : adj_rev[u])
    {
        if(visited[v]) continue;
        scc_count(adj_rev, sccs, visited, cnt, v);
    }
}



int main()
{
    init_code();

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<vector<int>> adj_rev(n+1);

    vector<bool> visited(n+1, false);
    stack<int> st;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        if(visited[i]) continue;
        dfs(adj, visited, st, i);
    }

    int cnt = 0;
    vector<vector<int>> sccs(n+1);

    visited.assign(n+1, false);

    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(visited[node]) continue;
        scc_count(adj_rev, sccs, visited, cnt, node);
        cnt++;
    }

    for(int i = 0; i<cnt; i++)
    {
        for(int j : sccs[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

}