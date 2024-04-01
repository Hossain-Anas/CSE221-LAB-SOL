#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif
}

int res = INT_MAX;


void djikstra(vector<vector<pii>> &adj, vector<bool> &visited, int s, int end)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,s});

    while(!pq.empty())
    {
        int w = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if(u == end)
        {
            // res = min(res, w);
            res = w;
            return;
        }

        if(visited[u]) continue;

        visited[u] = true;

        for(auto it: adj[u])
        {
            int v = it.second;
            int v_w = it.first;

            if(visited[v]) continue;

            int pick_w = max(v_w, w);

            pq.push({pick_w, v});
        }
    }
}


int main()
{
    init_code();

    int n,m;
    cin>>n>>m;

    vector<vector<pii>> adj(n+1);
    vector<bool> visited(n+1, false);


    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }

    djikstra(adj, visited, 1, n);

    if(res!=INT_MAX) cout<<res;
    else cout<<"IMPOSSIBLE";

}