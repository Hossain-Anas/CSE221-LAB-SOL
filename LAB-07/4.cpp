#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input4.txt", "r", stdin);
        freopen("output4.txt", "w", stdout);
    #endif
}

int n,x;
vector<int> coins;
vector<int> memo;

int coin_change(int amount)
{
    if(amount == 0) return 0;

    if(memo[amount] != -1) return memo[amount];

    int res = INT_MAX;

    for(int c : coins)
    {

        if(amount - c < 0) continue;

        int temp = coin_change(amount - c);

        if(temp != INT_MAX)
        {
            res = min(res, temp + 1);
        }
        
    }

    memo[amount] = res;
    return res;
}


int main()
{
    init_code();

    cin>>n>>x;
    memo.resize(x+1, -1);

    for(int i = 0; i<n; i++)
    {
        int z;
        cin>>z;
        coins.push_back(z);
    }

    int ans = coin_change(x);

    if(ans == INT_MAX) cout<<-1;
    else cout<<ans;
}
