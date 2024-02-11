#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
}


int m, n;
vector<int> res1;
vector<int> res2;
vector<int> m_arr;
vector<int> n_arr;

void merge()
{
    int max = INT_MAX;
    m_arr.push_back(max);
    n_arr.push_back(max);
    int mp = 0, np = 0;

    int r = m+n;

    for(int i=0; i<r; i++)
    {
        if(m_arr[mp]<n_arr[np])
        {
            res2.push_back(m_arr[mp]);
            mp++;
        }

        else
        {
            res2.push_back(n_arr[np]);
            np++;
        }
    }
}

void built_in_sort()
{
    for (int i = 0; i < m; i++)
    {
        res1.push_back(m_arr[i]);
    }

    for(int i = 0; i<n; i++)
    {
        res1.push_back(n_arr[i]);
    }

    sort(res1.begin(), res1.end());
}




int main()
{
    init_code();

    cin>>m;

    for(int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        m_arr.push_back(x);
    }

    cin>>n;

    for(int i = 0; i<n; i++)
    {
        int x;
        cin>>x;
        n_arr.push_back(x);
    }

    // for(auto i: m_arr) cout<<i<<" ";
    // cout<<"\n";
    // for(auto i: n_arr) cout<<i<<" ";

    built_in_sort(); //for O(Nlogn);
    merge(); //for O(N)

    for(auto i: res1) cout<<i<<" ";
    cout<<"\n";
    for(auto i : res2) cout<<i<<" ";

    return 0;
}