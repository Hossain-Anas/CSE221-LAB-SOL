#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
}

void bubblesort(vector<int> &v, int n)
{
    int flag = 0;

    for(int i=0; i<n-1; i++)
    {   
        // cout<<i<<endl;

        for(int j=0; j<n-i-1; j++)
        {
            if(v[j]>v[j+1])
            {   
                swap(v[j], v[j+1]);
                flag = 1;
            }
        }

        if(flag==0)
        {
            // cout<<"O(N)";
            break;
        }
    }
}

//if there's no swap after one pass in the inner loop that means the list/array is already sorted. this is why I used a flag
//to check whether there's a swap or not. if there's no swap I terminated the sorting mechanism. By this adaptive mechanism We can achieve 
//O(n) time complexity in the best case.

int main()
{
    init_code();

    vector<int> v;

    int t;
    cin>>t;

    for(int i = 0; i<t; i++)
    {
        int x;
        cin>>x;

        v.push_back(x);
    }

    bubblesort(v, t);

    for(auto i:v) cout<<i<<" ";

    return 0;
}
