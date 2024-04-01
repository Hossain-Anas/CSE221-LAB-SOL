#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void kahns_algo(vector<vector<int>> &adj, vector<int> &dependencies, vector<int> &topo)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=1; i<dependencies.size(); i++)
    {
        if(dependencies[i]==0)
        {
            pq.push(i);
        }
    }

    while(!pq.empty())
    {
        int v = pq.top();
        pq.pop();

        topo.push_back(v);

        for(int u: adj[v])
        {
            dependencies[u]--;
            if(dependencies[u] == 0)
            {
                pq.push(u);
            }
        }
    }
}



int main()
{
    init_code();

    int n,m;
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

    if(topo.size() != n) cout<<"IMPOSSIBLE";

    else
    {
        for(int i: topo)
        {
            cout<<i<<" ";
        }
    }

}