#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
}

void djikstra(vector<vector<pii>> &adj, vector<int> &dist, int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty())
    {
        // int w = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        for(auto it : adj[u])
        {
            int wt = it.first;
            int v = it.second;

            if(dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
}


int main()
{
    init_code();

    int n,m;
    cin>>n>>m;

    vector<vector<pii>> adj(n+1);
    vector<int> dist(n+1, INT_MAX);

    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }

    int s; cin>>s;

    djikstra(adj, dist, s);

    for(int i=1; i<=n; i++)
    {
        if(dist[i] == INT_MAX) cout<<-1<<" ";
        else cout<<dist[i]<<" ";
    }


}