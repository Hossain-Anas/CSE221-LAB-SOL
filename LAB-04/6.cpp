#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input6.txt", "r", stdin);
        freopen("output6.txt", "w", stdout);
    #endif
}

vector<pair<int, int>> possible_path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int diamond_count = INT_MIN;

bool isValid(int i, int j, int row, int column)
{
    return (i >= 0 && i<row && j >= 0 && j<column);
}

void bfs(vector<vector<char>> adj, int row, int column, int si, int sj, vector<vector<bool>> visited)
{
    queue<pair<int, int>> q;
    q.push({si,sj});
    visited[si][sj] = true;

    int d_count = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if(adj[p.first][p.second] == 'D') d_count++;

        for(int i=0; i<4; i++)
        {
            int adj_i = possible_path[i].first + p.first;
            int adj_j = possible_path[i].second + p.second;

            if(isValid(adj_i, adj_j, row, column) && adj[adj_i][adj_j] != '#' &&  !visited[adj_i][adj_j])
            {
                visited[adj_i][adj_j] = true;
                q.push({adj_i, adj_j});
            }
        }
    }

    if(d_count > diamond_count) diamond_count = d_count;
}


int main()
{
    init_code();
    int m,n;
    cin>>m>>n;

    vector<vector<char>> adj(m, vector<char>(n, '.'));

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            char x;
            cin>>x;
            adj[i][j] = x;
        }
    }


    // for(int i=0; i<m; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j] && adj[i][j] != '#')
            {
                bfs(adj, m, n, i, j, visited);
            }
        }
    }

    cout<<diamond_count;

    return 0;
}