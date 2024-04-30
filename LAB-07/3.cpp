#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif
}

vector<long long int> ways;


long long int jumps(int i)
{
    if(i == 0 || i == 1) return 1;

    if(i == 2) return 2;

    if(ways[i] != -1) return ways[i];

    long long int way1 = jumps(i-1);
    long long int way2 = jumps(i-2);

    ways[i] = way1 + way2;

    return ways[i];
}



int main()
{
    init_code();
    int n;
    cin>>n;

    ways.resize(n+1, -1);

    long long int res = jumps(n);
    cout<<res;
}

