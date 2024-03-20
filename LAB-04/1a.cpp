#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input1a.txt", "r", stdin);
        freopen("output1a.txt", "w", stdout);
    #endif
}


int main()
{
    init_code();

    int m,n;

    cin>>m>>n;

    // const int N = 100;
    // int adj[N][N] = {0};

    vector<vector<int>> adj(m+1, vector<int>(m+1,0));

    for(int i=0; i<n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v] = w;
    }


    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    } 

    return 0;
}