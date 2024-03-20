#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input8.txt", "r", stdin);
        freopen("output8.txt", "w", stdout);
    #endif
}


void bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &color, int s, int &black_0, int &white_1)
{
    queue<int> q;
    q.push(s);

    visited[s] = true;
    color[s] = 0;
    black_0++;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(int v : adj[front])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            
            if(color[front] == 0)
            {
                color[v] = 1;
                white_1++;
            }

            else if(color[front] == 1)
            {
                color[v] = 0;
                black_0++;
            }
        }
    }

}


int main()
{
    init_code();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int i=1; i<=t; i++)
    {
        int sz = 20005;

        vector<vector<int>> adj(sz);
        vector<bool> visited(sz, false);
        vector<int> color(sz, -1);

        int m;
        cin>>m;

        for(int j=0; j<m; j++)
        {
            int u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int black_0 = 0;
        int white_1 = 0;

        for(int k = 1; k < sz; k++)
        {
            if(visited[k]) continue;
            if(adj[k].empty()) continue;
            bfs(adj, visited, color, k, black_0, white_1);
        }

        int res = max(black_0, white_1);

        cout<<"Case "<<i<<": "<<res<<endl;
    }

    return 0;
}