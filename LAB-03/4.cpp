#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input4.txt", "r", stdin);
        freopen("output4.txt", "w", stdout);
    #endif
}


int left_max(vector<int> &arr, int l, int r)
{
    if(l==r)
        return arr[l];
    
    int mid = (l+r)/2;
    int right = left_max(arr, l, mid);
    int left = left_max(arr, mid+1, r);
    return max(left, right);
}

int right_max(vector<int> &arr, int l, int r)
{
    if(l==r)
        return arr[l]*arr[l];
    
    int mid = (l+r)/2;
    int right = right_max(arr, l, mid);
    int left = right_max(arr, mid+1, r);
    return max(left, right);
}


int max_sum(vector<int> &arr, int l, int r)
{
    if(l==r)
        return arr[l];

    int mid = (l+r)/2;
    int left = max_sum(arr, l, mid);
    int right = max_sum(arr, mid+1, r);
    int mid_sum = left_max(arr, l, mid) + right_max(arr, mid+1, r);

    return max(left, max(right,mid_sum));
}


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

    // for(auto i: arr) cout<<i<<" ";

    int res = max_sum(arr, 0, n-1);

    cout<<res;
    return 0;
}