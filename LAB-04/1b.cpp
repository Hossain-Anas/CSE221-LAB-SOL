#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input1b.txt", "r", stdin);
        freopen("output1b.txt", "w", stdout);
    #endif
}


int main()
{
    init_code();

    int m,n;

    cin>>m>>n;

    vector<vector<pair<int, int>>> adj(m+1);

    for(int i=0; i<n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    for(int i=0; i<=m; i++)
    {
        cout<<i<<" : ";
        for(auto j: adj[i])
        {
            cout<<"("<<j.first<<", "<<j.second<<") ";
        }
        cout<<endl;
    }

    return 0;
}