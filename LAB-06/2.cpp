#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
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

        for(pii it: adj[u])
        {
            int v = it.second;
            int v_w = it.first;

            if(dist[v] > dist[u] + v_w)
            {
                dist[v] = dist[u] + v_w;
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
    vector<int> dist1(n+1, INT_MAX);
    vector<int> dist2(n+1, INT_MAX);

    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }

    int s1, s2;
    cin>>s1>>s2;

    djikstra(adj, dist1, s1);
    djikstra(adj, dist2, s2);

    int node = -1;
    int time = INT_MAX;

    for(int i=1; i<=n; i++)
    {
        if(dist1[i] != INT_MAX && dist2[i] != INT_MAX)
        {
            int temp = max(dist1[i], dist2[i]);
            {
                if(temp < time)
                {
                    node = i;
                    time = temp;
                }
            }
        }
    }

    if(node == -1) cout<<"IMPOSSIBLE";

    else
    {
        cout<<"Time "<<time<<endl;
        cout<<"Node "<<node<<endl;
    }

    return 0;
}




