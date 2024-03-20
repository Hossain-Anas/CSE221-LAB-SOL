#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input4.txt", "r", stdin);
        freopen("output4.txt", "w", stdout);
    #endif
}



// bool undirected_cycle(vector<vector<int>> &adj, int u, vector<bool> &visited, int p=-1)
// {
//     bool cycle = false;

//     visited[u] = true;

//     for(int v: adj[u])
//     {
//         if(v==p) continue;

//         if(visited[v]) return true;

//         cycle = cycle || undirected_cycle(adj, v, visited, u);
//     }

//     return cycle;
// }



bool directed_cycleCheck(vector<vector<int>> adj, int u, vector<bool> &visited, vector<bool> &path)
{
    visited[u] = true;
    path[u] = true;

    bool cycle = false;

    for(int v : adj[u])
    {
        if(visited[v] && path[v])
        {
            return true;
        }

        else
        {
            cycle |= directed_cycleCheck(adj, v, visited, path);
        }
    }

    path[u] = false;
    return cycle;
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
        // adj[v].push_back(u);
    }

    vector<bool> path(m+1, false);

    int flag = 0;

    for(int i=1; i<=m; i++)
    {
        if(visited[i]) continue;

        if(directed_cycleCheck(adj, i, visited, path))
        {
            flag = 1;
            break;
        }
    }

    if(flag) cout<<"YES";
    else cout<<"NO";

}