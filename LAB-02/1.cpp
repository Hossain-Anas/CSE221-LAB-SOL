#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
}

int n, key;
vector<int> arr;

void naive_twosum()
{
    int x,y;
    int flag = 0;

    for(int i= 0; i<n-1; i++)
    {
        if (flag==1) break;

        for(int j= i+1; j<n; j++)
        {
            if(arr[i]+arr[j]==key)
            {
                x = i;
                y = j;
                flag = 1;
                break;
            }
        }
    }

    if(flag==0) cout<<"IMPOSSIBLE"<<endl;
    else cout<<x+1<<" "<<y+1<<endl;
}


void two_sum()
{
    int lp=0, rp = n-1;

    for (int i = 0; i < n; i++)
    {
        if(lp==rp)
        {
            cout<<"IMPOSSIBLE"<<endl;
            break;
        }

        int sum = arr[lp] + arr[rp];

        if(sum == key)
        {
            cout<<lp+1<<" "<<rp+1<<endl;
            break;
        }

        else if(sum>key)
        {
            rp--;
        }

        else if(sum<key)
        {
            lp++;
        }
    }
}



int main()
{
    init_code();

    cin>>n>>key;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    naive_twosum();
    two_sum();

    // for(auto i: arr) cout<<i<<" ";


    return 0;
}