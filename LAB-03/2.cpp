#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif
}

int find_max(vector<int> &arr, int l, int r)
{
    if (l==r)
    {
        return arr[l];
    }

    int mid = (l+r)/2;
    int left = find_max(arr, l, mid);
    int right = find_max(arr, mid+1, r);
    return max(left, right);
}

//O(logN)


int main()
{
    init_code();

    int n;
    cin>>n;

    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int res = find_max(arr, 0, n-1);
    
    cout<<res;

    return 0;
}


