#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDDGE
        freopen("input1a.txt", "r", stdin);
        freopen("output1a.txt", "w", stdout);
    #endif
}


int main()
{
    init_code();
    int t;
    cin>>t;

    while(t--)
    {
        int x;
        cin>>x;

        if(x%2==0) cout<<x<<" is an Even number"<<endl;
        else cout<<x<<" is an Odd number"<<endl;    
    }

    return 0;
}