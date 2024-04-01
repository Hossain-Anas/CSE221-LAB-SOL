#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

bool flag = false;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, int u, vector<bool> &path)
{
    visited[u] = true;
    path[u] = true;

    for(int v: adj[u])
    {
        if(visited[v] && path[v])
        {
            flag = true;
        }

        else if(!visited[v])
        {   
            dfs(adj, visited, st, v, path);
        }
    }

    path[u] = false;

    st.push(u);
}

int main()
{
    init_code();

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, false);
    vector<bool> path(n+1, false);

    stack<int> st;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1; i<=n; i++)
    {
        if(visited[i]) continue;
        dfs(adj, visited, st, i, path);
    }

    if (flag) cout<<"IMPOSSIBLE";

    else
    {
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }

    return 0;    
}