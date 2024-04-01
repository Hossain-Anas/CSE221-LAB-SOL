#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int n,m;
int visit_count = 0;

void kahns_algo(vector<vector<int>> &adj, vector<int> &dependencies, vector<int> &topo)
{
    queue<int> q;

    for(int i=1; i<dependencies.size(); i++)
    {
        if(dependencies[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        topo.push_back(v); 
        visit_count++;

        for(int u: adj[v])
        {
            dependencies[u]--;
            if(dependencies[u] == 0)
            {
                q.push(u);
            }
        }
    }
}



int main()
{
    init_code();

    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, false);
    vector<int> dependencies(n+1);

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        dependencies[v]++;
    }

    vector<int> topo;

    kahns_algo(adj, dependencies, topo);

    if(visit_count != n) cout<<"IMPOSSIBLE";

    else
    {
        for(int i: topo)
        {
            cout<<i<<" ";
        }
    }

}